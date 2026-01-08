#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {

protected:
    int id;
    std::string name;
    double price;
    int stock;
    static int nextID;

public:
    Product(std::string name, double price, int stock);
    virtual ~Product(); // destructor virtual (important la mostenire)

    int getID() const;
    double getPrice() const;
    int getStock() const;

    void decreaseStock(int A);
    void increaseStock(int A);

    virtual std::string type() const=0;
    virtual void print(std::ostream& os) const=0;
};

std::ostream& operator<<(std::ostream& os, const Product& p);

#endif //PRODUCT_H