
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() {
        return 0;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() override {
        return 0.5 * base * height;
    }
};

// Main function
int main() {
    int choice;

    cout << "===== SHAPE AREA CALCULATOR =====" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    Shape* shape = nullptr;

    if (choice == 1) {
        double radius;

        cout << "Enter radius: ";
        cin >> radius;

        if (radius <= 0) {
            cout << "Invalid dimension!" << endl;
            return 0;
        }

        shape = new Circle(radius);
    }
    else if (choice == 2) {
        double length, width;

        cout << "Enter length and width: ";
        cin >> length >> width;

        if (length <= 0 || width <= 0) {
            cout << "Invalid dimensions!" << endl;
            return 0;
        }

        shape = new Rectangle(length, width);
    }
    else if (choice == 3) {
        double base, height;

        cout << "Enter base and height: ";
        cin >> base >> height;

        if (base <= 0 || height <= 0) {
            cout << "Invalid dimensions!" << endl;
            return 0;
        }

        shape = new Triangle(base, height);
    }
    else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    cout << "Area = " << shape->area() << endl;

    delete shape;

    return 0;
}
