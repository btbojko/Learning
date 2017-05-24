#include <iostream>

using namespace std;

inline int Max(int x, int y){
    return (x > y) ? x : y;
}

// main function for the program
int main()
{
    cout << "Max (20, 10) : " << Max(20,10) << endl;
    cout << "Max (0, 200) : " << Max(0,200) << endl;
    cout << "Max (1010, 100) : " << Max(1010,100) << endl;
    cout << "Max (-10, 310) : " << Max(310,-10) << endl;

    return 0;
}
