#include <iostream>
using namespace std;

// Abstract class (Interface)
class Animal {
public:
    // Pure virtual function (abstract method)
    virtual void makeSound() = 0; // No implementation here
};

// Derived class inheriting from Animal
class Dog : public Animal {
public:
    // Implementing the abstract method
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

// Another derived class inheriting from Animal
class Cat : public Animal {
public:
    // Implementing the abstract method
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    // Create objects of derived classes
    Dog dog;
    Cat cat;

    // Use the objects to call the makeSound method
    dog.makeSound();   // Outputs: Woof!
    cat.makeSound();   // Outputs: Meow!

    return 0;
}
