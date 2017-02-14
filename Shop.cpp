//
// Created by kacper on 29.12.16.
//

#include "Shop.h"
#include <iomanip>

void Shop::addToy(std::string nameOfToy, double priceOfToy)
{
    toys.push_back(Toy(nameOfToy, priceOfToy));
}

void Shop::deleteToy(std::string nameOfToy)
{
    for (Vector<Toy>::iterator it = toys.begin(); it != toys.end(); ++it)
        if ((*it).getName() == nameOfToy)
            toys.erase(it);
}
std::ostream &operator<<(std::ostream &out, const Shop &shop)
{
    out << std::setw(15) << shop.getCompanyName();
    out << std::setw(15) << shop.getStreetName();
    out << std::setw(15) << shop.getStreetNumber();
    out << std::endl;

    for (Vector<Toy>::iterator it = shop.toys.begin(); shop.toys.end() != it; ++it)
    {
        out << std::setw(15) << (*it).getName();
        out << std::setw(15) << (*it).getPrice() << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Shop &shop)
{
    std::string name;
    float price;
    in >> name >> price;
    shop.addToy(name, price);
    return in;
}

void Shop::addToy()
{
    toys.push_back(Toy());
}
