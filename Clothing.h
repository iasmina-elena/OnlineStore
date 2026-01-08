#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"

class Clothing : public Product {
    std::string size;

public:
    Clothing(std::string name, double price, int stock, std::string size);

    std::string type() const override;
    void print(std::ostream& os) const override;
};

#endif //CLOTHING_H