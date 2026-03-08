#include "Product.h"

int Product::count = 0;

Product::Product() {
    name = "None";
    price = 0;
    count++;
}

Product::Product(std::string name, double price) {
    this->name = name; 
    this->price = price;
    count++;
}

Product::Product(const Product& other) {
    name = other.name;
    price = other.price;
    count++;
}

Product::Product(Product&& other) {
    name = std::move(other.name);
    price = other.price;
}

void Product::setData(std::string name, double price) {
    this->name = name;
    this->price = price;
}

void Product::show() const {
    std::cout << "Name: " << name << " Price: " << price << std::endl;
}

int Product::getCount() {
    return count;
}

Product Product::operator+(const Product& other) {
    Product temp;
    temp.price = this->price + other.price;
    temp.name = this->name + "+" + other.name;
    return temp;
}

Product Product::operator-() {
    Product temp = *this;
    temp.price = -temp.price;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Product& p) {
    out << p.name << " " << p.price;
    return out;
}

std::istream& operator>>(std::istream& in, Product& p) {
    in >> p.name >> p.price;
    return in;
}