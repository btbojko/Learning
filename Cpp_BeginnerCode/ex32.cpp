#include <iostream>

class Box {
    public: 
        static int objectCount;
        //Constructor definiton
        Box(double l=2.0, double b=2.0, double h=2.0){
            std::cout << "Constructor called." << std::endl;
            length = l;
            breadth = b;
            height = h;
            // increase every time object is created
            objectCount++;
        }

        double Volume() {
            return length * breadth * height;
        }

    private:
        double length;
        double breadth;
        double height;
};

// initialize static member of class Box
int Box::objectCount = 0;

int main()
{
    Box box1(3.3, 1.2, 1.5);    //declare box1
    Box box2(8.5, 6.0, 2.0);    //declare box1

    // Print total number of objects 
    std::cout << "Total objects : " << Box::objectCount << std::endl;

    return 0;
}
