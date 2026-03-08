#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    double price;

    static int count; 

public:
    Product(); 
    Product(std::string name, double price);

    Product(const Product& other); 
    Product(Product&& other); 

    void setData(std::string name, double price);
    void show() const; 

    static int getCount(); 

    Product operator+(const Product& other); 
    Product operator-(); 

    friend std::ostream& operator<<(std::ostream& out, const Product& p);
    friend std::istream& operator>>(std::istream& in, Product& p);
};

#endif