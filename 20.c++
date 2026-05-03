#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x, degree;
    int terms;

    cout << "Enter the angle in degrees: ";
    cin >> degree;
    cout << "Enter the number of terms: ";
    cin >> terms;

    x = degree * (M_PI / 180.0);

    double sum = x;
    double term = x;

    for (int i = 1; i < terms; i++) {
        term = term * (-1 * x * x) / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    cout << fixed << setprecision(6);
    cout << "\nCalcalated sin(" << degree << ") = " << sum << endl;
    cout << "Actual sin(" << degree << ") = " << sin(x) << endl;

    return 0;
}