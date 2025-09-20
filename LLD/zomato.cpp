#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class User {
    string name;
    string address;

public:
    User(const string& n, const string& add) : name(n), address(add) {}

    string getName() const { return name; }
    string getAddress() const { return address; }
};

class MenuItem {
    string name;
    double price;

public:
    MenuItem(const string& n, double p) : name(n), price(p) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
};

class Restaurant {
    string name;
    vector<MenuItem> menu;

public:
    Restaurant(const string& n) : name(n) {}

    string getName() const { return name; }
    void addMenuItem(const MenuItem& item) { menu.push_back(item); }
    const vector<MenuItem>& getMenu() const { return menu; }
};

class Cart {
    vector<MenuItem> items;
    double totalPrice;

public:
    Cart() : totalPrice(0) {}

    void addItem(const MenuItem& item) {
        items.push_back(item);
        totalPrice += item.getPrice();
    }

    void removeItem(const string& itemName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == itemName) {
                totalPrice -= it->getPrice();
                items.erase(it);
                break;
            }
        }
    }

    double getTotalPrice() const { return totalPrice; }
    const vector<MenuItem>& getItems() const { return items; }

    void showCart() const {
        cout << "Cart:\n";
        for (const auto& item : items) {
            cout << "- " << item.getName() << " : Rs." << item.getPrice() << "\n";
        }
        cout << "Total in Cart: Rs." << totalPrice << "\n";
    }
};

class Order {
    const User* user;
    const Restaurant* res;
    vector<MenuItem> items;
    double totalPrice;

public:
    Order(const User* u, const Restaurant* r, const Cart& cart)
        : user(u), res(r), totalPrice(cart.getTotalPrice()), items(cart.getItems()) {}

    double getTotalPrice() const { return totalPrice; }
    void showOrderDetails() const {
        cout << "\nOrder for " << user->getName() << " from " << res->getName() << ":\n";
        for (const auto& item : items) {
            cout << "- " << item.getName() << " : Rs." << item.getPrice() << "\n";
        }
        cout << "Total: Rs." << totalPrice << "\n";
    }
};

class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual ~Payment() {}
};

class CardPayment : public Payment {
    string cardNumber;
public:
    CardPayment(const string& c) : cardNumber(c) {}
    bool pay(double amount) override {
        cout << "Processing Card Payment of Rs." << amount << " using card " << cardNumber << "...\n";
        return true; // assume success
    }
};

class Delivery {
    const Order* order;
public:
    Delivery(const Order* o) : order(o) {}
    void deliver(const User* user) const {
        cout << "Delivering order to " << user->getName() << " at " << user->getAddress() << "...\n";
    }
};

int main() {
    User* user =  new User("Shivam", "IIIT Sonepat Hostel");
    Restaurant* res = new Restaurant("Pizza Palace");

    res->addMenuItem(MenuItem("Margherita Pizza", 250));
    res->addMenuItem(MenuItem("Garlic Bread", 120));
    res->addMenuItem(MenuItem("Coke", 50));

    // User adds items to Cart
    Cart cart;
    cart.addItem(res->getMenu()[0]);
    cart.addItem(res->getMenu()[2]);
    cart.showCart();

    // User places order from cart
    Order* order = new Order(user, res, cart);
    order->showOrderDetails();

    // Payment
    CardPayment payment("1234-5678-9012");
    if (payment.pay(order->getTotalPrice())) {
        cout << "Payment Successful!\n";
    }

    // Delivery
    Delivery delivery(order);
    delivery.deliver(user);

    return 0;
}