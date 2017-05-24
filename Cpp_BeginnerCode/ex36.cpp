#include <iostream>

using namespace std;

// Base class
class Shape {
    public:
        // pure virtual function providing interface framework
        virtual int getArea() = 0;

        void setWidth(int w){
            width = w;
        }       

        void setHeight(int h){
            height = h;
        }

    protected:
        int width;
        int height;
};

// derived class
class Rectangle : public Shape {
    public:
        int getArea() {
            return width*height;
        }
};

class Triangle : public Shape {
    public:
         int getArea() {
             return 0.5*width*height;
         }
};

// main function for program
int main()
{
    Rectangle Rect;
    Triangle  Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);
    // Print the area of the object
    cout << "Total Rectangular area : " << Rect.getArea() << endl;
    
    Tri.setWidth(5);
    Tri.setHeight(7);
    // Print the area of the object
    cout << "Total Triangle area : " << Tri.getArea() << endl;

    return 0;
}

