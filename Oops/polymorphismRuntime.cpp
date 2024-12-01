#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Overriding the base class method
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

// Another derived class
class Cat : public Animal {
public:
    // Overriding the base class method
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animal;
    Dog dog;
    Cat cat;

    // Pointing base class pointer to derived class object
    animal = &dog;
    animal->makeSound(); // Outputs: Woof!

    animal = &cat;
    animal->makeSound(); // Outputs: Meow!

    return 0;
}
