//
// Created by kacper on 29.12.16.
//

#ifndef ZADANIE3_SHOP_H
#define ZADANIE3_SHOP_H

#include "Toy.h"
#include "vector.h"
class Shop {
private:
    Vector<Toy> toys;
    std::string streetName = "^‿^";
    int streetNumber = 0;
    std::string companyName = "(ง─|─)ง";
public:
    Shop(std::string streetName, std::string companyName, int streetNumber)
            : streetName(streetName), streetNumber(streetNumber), companyName(companyName) {};
   // Shop(std::string cName): companyName(cName){};
    Shop(){};
    std::string getCompanyName() const { return companyName;}
    std::string getStreetName() const { return streetName;}
    int getStreetNumber() const { return streetNumber;}
    void addToy(std::string nameOfToy, double priceOfToy);
    void addToy();
    void deleteToy(std::string nameOfToy);

    friend std::ostream & operator<<(std::ostream & out, const Shop & shop);
    friend std::istream & operator>>(std::istream & in, Shop & shop);
};


#endif //ZADANIE3_SHOP_H
