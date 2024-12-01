#include <iostream>
using namespace std;

// Define a class named 'Car'
class Car {
public:
    // Data members (attributes)
    string brand;
    string model;
    int year;

    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
        cout << "Car object created!" << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car object destroyed!" << endl;
    }

    // Member function (method) to display car details
    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create an object of the class 'Car' using the constructor
    Car car1("Toyota", "Camry", 2022);

    // Call the member function to display car details
    car1.displayDetails();

    // When main function ends, the destructor is called automatically

    return 0;
}
