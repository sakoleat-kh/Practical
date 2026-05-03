#include <iostream>
#include <string>

using namespace std;

struct address {
    string plot_no;
    string city;
    string state;
    string pin_name;
};

struct company {
    string name;
    string phone;
    int no_of_employee;
    address addr;
};

int main() {
    const int SIZE = 3;
    company c[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter details for Company " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin >> ws, c[i].name);
        cout << "Phone: ";
        getline(cin, c[i].phone);
        cout << "Number of Employee: ";
        cin >> c[i].no_of_employee;

        cout << "Enter Address (Plot No, City, State, PIN):" << endl;
        cout << " Plot No: ";
        getline(cin >> ws, c[i].addr.plot_no);
        cout << " City: ";
        getline(cin, c[i].addr.city);
        cout << " State: ";
        getline(cin, c[i].addr.state);
        cout << " PIN Name: ";
        getline(cin, c[i].addr.pin_name);
        cout << "--------------------------------" << endl;
    }
    cout << "\n--- Displaying Company Records ---\n";
    for (int i = 0; i < SIZE; i++){
        cout << "Company: "<< c[i].name << endl;
        cout << "Phone: " << c[i].phone << endl;
        cout << "Employees: " << c[i].no_of_employee << endl;
        cout << "Address: " << c[i].addr.plot_no << ", "
             << c[i].addr.city << ", " << c[i].addr.state
             << " - " << c[i].addr.pin_name << endl;
        cout << "-------------------------------" << endl;
    }

    return 0;
}