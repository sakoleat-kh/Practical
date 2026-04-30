#include <iostream>
#include <cstring>

using namespace std;

class String {
    char* str;
    int len;

public:
    String() {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(const char* s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    String(const String& s) {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }
    ~String() {
        delete[] str;
    }
    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s1;
    String s2("Hello");
    String s3 = s2;

    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    cout << "s3: ";
    s3.display();

    return 0;
}
