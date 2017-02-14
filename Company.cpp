//
// Created by kacper on 29.12.16.
//
#include <iomanip>
#include "Company.h"
std::ostream &operator<<(std::ostream &out, const Company &company) {
    if (company.getStoresAmount() == 0)
        out << std::setw(15) << company.companyName << "\n";
    for (Vector<Shop>::iterator it = company.stores.begin(); company.stores.end() != it; ++it)
    {
        out  << (*it);
        out  << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Company &company)
{
    in >> company.companyName;
    return in;
}

void Company::addToyToAllStores(std::string nameOfToy, double priceOfToy)
{
    for (Vector<Shop>::iterator it = stores.begin(); it != stores.end(); ++it)
        (*it).addToy(nameOfToy, priceOfToy);
}
void Company::addToyToAllStores()
{
    for (Vector<Shop>::iterator it = stores.begin(); it != stores.end(); ++it)
        (*it).addToy();
}
void Company::addStore(std::string streetName, int streetNumber)
{
    stores.push_back(Shop(streetName, companyName, streetNumber));
}
/*void Company::addStore()
{
    stores.push_back(Shop(companyName));
}*/