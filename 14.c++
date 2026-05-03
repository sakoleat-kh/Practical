#include <iostream>
#include <cstdlib>

class NumberWrapper {
    private:
        int value;

    public:
        NumberWrapper(int val) : value(val) {}

        NumberWrapper(const char* valStr) {
            value = std::atoi(valStr);
        }

    int getValue() const {
        return value;
    }
};

int main() {
    NumberWrapper obj1(100);
    NumberWrapper obj2("250");

    std::cout << "Value 1: " << obj1.getValue() << std::endl;
    std::cout << "Value 2: " << obj2.getValue() << std::endl;

    return 0;
}