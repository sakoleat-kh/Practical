#include <iostream>
using namespace std;

class Box {
    private: 
        double length;
        double breadth;
        double height;

    public: 
        Box(double l, double b, double h) {
            length = l;
            breadth = b;
            height = h;
        }
        Box(double l, double b) {
            length = l;
            breadth = b;
            height = 10;
        }
        double calculateVolume() {
            return length * breadth * height;
        }
        void displayDimensions() {
            cout << "L: " << length << ", B: " << breadth << ", H: " << height << endl;
        }
};

int main() {
    Box b1(5, 4, 3);
    cout << "Box 1 - " ;
    b1.displayDimensions();
    cout << "Volume: " << b1.calculateVolume() << endl << endl;

    Box b2(5, 4);
    cout << "Box 2 (Default Height 10) - ";
    b2.displayDimensions();
    cout << "Volume: " << b2.calculateVolume() << endl << endl;

    return 0;
}