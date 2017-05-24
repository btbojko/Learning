#include <iostream>

using namespace std;

class Box {
    public:
        // constructor definition
        Box(double l = 2.0, double b = 2.0, double h = 2.0){
            cout << "Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
        }

        double Volume(){
            return length * breadth * height;
        }

        int compare (Box box){
            return this -> Volume() > box.Volume();
        }

    private:
        double length;    // Length of a box
        double breadth;   // breadht of a box
        double height;    // height of a box
};

// main function for the program
int main() 
{
    Box box1(3.3, 1.2, 1.5);  // declare box1
    Box box2(8.5, 6.0, 2.0);  // declare box2
    Box box3(2.);               // declare box3 with default values

    if(box1.compare(box2)){
        cout << "Box 2 is smaller than Box 1" << endl;
    } else {
        cout << "Box 2 is equal to or larger than Box 1" << endl;
    }

    cout << "Volume of default box : " << box3.Volume() << endl;

    return 0;
}
