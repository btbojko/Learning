#include <iostream>
using namespace std;

class Line{
    public:
        void setLength(double);
        double getLength(void);
        Line(double);    // this is the constructor declaration
        ~Line();         // this is the deconstructor declaration

    private:
        double length;  
};

// Member function defintions including the constructor
Line::Line(double len){
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

Line::~Line(void){
    cout << "Object is being deleted" << endl;
}

void Line::setLength(double len){
    length = len;
}

double Line::getLength(void){
    return length;
}

// Main function for the program
int main(){
    Line line(10.0);

    //get line length
    cout << "Length of line : " << line.getLength() << endl;

    //reset line length
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

    //Line ~line();
    
    return 0;
}
