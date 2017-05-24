#include <iostream>

class Box {
    double width;
  
    public:
        friend void printWidth(Box box);
        void setWidth(double);
};

// Member function definitions
void Box::setWidth(double wid){
    width = wid;
}

// Note: printWidth() is not a member function of any class
void printWidth(Box box){
    /* Because printWidth() is a friend of Box, it can directly
     * access any member of this class */
    std::cout << "Width of box : " << box.width << std::endl;
}

// Main functioni for the program 
int main()
{
    Box box;

    // set box width with member funtion 
    box.setWidth(10.0);

    // use friend funtion to print the width 
    printWidth(box);

    return 0;
}
