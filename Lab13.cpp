#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {}
    virtual double getFinalPrice() const = 0; 
    string getName() const { return name; }
    double getPrice() const { return price; }
    virtual ~Product() = default;
};

class Book : public Product {
public:
    Book(const string& name, double price) : Product(name, price) {}
    double getFinalPrice() const override { return price * 0.9; } 
};

class Pen : public Product {
public:
    Pen(const string& name, double price) : Product(name, price) {}
    double getFinalPrice() const override { return (price > 5) ? price - 5 : price; } 
};

int main() {
    Product* products[] = {
        new Book("C++ for Beginners", 200),
        new Book("Advanced C++", 300),
        new Pen("Blue Pen", 10),
        new Pen("Red Pen", 4)
    };

    for (const auto& product : products) {
        cout << product->getName() << " - Base Price: " << product->getPrice()
             << ", Final Price: " << product->getFinalPrice() << endl;
        delete product; 
    }

    return 0;
}
