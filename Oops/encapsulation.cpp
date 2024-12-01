#include <iostream>
using namespace std;

class Person {
private:
    // Private data members
    string name;
    int age;

public:
    // Setter method for name
    void setName(string n) {
        name = n;
    }

    // Getter method for name
    string getName() {
        return name;
    }

    // Setter method for age
    void setAge(int a) {
        if (a > 0) { // Simple validation
            age = a;
        } else {
            cout << "Please enter a valid age." << endl;
        }
    }

    // Getter method for age
    int getAge() {
        return age;
    }

    // Method to display Person details
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Create an object of the Person class
    Person person1;

    // Set the name and age using setter methods
    person1.setName("John");
    person1.setAge(25);

    // Display the person's details
    person1.displayInfo();

    // Access the name and age using getter methods
    cout << "Name from getter: " << person1.getName() << endl;
    cout << "Age from getter: " << person1.getAge() << endl;

    return 0;
}
