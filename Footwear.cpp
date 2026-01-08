#include "Footwear.h"

Footwear::Footwear(std::string name, double price, int stock, int size)
        : Product(std::move(name), price, stock), size(size){}

std::string Footwear::type() const {
        return "Incaltaminte";
}

void Footwear::print(std::ostream& os) const {
        os << "[INCALTAMINTE] "
           << "ID = " << id
           << " | Nume = " << name
           << " | Pret = " << price
           << " | Marime = " << size
           << " | Stoc = " << stock;
}