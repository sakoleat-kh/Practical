#include <iostream>
#include <cmath>

class Rectangle ;

class Polar {
    float r, theta;
public:
    Polar(float radius = 0, float angle = 0) : r(radius), theta(angle) {}
    Polar(const Rectangle &rect);
    float getR() {return r; }
    float getTheta() {return theta; }
    void display() { std::cout << "Polar -> r: " << r << ", theta: " << theta << "radius" << std::endl; }
};

class Rectangle {
    float x, y;
    friend class Polar;
public:
    Rectangle(float x_coord = 0, float y_coord = 0) : x(x_coord), y(y_coord) {}
    Rectangle(Polar p) {
        x = p.getR() * cos(p.getTheta());
        y = p.getR() * sin(p.getTheta());
    }
    void display() { std::cout << "Rectangle -> x: " << x << ", y: " << y << std::endl; }
};

Polar::Polar(const Rectangle &rect) {
    r = std::sqrt(rect.x * rect.x + rect.y * rect.y);
    theta = std::atan2(rect.y, rect.x);
}

int main() {
    Polar p1(10, 0.5236);
    Rectangle r1 = p1;
    p1.display();
    r1.display();

    Rectangle r2(5, 5);
    Polar p2 = r2;
    r2.display();
    p2.display();

    return 0;
}