//
//  product.hpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Product
{
private:
    int code;
    string name;
    int price;
public:
    Product();
    ~Product();
    Product(int code, string name, int price);
    Product(const Product& p);
    int get_code();
    int get_price();
    string get_name();
    void set_code(int code);
    void set_price(int price);
    void set_name(string name);
    Product& operator = (const Product& p);
    bool operator == (const Product& p);
    friend ostream& operator << (ostream& os, const Product& p);
};
