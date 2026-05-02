#include <iostream>
using namespace std;

double power(double m, int n = 2) {
    double result = 1;

    for (int i = 0; i < n; i++) {
        result *= m;
    }
    return result;
}
int main() {
    double m;
    int n;

    cout << "Enter value of m: ";
    cin >> m;

    cout << "Enter value of n (enter 0 to use default square): ";
    cin >> n;

    if(n == 0) {
        cout << "Result (square): " << power(m) << endl;
    
    } else {
        cout << "Result: " << power(m, n) << endl;
    }
    return 0;
}