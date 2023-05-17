//Main program of the Bank management system

#include <iostream>
#include "Bank.hpp"
#include "Admin.hpp"
#include "Customer.hpp"
#include "User.hpp"

static User* CreateAdmin(Parameters p)
{
    return new Admin(p.GetName(), p.GetPassword(), p.GetBank());
}

static User* CreateCustomer(Parameters p)
{
    return new Customer(p.GetName(), p.GetPassword(), p.GetBank());
}

int main()
{
    Bank b;
    b.AddFactoryMethod("admin", CreateAdmin);
    b.AddFactoryMethod("customer", CreateCustomer);
    int option = 0;

    while (option)
    {
        std::cout << "Welcome to Bank Management system! Choose an option: 1. Create new user ,2. Login ,3. Exit" << std::endl;
        std::cin >> option;
        if (1 == option)
        {
            std::cout << "Enter the following details: -Name, -Password, -Role" << std::endl;
            std::cout << "Name: ";
            std::string name;
            std::string password;
            std::string role;
            
            std::cin >> name;
            std::cout << "\n";
            std::cout << "Password: ";
            std::cin >> password;
            std::cout << "\n";
            std::cout << "Role: ";
            std::cin >> role;
            std::cout << "\n";

            b.AddUser(name, password, role);
        }
        else if (2 == option)
        {
            std::cout << "Please enter name and password" << std::endl;
            std::string name;
            std::string password;
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "\n";
            std::cout << "Password: ";
            std::cin >> password;
            std::cout << "\n";

            User* user = b.Login(name, password);
            if (nullptr == user)
            {
                std::cout << "login failed!" << std::endl;

            }

            else if(Admin* admin = dynamic_cast<Admin*>(user))
            {
                admin->Welcome();
            }
            else
            {
                Customer* cust = dynamic_cast<Customer*>(user);
                cust->Welcome();
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
