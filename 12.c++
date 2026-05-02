#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
    public:
    double volume(double side) {
        return side * side * side;
    }

    double volume(float radius, char type) {
        return (4.0/3.0) * 3.14159 * pow(radius, 3);
    }
    
    double volume(double l, double w, double h) {
        return l * w * h;
    }
};

int main() {
    Calculator calc;
    
    cout << "Cube: " << calc.volume(3) << endl;
    cout << "Coboid: " << calc.volume(2, 4, 5) << endl;
    cout << "Sphere: " << calc.volume(3.0f, 's') << endl;

    return 0;
}