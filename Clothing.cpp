#include "Clothing.h"

Clothing::Clothing(std::string name, double price, int stock, std::string size)
        : Product(std::move(name), price, stock),
          size(std::move(size)) {
}

std::string Clothing::type() const {
    return "Haina";
}

void Clothing::print(std::ostream& os) const {
    os << "[HAINA] "
    << "ID = " << id
    << " | Nume = " << name
    << " | Pret = " << price
    << " | Marime = " << size
    << " | Stoc = " << stock;
}