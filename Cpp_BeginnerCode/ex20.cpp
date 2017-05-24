#include <iostream>


int main()
{
    char str[] = "Unable to read ...";

    std::cerr << "Error message : " << str << std::endl;
    std::clog << "Error message : " << str << std::endl;
}
