#include "Store.h"
#include "Product.h"
#include <iostream>
#include <stdexcept>

Store::Store() {

}

Store::~Store() {
    for (Product* p : products) {
        delete p;
    }
}

void Store::addProduct(Product* p) {
    products.push_back(p);
}

void Store::listProducts() const {
    for (Product* p : products) {
        std::cout << *p << "\n";
    }
}

Product* Store::findProductById(int id) const {
    for (Product* p : products) {
        if (p->getID() == id) {
            return p;
        }
    }

    throw std::runtime_error("Produsul nu exista");
}


int Store::placeOrderOneItem(int productId, int A, const std::string& address) {
    Product* p = findProductById(productId);

    p->decreaseStock(A);

    std::vector<OrderItem> items;
    OrderItem item;
    item.product = p;
    item.quantity = A;
    items.push_back(item);

    Order newOrder(items, address);
    orders.push_back(newOrder);

    std::cout << "Comanda plasata cu succes!";
    return newOrder.getID();
}

double Store::returnOrderById(int orderId) {
    for (Order& o : orders) {
        if (o.getID() == orderId) {
            double refund = o.totalFinal();
            o.returnOrder();
            std::cout << "Comanda returnata";
            return refund;
        }
    }
    throw std::runtime_error("Comanda nu exista");
}

void Store::listOrders() const {
    if (orders.size() == 0) {
        std::cout << "Nu exista comenzi\n";
        return;
    }
    for (const Order& o : orders) {
        o.print();
    }
}

double Store::previewOrderCost(int productId, int A) const {
    Product* p = findProductById(productId);
    double sum = p->getPrice() * A;

    if (sum > 500) {
        sum -= 100;
    }
    else if (sum < 100) {
        sum +=20;
    }
    return sum;
}