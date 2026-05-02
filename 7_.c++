#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
    string empID;
    string empName;
    string dob;
    double salary;

    public:
    void addDetails() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, dob);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayDetails() const {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Salary: $" << salary << endl; 
        cout << "-------------------------" << endl;
    }
};

int main() {
    Employee emp;
    emp.addDetails();
    emp.displayDetails();

    return 0;
}