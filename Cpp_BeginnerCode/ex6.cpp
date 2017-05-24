#include <iostream>

int sum(int a, int b=20)
{
    int result;

    result = a + b;

    return result;
}

int main()
{
    // local variable declaration
    int a = 100;
    int b = 200;
    int result;

    // calling a function to add the values
    result = sum(a,b);
    std::cout << "Total value is : " << result << std::endl;

    // calling a function again as follows
    result = sum(a);
    std::cout << "Total value is : " << result << std::endl;
    
    return 0;
}
