#include <iostream>

class Box {
    public: 
        //Constructor definiton
        Box(double l=2.0, double b=2.0, double h=2.0){
            std::cout << "Constructor called." << std::endl;
            length = l;
            breadth = b;
            height = h;
        }

        double Volume() {
            return length * breadth * height;
        }

    private:
        double length;
        double breadth;
        double height;
};

int main()
{
    Box box1(3.3, 1.2, 1.5);    //declare box1
    Box box2(8.5, 6.0, 2.0);    //declare box1
    Box *ptrBox;               //declare pointer to a class

    // save the address of first object
    ptrBox = &box1;

    // now try to access a member using member access operator
    std::cout << "Volume of box1 : " << ptrBox -> Volume() << std::endl;

    // save the address of second object
    ptrBox = &box2;

    // now try to access a member using member access operator
    std::cout << "Volume of box2 : " << ptrBox -> Volume() << std::endl;

    return 0;
}
