#include <iostream>
using namespace std;

// Base class (Parent class)
class Vehicle {
public:
    string brand;
    int year;

    // Constructor for the base class
    Vehicle(string b, int y) {
        brand = b;
        year = y;
    }

    // Base class method
    void honk() {
        cout << "Beep beep!" << endl;
    }
};

// Derived class (Child class) inheriting from Vehicle
class Car : public Vehicle {
public:
    string model;

    // Constructor for the derived class
    Car(string b, int y, string m) : Vehicle(b, y) {
        model = m;
    }

    // Derived class method
    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "Model: " << model << endl;
    }
};

int main() {
    // Create an object of the derived class
    Car car1("Toyota", 2022, "Camry");

    // Call methods from both the base and derived classes
    car1.honk();             // Method from the base class
    car1.displayDetails();   // Method from the derived class

    return 0;
}
