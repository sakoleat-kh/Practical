#include <iostream>
using namespace std;

class Complex {
    private:
        double real;
        float imag;

    public:
        Complex(float r = 0, float i = 0) {
            real = r;
            imag = i;
            cout << "Constructor called for " << real << " + " << imag << "i" << endl;
        }
    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex multiply(Complex c) {
        float r = (real * c.real) - (imag * c.imag);
        float i = (real * c.imag) + (imag * c.real);
        return Complex(r, i);
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    cout << "\n--- Performing Operations ---\n";

    Complex sum = c1.add(c2);
    cout << "Sum: ";
    sum.display();

    Complex prod = c1.multiply(c2);
    cout << "Product: ";
    prod.display();

    cout << "\n--- End of Operations ---\n";

    return 0;
}