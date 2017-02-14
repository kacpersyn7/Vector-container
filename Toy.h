//
// Created by kacper on 29.12.16.
//

#ifndef ZADANIE3_TOY_H
#define ZADANIE3_TOY_H

#include <string>
class Toy {
private:
    std::string name_m = "ಠ_ಠ";
    double price_m = 0.0;
public:
    Toy(){};
    Toy(std::string name, double price):
            name_m(name), price_m(price){};
    std::string getName() const { return name_m;}
    double getPrice() const { return price_m;}
};

#endif //ZADANIE3_TOY_H
