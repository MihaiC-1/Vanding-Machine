//
//  repo.hpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Repo
{
protected:
    vector<T> products;
public:
    Repo();
    ~Repo();
    vector<T> get_all();
    T get_product_by_code(int code);
    long get_size();
    void add_product(T& p);
    void delete_product_by_code(int code);
    void update_product_by_code(T& p, int code);
};

template<class T>
Repo<T>::Repo()
{
    
}

template<class T>
Repo<T>::~Repo()
{
    this->products.clear();
}

template<class T>
void Repo<T>::add_product(T& p)
{
    for (int i = 0; i < get_size(); i++ )
    {
        if (this->products[i].get_code() == p.get_code())
        {
            cout << "Objects can't have the same code!";
            return;
        }
    }
    this->products.push_back(p);
}

template<class T>
vector<T> Repo<T>::get_all()
{
    return this->products;
}

template<class T>
long Repo<T>::get_size()
{
    return this->products.size();
}

template<class T>
void Repo<T>::delete_product_by_code(int code)
{
    for (int i = 0; i < get_size(); i++)
    {
        if (this->products[i].get_code() == code)
        {
            this->products.erase(this->products.begin() + i);
            return;
        }
    }
}

template<class T>
void Repo<T>::update_product_by_code(T& p, int code)
{
    for (int i = 0; i < get_size(); i++)
    {
        if (this->products[i].get_code() == code)
        {
            this->products[i] = p;
        }
    }
}

template<class T>
T Repo<T>::get_product_by_code(int code)
{
    for (int i = 0; i < get_size(); i++)
    {
        if (this->products[i].get_code() == code)
        {
            return this->products[i];
        }
    }
    return this->products[0];
}

