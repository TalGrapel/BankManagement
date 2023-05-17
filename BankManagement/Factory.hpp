#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <map>              //container
#include <stdexcept>        //invalid_argument

#include "singleton.hpp"


// KEY must have a to_string member function that is callable as key.to_string()
//and returns a std::string (or something implcitly convertible to it), and
//comparible using std::less. 
//CREATOR must be a callable object that recieves PARAMS and returns a BASE *. 
template <typename KEY, typename BASE, class PARAMS,
    typename CREATOR = BASE * (*)(PARAMS) >
class Factory
{
public:
    void Add(KEY key, CREATOR func, bool should_replace_key = false);
    BASE* Create(KEY key, PARAMS params) const;
    static Factory<KEY, BASE, PARAMS>* GetInstance();

private:
    std::map<KEY, CREATOR> m_map;
    Factory();
    friend Singleton<Factory>;
};

// Exceptions

template <typename KEY>
class UnkownKey : public std::invalid_argument
{
public:

    UnkownKey(const std::string& what, KEY key);
};

template <typename KEY>
class KeyCannotBeAdded : public std::invalid_argument
{
public:

    KeyCannotBeAdded(const std::string& what, KEY key);
};

template<typename KEY>
UnkownKey<KEY>::UnkownKey(const std::string& what, KEY key) :
    std::invalid_argument(what)
{
    //empty on purpose
}

template<typename KEY>
KeyCannotBeAdded<KEY>::KeyCannotBeAdded(const std::string& what, KEY key) :
    std::invalid_argument(what)
{
    //empty on purpose
}

template <typename KEY, typename BASE, class PARAMS,
    typename CREATOR >
Factory<KEY, BASE, PARAMS, CREATOR>::Factory()
{
}


template<typename KEY, typename BASE, class PARAMS, typename CREATOR>
Factory<KEY, BASE, PARAMS>* Factory<KEY, BASE, PARAMS, CREATOR>::GetInstance()
{
    return Singleton<Factory<KEY, BASE, PARAMS>>::GetInstance();
}

template <typename KEY, typename BASE, class PARAMS,
    typename CREATOR>
void Factory<KEY, BASE, PARAMS, CREATOR>::Add(KEY key, CREATOR func,
    bool should_replace_key)
{
    if (false == should_replace_key && m_map.count(key))
    {
        throw KeyCannotBeAdded<KEY>("key alreay exist", key);
    }

    m_map[key] = func;
}

template<typename KEY, typename BASE, class PARAMS, typename CREATOR>
BASE* Factory<KEY, BASE, PARAMS, CREATOR>::Create(KEY key, PARAMS params) const
{
    if (!m_map.count(key))
    {
        throw UnkownKey<KEY>("Key doesnt exist", key);
    }

    return m_map.at(key)(params);
}


#endif // __FACTORY_HPP__

