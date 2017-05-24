#include <iostream>
using namespace std;

class Box {
    public:
   
        double getVolume(void){
            return length * breadth * height;
        }

        double setLength(double len){
            length = len;
        }

        double setBreadth(double bre){
            breadth = bre;
        }
       
        double setHeight(double hei){
            height = hei;
        }

        // Overload + operator to add two Box objects
        Box operator+(const Box& b){
            Box box;
            box.length = this -> length + b.length;
            box.breadth = this -> breadth + b.breadth;
            box.height = this -> height + b.height;
            return box;
        }

    private:
        double length;    // length of box
        double breadth;   // breadth of box
        double height;    // height of box
};

// main function for the program
int main() 
{
    Box box1;        // declare box1 of type Box
    Box box2;        // declare box1 of type Box
    Box box3;        // declare box1 of type Box
    double volume = 0.0; // store the volume of a box here

    // box 1 specification
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    
    // box 1 specification
    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);

    // volume of box 1 
    volume = box1.getVolume();
    cout << "Volume of box1 : " << volume << endl;

    // volume of box 2
    volume = box2.getVolume();
    cout << "Volume of box2 : " << volume << endl;

    // add two objects as follows
    box3 = box1 + box2;

    // volume of box3
    volume = box3.getVolume();
    cout << "Volume of box3 : " << volume << endl;

    return 0;
}
