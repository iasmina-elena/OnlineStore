#ifndef STORE_H
#define STORE_H

#include <vector>
#include <string>
#include "Order.h"

class Product;

class Store {
    std::vector<Product*> products;
    std::vector<Order> orders;
    Product* findProductById(int id) const;

public:
    Store();
    ~Store();

    void addProduct(Product *p);
    void listProducts() const;

    int placeOrderOneItem(int productId, int A, const std::string& address); //returneaza id ul comenzii
    double returnOrderById(int orderId);
    void listOrders() const;

    double previewOrderCost(int productId, int A) const;

};

#endif //STORE_H