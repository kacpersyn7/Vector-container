//
// Created by kacper on 29.12.16.
//

#ifndef ZADANIE3_COMPANY_H
#define ZADANIE3_COMPANY_H

#include "vector.h"
#include "Shop.h"
#include "Toy.h"

class Company{
private:
    std::string companyName = "( ͠° ͜ʖ °)";
    Vector<Shop> stores;
public:
    Company(std::string name) : companyName(name) {};
    Company(){};
    void addStore(std::string streetName, int streetNumber);
    void addToyToAllStores(std::string nameOfToy, double priceOfToy);
   // void addStore();
    void addToyToAllStores();
    std::string getCompanyName() const { return companyName;}
    Shop & getShopInfo(int position) { return stores[position];}
    int getStoresAmount() const { return stores.max_size();}

    friend std::ostream & operator<<(std::ostream & out, const Company & outCmp);
    friend std::istream & operator>>(std::istream& in, Company & inF);
};


#endif //ZADANIE3_COMPANY_H
