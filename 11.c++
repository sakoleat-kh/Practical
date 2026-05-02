#include <iostream>
using namespace std;

class POUNDS;

class KILOS {
    int kg;
    float g;

public:
    KILOS(int k = 0, float gram = 0) : kg(k), g(gram) {}

    void display() {
        cout << kg << " kg, " << g << " g" << endl;
    }
    friend POUNDS addWeightd(KILOS, POUNDS);
};

class POUNDS {
    int lbs;
    float oz;

public: POUNDS(int p = 0, float o = 0) : lbs(p), oz(o) {}
    void display() {
        cout << lbs << " lbs, " << oz << " oz" << endl;
    }
    friend POUNDS addWeightd(KILOS, POUNDS);
};

POUNDS addWeightd(KILOS k_obj, POUNDS p_obj) {
    float total_grams = (k_obj.kg * 1000) + k_obj.g;
    float k_in_ounces = total_grams / 28.0;
    float total_ounces = k_in_ounces + (p_obj.lbs * 16) + p_obj.oz;
    int final_lbs = (int)(total_ounces / 16);
    float final_oz = total_ounces - (final_lbs * 16);

    return POUNDS(final_lbs, final_oz);
}

int main() {
    KILOS k1(2, 500);
    POUNDS p1(3, 4);

    cout << "Weight in KILOS: ";
    k1.display();
    cout << "Weight in POUNDS: ";
    p1.display();

    POUNDS result = addWeightd(k1, p1);
    cout << "Total wight after addition: ";
    result.display();

    return 0;
}