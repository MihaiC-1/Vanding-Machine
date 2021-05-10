//
//  testProduct.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "testProduct.hpp"
#include "product.hpp"
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

void test_getter()
{
    
    string name_1 = "Dorna";
    string name_2 = "Dorna";
    string name_3 = "Dorna";
    
    Product prod_1(1, name_1, 5);
    Product prod_2(2, name_2, 7);
    Product prod_3(3, name_3, 6);
    
    assert(prod_1.get_code() == 1);
    assert(prod_2.get_code() == 2);
    assert(prod_3.get_code() == 3);
    
    assert(prod_1.get_price() == 5);
    assert(prod_2.get_price() == 7);
    assert(prod_3.get_price() == 6);
    
    assert(prod_1.get_name() == name_1);
    assert(prod_2.get_name() == name_1);
    assert(prod_3.get_name() == name_1);
}

void test_setter()
{
    Product prod(1, "Apa", 6);
    
    prod.set_code(5);
    prod.set_price(4);
    prod.set_name("Suc");
    
    assert(prod.get_code() == 5);
    assert(prod.get_price() == 4);
    assert(prod.get_name() == "Suc");
}

void test_eq()
{
    char* name = new char[10];
    
    strcpy(name, "Viva");
    
    Product p_1(1, name, 5),
            p_2(1, name, 5);
    
    assert(p_1 == p_2);
}

void test_product()
{
    test_getter();
    test_setter();
    test_eq();
}
