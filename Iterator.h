//
// Created by kacper on 27.11.16.
//

#ifndef ZADANIE3_ITERATOR_H
#define ZADANIE3_ITERATOR_H
#include "vector.h"
#include <iostream>
template <class T> class Vector;
template <class T>
class Iterator {
public:
    Iterator(const Vector<T>& vec, unsigned pos = 0);
    Iterator(): ptr(nullptr){};
    bool operator!=(const Iterator<T>& iter) const { return ptr != iter.ptr; }
    bool operator==(const Iterator<T>& iter) const { return ptr == iter.ptr; }
    bool operator<(const Iterator<T>& iter) const { return ptr < iter.ptr; }
    bool operator<=(const Iterator<T>& iter) const { return ptr <= iter.ptr; }
    const Iterator<T> operator+(const unsigned int val) const { T* temp_ptr = ptr + val  ; return Iterator<T>(&temp_ptr);}
    const Iterator<T> operator-(const unsigned int val) const { T* temp_ptr = ptr - val  ; return Iterator<T>(&temp_ptr);}
    T & operator*() const {return *ptr;};
    const Iterator<T> operator++() { ++ptr; return *this; }
    const Iterator<T> operator--() { --ptr; return *this; }

private:
    Iterator(T ** p): ptr(*p){};
    T *ptr;
};
template <class T>
Iterator<T>::Iterator(const Vector<T>& vec, unsigned pos)
{
    if(pos <= vec.size())
        ptr = &(vec.vector_m[pos]);
    else
        throw std::logic_error("poza zakresem!");

}

#endif //ZADANIE3_ITERATOR_H
