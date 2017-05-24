#include <iostream>

int main()
{
    char greetings[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    std::cout << "Greeting message: ";
    std::cout << greetings << std::endl;

    return 0;
}
