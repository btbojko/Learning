#include <iostream>

using namespace std;

class Box {
    public:
        double length;    // length of a box
        double breadth;   // breadth of a box
        double height;    // height of a box
};

int main()
{
    Box box1;        // declare box1 of type Box
    Box box2;        // declare box2 of type Box
    double volume = 0.; // Store the volume of a box here

    // box 1 specification
    box1.height  = 5.0;
    box1.length  = 6.0;
    box1.breadth = 7.0;

    // box 1 specification
    box2.height  = 10.0;
    box2.length  = 12.0;
    box2.breadth = 13.0;

    // volume of box 1
    volume = box1.height * box1.length * box1.breadth;
    cout << "Volume of box1 : " << volume << endl;

    // volume of box 1
    volume = box2.height * box2.length * box2.breadth;
    cout << "Volume of box2 : " << volume << endl;

    return 0;
}
