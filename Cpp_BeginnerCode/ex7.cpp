#include <iostream>
#include <cmath>

int main()
{
    // number definition
    short  s = 10;
    int    i = -1000;
    long   l = 100000;
    float  f = 230.47;
    double d = 200.374;

    // mathematical operations
    std::cout << "sin(d) = " << sin(d) << std::endl; 
    std::cout << "abs(i) = " << std::abs(i) << std::endl; 
    std::cout << "floor(d) = " << floor(d) << std::endl; 
    std::cout << "sqrt(f) = " << sqrt(f) << std::endl; 
    std::cout << "pow(d,2) = " << pow(d,2) << std::endl; 

    return 0;
}
