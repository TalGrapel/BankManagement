#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include <mutex>                    //mutex
#include <atomic>                   //atomic_fence

template <class T>
class Singleton
{
public:
    static T* GetInstance();

private:
    Singleton();
    static T* m_singleton;
    static std::mutex m_mutex;
};

template<class T>
T* Singleton<T>::m_singleton = nullptr;

template<class T>
std::mutex Singleton<T>::m_mutex;

template<class T>
Singleton<T>::Singleton()
{
    //empty on purpose
}

template<class T>
T* Singleton<T>::GetInstance()
{
    T* temp = m_singleton;

    std::atomic_thread_fence(std::memory_order_acquire);

    if (nullptr == temp)
    {
        m_mutex.lock();
        temp = m_singleton;

        if (nullptr == temp)
        {
            temp = new T();

            std::atexit([]() {delete m_singleton; m_singleton = nullptr; });

            std::atomic_thread_fence(std::memory_order_release);

            m_singleton = temp;
        }
        m_mutex.unlock();
    }

    return temp;
}

#endif // __SINGLETON_HPP__
