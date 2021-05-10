//
//  product.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "product.hpp"
#include <iostream>
#include <ostream>
#include <string.h>
#include <cstddef>
#include <cstring>
#include <string>

using namespace std;

Product::Product()
{
    this->code = 0;
    this->name = "";
    this->price = 0;
}

Product::Product(int code, string name, int price)
{
    this->code = code;
    this->name = name;
    this->price = price;
}

Product::Product(const Product& p)
{
    this->code = p.code;
    this->price = p.price;
    this->name = p.name;
}

Product::~Product()
{
    this->name = "";
}

int Product::get_code()
{
    return this->code;
}

int Product::get_price()
{
    return this->price;
}

string Product::get_name()
{
    return this->name;
}

void Product::set_code(int code)
{
    this->code = code;
}

void Product::set_price(int price)
{
    this->price = price;
}

void Product::set_name(string name)
{
    this->name = name;
}

Product& Product::operator = (const Product& p)
{
    this->set_code(p.code);
    this->set_price(p.price);
    this->set_name(p.name);
    return *this;
}

bool Product::operator == (const Product& p)
{
    return (this->code == p.code) && (this->price == p.price) && (this->name == name);
}

ostream& operator<<(ostream& os, const Product& p) {
    os << p.code << " " << p.name << " " << p.price;
    return os;
}
