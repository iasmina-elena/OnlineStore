#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>

class Product;

struct OrderItem {
    Product *product;
    int quantity;
};

class Order {
    int id;
    static int nextID;
    bool returned;

    std::string address;
    std::vector<OrderItem> items;

public:
    Order(const std::vector<OrderItem>& items, const std::string& address);

    int getID() const;
    bool isReturned() const;

    double totalBeforeRules() const;
    double totalFinal() const;

    void returnOrder();
    void print() const;
};

#endif //ORDER_H