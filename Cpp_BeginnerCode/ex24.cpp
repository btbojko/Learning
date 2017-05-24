#include <iostream>

using namespace std;

class Box {
    public:
        double length;    // length of a box
        double breadth;   // breadth of a box
        double height;    // height of a box
           
        // Member functions declaration
        double getVolume(void);
        void setLength(double);
        void setBreadth(double);
        void setHeight(double);
};

// Member function definitions
double Box::getVolume(void){
    return length * breadth * height;
}

void Box::setLength(double len){
    length = len;
}

void Box::setBreadth(double bre){
    breadth = bre;
}

void Box::setHeight(double hei){
    height = hei;
}

// Main function for program
int main()
{
    Box box1;        // declare box1 of type Box
    Box box2;        // declare box2 of type Box
    double volume = 0.; // Store the volume of a box here

    // box 1 specification
    box1.setHeight(5.0);
    box1.setLength(6.0);
    box1.setBreadth(7.0);

    // box 1 specification
    box2.setHeight(10.0);
    box2.setLength(12.0);
    box2.setBreadth(13.0);

    // volume of box 1
    volume = box1.getVolume();
    cout << "Volume of box1 : " << volume << endl;

    // volume of box 1
    volume = box2.getVolume();
    cout << "Volume of box2 : " << volume << endl;

    return 0;
}
