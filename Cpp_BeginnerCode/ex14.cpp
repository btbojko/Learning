#include <iostream>

int main()
{
    int var = 20;    //actual variable declaration
    int *ip;         // pointer variable

    ip = &var;       // store address for var in pointer variable

    std::cout <<  "Value of var variable: ";
    std::cout << var << std::endl;

    // print the address stored in ip pointer variable
    std::cout << "Address stored in ip variable: ";
    std::cout << ip << std::endl;

    // access the value at the addres available in pointer
    std::cout << "Value of *ip variable: ";
    std::cout << *ip << std::endl;

    return 0;
}
