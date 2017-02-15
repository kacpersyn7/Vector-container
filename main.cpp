#include "vector.h"
#include "Toy.h"
#include "Shop.h"
#include "Company.h"
#include <fstream>

int main()
{
    try
    {
        Vector <Company> Database;

        Vector<Company>::iterator it;

        bool done = false;
        std::string tempToyName;
        int tempToyPrice;
        std::string tempName;
        std::string tempCompanyName;
        std::string tempStreetName;
        int tempStreetNumber;
        std::fstream shopFile;
        Shop tempShop;



        shopFile.open("Shops.txt");
        if (!shopFile.is_open())
        {
            throw "File open error";
        }
        while (shopFile && shopFile >> tempCompanyName && shopFile >> tempStreetName && shopFile >> tempStreetNumber)
        {
            for (it = Database.begin(); it != Database.end(); ++it)
                if ((*it).getCompanyName() == tempCompanyName)
                {
                    (*it).addStore(tempStreetName, tempStreetNumber);
                    break;
                }

            if (it == Database.end())
            {
                Database.push_back(Company(tempCompanyName));
                it = Database.end()-1;
                (*it).addStore(tempStreetName, tempStreetNumber);
            }
        }
        shopFile.close();

        for (Company elem : Database)
            std::cout << elem;

       /* Vector<Company> myvector(4);
        myvector[1].addStore();
        myvector[1].addStore();
        myvector[1].addToyToAllStores();
        for (auto it=myvector.begin(); it!=myvector.end(); ++it)
            std::cout<< *it;
        //for(Shop x : myvector);


            //std::cout << x;

        /*Vector<int> myvector (3,100);
        Vector<int>::iterator it;

        it = myvector.begin()+3;
        myvector.insert ( it , 200 );
        std::cout << "myvector contains:";
        for (it=myvector.begin(); it!=myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
       /* myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        Vector<int> anothervector (2,400);
        myvector.insert (it+2,anothervector.begin(),anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3);

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';

        return 0;
       /* Vector<std::string> a (10);
        a.push_back("aasadaa");
        a.push_back("lol");
        // std::cout<<a[0];

        a.push_back("lel");
        a.push_back("hue");
        a.push_back("mue");
        a.push_back("coo");
        a.push_back("aasadaa");
        a.push_back("blabla");
        a.push_back("huehue");
        a.push_back("cooo");
        a.push_back("aasadaa");
        a.push_back("aasadaa");
        a.push_back("blabla");
        a.push_back("aasadaa");
        a.push_back("blabla");
        a.push_back("aasadaa");
        a.push_back("blabla");
        for(std::string x : a)
        { // iteracja po typie użytkownika
            std::cout << " " << x;
        }
        a.pop_back();
        for(std::string x : a)
        { // iteracja po typie użytkownika
            std::cout << " " << x;
        }
        std::cout<<"\n";
        std::cout<<"\n";
        a.clear();
        a.push_back("aasadaa");
        a.push_back("blabla");
        a.push_back("huehue");
        a.push_back("cooo");
        a.push_back("noo");
        a.push_back("nopo");
        std::cout<<"\n";
        for(std::string x : a)
        { // iteracja po typie użytkownika
            std::cout << " " << x;
        }
        std::cout<<"\n";
        a.erase(a.begin()+1,a.begin()+3);
        std::cout<<"\n";
        for(std::string x : a)
        { // iteracja po typie użytkownika
            std::cout << " " << x;
        }
        std::cout<<"\n";
        //Vector<std::string>::iterator it = a.begin() + 1;
        //std::cout<<*it<<"\n";

        //std::cout<<a[3];
        //a.pop_back();
        //std::cout<<a[4];
        /*  a.pop_back();
          a.pop_back();
          //a.pop_back();
          a.resize(15);
          std::cout<<a[3];
          //a.resize(3);
          a.push_back("lol");
          std::cout<<a[2];*/
        return 0;
    }
    catch (std::bad_alloc & ba) {
        std::cerr<<ba.what()<<"\n";
    }
    catch (std::logic_error & lo) {
        std::cerr<<lo.what()<<"\n";//exit(EXIT_FAILURE);
    }
}
