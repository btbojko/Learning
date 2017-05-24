#include <iostream>

//function declaration
int max(int, int);

int main()
{
    // local variable declaration
    int a = 100;
    int b = 200;
    int ret;

    // calling a function to get max value
    ret = max(a, b);

    std::cout << "Max value is : " << ret << std::endl;

    return 0;
}

//function returning the max between two numbers
int max(int num1, int num2)
{
    //local variable declaration
    int result;

    if(num1 > num2)
        result = num1;
    else 
        result = num2;

    return result;
}
