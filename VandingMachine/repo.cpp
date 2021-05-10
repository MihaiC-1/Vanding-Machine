//
//  repo.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//
/*
#include "repo.hpp"
#include "product.hpp"
#include <vector>
#include <iostream>

using namespace std;

Repo::Repo()
{
}
Repo::~Repo()
{
    this->products.clear();
}
void Repo::add_product(Product p)
{
    this->products.push_back(p);
}

vector<Product> Repo::get_all()
{
    return this->products;
}

long Repo::get_size()
{
    return this->products.size();
}

void Repo::delete_product(Product p)
{
    int ok = 0;
    int i = 0;
    while (i < this->products.size())
    {
        if (ok == 0)
        {
            if (this->products[i] == p)
                ok = 1;
            else
                i++;
        }
        else if (ok == 1)
        {
            if (i < this->products.size() - 1)
                this->products[i] = this->products[i + 1];
            i++;
        }
    }
    this->products.pop_back();
}

void Repo::update_product(Product p, Product new_p)
{
    vector<Product>::iterator t;
    
    t = find(this->products.begin(), this->products.end(), p);
    
    if (t != this->products.end())
    {
        *t = new_p;
    }
}

Product Repo::get_product_at_position(int pos)
{
    if (pos < 0 || pos > this->products.size() - 1)
    {
        char emptyName[] = "";
        return Product(0, emptyName, 0);
    }
    return this->products[pos];
}
*/
