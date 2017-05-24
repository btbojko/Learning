#include <iostream>
using namespace std;

class Box {
    private:
        double length;
        double height;
   
     protected:
        double width;
     
     public:
        void setLength(double);
        void setHeight(double);
        void setWidth(double);
        double getVolume(void);
};

//define the member functions for Box
void Box::setLength(double len){
    length = len;
}

void Box::setHeight(double hei){
    height = hei;
}

void Box::setWidth(double wid){
    width = wid;
}

double Box::getVolume(void){
    return height * length *width;
}

class smallBox : public Box { //smallBox is a derived class
    public:
        void setSmallWidth(double);
        double getSmallWidth(void);
};

// Member functions for smallBox
void smallBox::setSmallWidth(double wid){
    width = wid;
}

double smallBox::getSmallWidth(void){
    return width;
}

// Main function for the program
int main()
{
    smallBox box;

    // set box using the member functions
    box.setHeight(10.);
    box.setLength(20.);
    box.setWidth(50.);

    // get the volume of this box
    cout << "Width of the box : " << box.getSmallWidth() << endl;
    cout << "Volume of the box : " << box.getVolume() << endl;

    // set the width much smaller
    box.setSmallWidth(2.0);
    
    cout << "Now reduce the size of the box by specifying the " << endl;
    cout << "width of the small box. " << endl;
    // get volume for the small box
    cout << "Width of the box : " << box.getSmallWidth() << endl;
    cout << "Volume of the box : " << box.getVolume() << endl;

    return 0;
}
