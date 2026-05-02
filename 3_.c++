#include <iostream>

using namespace std;

class DB;

class DM{
    int meters;
    int centimeters;

public:
    void getData(){
        cout << "Enter distance in meters and centimeters: ";
        cin >> meters >> centimeters;
    }
    void display() {
        cout << "Distance = " << meters << " meters "
        << centimeters << " centimeters" << endl;
    }
    friend void addDistance(DM, DB);
};

class DB {
    int feet;
    int inches;

public: 
    void getData() {
        cout << "Enter distance in feet and inches: ";
        cin >> feet >> inches;
    }
    friend void addDistance(DM,DB);
};

void addDistance(DM d1, DB d2) {
    int totalInches = d2.feet * 12 + d2.inches;
    float cm_from_db = totalInches * 2.54;

    int cm_from_dm = d1.meters * 100 + d1.centimeters;

    float total_cm = cm_from_dm + cm_from_db;

    int meters = (int)(total_cm / 100);
    int centimeters = (int)(total_cm) % 100;

    cout << "\nTotal Distance (in meters and centimeters):\n";
    cout << meters << " meters " << centimeters << " centimeters" << endl;
}

int main() {
    DM d1;
    DB d2;

    d1.getData();
    d2.getData();

    addDistance(d1, d2);

    return 0;
}