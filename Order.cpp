#include "Order.h"
#include "Product.h"
#include <iostream>
#include <stdexcept>

int Order::nextID = 1;

Order::Order(const std::vector<OrderItem>& items, const std::string& address)
     : id(nextID++), returned(false), address(address), items(items) {}

int Order::getID() const {return id;}
bool Order::isReturned() const {return returned;}

double Order::totalBeforeRules() const {
     double sum = 0;
     for (const auto& item : items) {
          sum += item.product->getPrice() * item.quantity;
     }
     return sum;
}

double Order::totalFinal() const {
     double sum = totalBeforeRules();
     if (sum > 500) {
          sum -=100; // reducere
     }
     else if (sum < 100) {
          sum +=20; // taxa transport
     }
     return sum;
}

void Order::returnOrder() {
     if (returned) {
          throw std::runtime_error("Comanda deja returnata");
     }
     for (auto& item : items) {
          item.product->increaseStock(item.quantity);
     }
     returned = true;
}

void Order::print() const {
     std::cout << "Comanda #" << id
               << " | Adresa: " << address
               << " | Total initial: " << totalBeforeRules()
               << " | Total final: " << totalFinal()
               << " | Status: " ;
     if (returned) {
          std::cout << "Returnata";
     }
     else {
          std::cout << "Activa";
     }
     std::cout << "\n";
}
