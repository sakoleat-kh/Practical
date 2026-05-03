#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addStudent() {
    Student s;
    ofstream outFile("students.dat", ios::binary | ios::app);

    cout << "Enter student ID: "; cin >> s.id;
    cin.ignore();
    cout << "Enter Name: "; cin.getline(s.name, 50);
    cout << "Enter GPA: "; cin >> s.gpa;

    outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    outFile.close();
    cout << "Record added successfully.\n";
}

void updateStudent() {
    int id;
    bool found = false;
    cout << "Enter Student ID to update: "; cin >> id;

    fstream file("student.dat", ios::binary | ios::in | ios::out);
    Student s;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.id == id) {
            cout << "Enter New Name: "; cin.ignore(); cin.getline(s.name, 50);
            cout << "Enter New GPA: "; cin >> s.gpa;

            file.seekp(-static_cast<std::streamoff>(sizeof(Student)), ios::cur);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Student ID not found.\n";
}

void deleteStudent() {
    int id; bool found = false;
    cout << "Enter Student ID to delete: "; cin >> id;

    ifstream inFile("student.dat", ios::binary);
    ofstream temFile("temp.dat", ios::binary);
    Student s;

    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.id != id) {
            temFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
        } else {
            found = true;
        }
    }

    inFile.close();
    temFile.close();

    remove("Student.dat");
    rename("temp.dat", "Student.dat");

    if (found) cout << "Record deleted succeddfully.\n";
    else cout << "Record not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. add Student\n2. Update Student\n3. Delete Student\n4. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: addStudent(); break;
            case 2: updateStudent(); break;
            case 3: deleteStudent(); break;
        }
    } while (choice != 4);

    return 0;
    
}