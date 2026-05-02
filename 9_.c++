#include <iostream>
using namespace std;

void sortTwoNumbers(int &num1, int &num2) {
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
}

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Before sorting: " << a << " " << b << endl;

    sortTwoNumbers(a, b);
    cout << "After sorting (smallest first):  " << a << ", " << b << endl;
    
    return 0;
}