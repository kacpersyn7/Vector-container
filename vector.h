//
// Created by kacper on 16.11.16.
//

#ifndef ZADANIE3_VECTOR_H
#define ZADANIE3_VECTOR_H
#include <iostream>
#include "Iterator.h"
template <class T>
class Vector
{
public:
    Vector(const Vector& orig);
    Vector(unsigned int size, const T & val);
    Vector(unsigned int size);
    Vector() { set_null(); };
    ~Vector() {delete [] vector_m; };
    void push_back(const T & val);
    void pop_back();
    void resize(unsigned count, const T & val);
    void resize(unsigned count);
    unsigned size() const { return  size_m; };
    unsigned max_size() const  {return capacity_m; };
    void clear();
    Vector & operator=(const Vector & vector);
    T & operator[](unsigned pos);
    //T  operator[]  (unsigned pos) const;
    friend class Iterator<T>;
    typedef class Iterator<T> iterator;
    iterator begin() const { return Iterator<T>(*this, 0); }
    iterator end() const { return Iterator<T>(*this, size_m); }
    Iterator<T> erase(const iterator it);
    Iterator<T> erase(const iterator start, const iterator finish); //usuwa elementy od start do finish
    Iterator<T> insert (const iterator position, const T & val);
private:
    T *vector_m;
    unsigned int size_m;
    unsigned int capacity_m;
    void set_null() { capacity_m = 0; size_m = 0; vector_m = new T [0]; }

};
template<class T>
Vector<T>::Vector(const Vector& orig)
{
    if (orig.capacity_m > 0 && orig.vector_m != nullptr)
    {
        vector_m = new T[orig.capacity_m];
        capacity_m = orig.capacity_m;
        size_m = orig.size_m;
        for (int i = 0; i < size_m; ++i)
            vector_m[i] = orig.vector_m[i];
    }
    else
    {
        throw std::logic_error("operacja kopiowania niedozwolona!");
    }
}
template<class T>
Vector<T>::Vector(unsigned int size, const T & val)
{
    capacity_m = size;
    size_m = size;
    vector_m = new T[size];
    for (int i = 0; i < size_m; ++i)
        vector_m[i] = val;
}
template<class T>
Vector<T>::Vector(unsigned int size)
{
    capacity_m = size;
    size_m = size;
    vector_m = new T[size];
    for (int i = 0; i < size_m; ++i)
        vector_m[i] = T();
}
template<class T>
void Vector<T>::push_back(const T & val)
{
    if (size_m < capacity_m)
    {
        vector_m[size_m] = val;
        ++size_m;
    }
    else
    {
        capacity_m += 5;
        T *temp_vector = new T[capacity_m];
        for (int i = 0; i < size_m; ++i)
            temp_vector[i] = vector_m[i];

        temp_vector[size_m] = val;
        ++size_m;
        delete[] vector_m;
        vector_m = temp_vector;
    }
}
template <class T>
void Vector<T>::resize(unsigned count, const T & val)
{
    if(count > size_m)
        for (int i = size_m; i < count; ++i)
            push_back(val);
    else
        while (size_m != count)
            pop_back();
}
template <class T>
void Vector<T>::resize(unsigned count)
{
    if(count > size_m)
        for (int i = size_m; i < count; ++i)
            push_back(T());
    else
        while (size_m != count)
            pop_back();
}
template<class T>
void Vector<T>::pop_back()
{
    if(size_m > 0)
        size_m--;
}
template <class T>
void Vector<T>::clear()
{
    delete[] vector_m;
    set_null();
}
template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & vector)
{
    if (this != &vector)
    {
        delete[] vector_m;
        capacity_m = vector.capacity_m;
        size_m = vector.size_m;
        vector_m = new T[vector.capacity_m];
        for (int i = 0; i < size_m; ++i)
            vector_m[i] = vector.vector_m[i];
    }
    return *this;
}
template<class T>
T & Vector<T>::operator [](unsigned i)
{
    if(i < size_m)
        return *(vector_m + i);
    else
        throw std::logic_error("poza zakresem!");
}
/*template<class T>
T  Vector<T>::operator [](unsigned i) const
{
    if(i < size_m)
        return *(vector_m + i);
    else
    {
        throw std::logic_error("poza zakresem!");
    }
}*/
template <class T>
Iterator<T> Vector<T>::erase(const Vector::iterator it)
{
    iterator new_temp = it;
    iterator old_temp = it;
    if(it <= end())
    {
        while(old_temp != end())
        {
            ++old_temp;
            *new_temp = *old_temp;
            ++new_temp;
        }
        size_m--;
        return new_temp;
    }
    else
        throw std::logic_error("poza zakresem!");
}
template <class T>
Iterator<T> Vector<T>::erase(const iterator start, const iterator finish)
{
    iterator new_temp = start;
    iterator old_temp = finish;
    unsigned i = 0;
    if(start <= finish && finish <= end())
    {
        while(new_temp != finish)
        {
            *new_temp = *old_temp;
            ++old_temp;
            ++new_temp;
            ++i;
        }
        while(old_temp != end())
        {
            *new_temp = *old_temp;
            ++old_temp;
            ++new_temp;
        }
        size_m -= i;

        return new_temp;
    }
    else
        throw std::logic_error("poza zakresem!");
}
template <class T>
Iterator<T> Vector<T>::insert(const Vector::iterator position, const T &val)
{
    if(position <= end())
    {
        auto old_temp = end();
        unsigned i = 0;
        while(old_temp != position)
        {
            --old_temp;
            ++i;
        }
        auto new_temp = end();
        push_back(*(new_temp-1));
        old_temp = end();
        new_temp = --old_temp;
        for(int j = 0; j < i;++j)
        {
            --old_temp;
            *new_temp = *old_temp;
            --new_temp;
        }
        *(new_temp) = val;
        return new_temp;
    }
    else
        throw std::logic_error("poza zakresem!");
}


#endif /* VECTOR_H */




