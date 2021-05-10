//
//  testService.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//
/*
#include "testService.hpp"
#include "service.hpp"
#include <string>
#include <iostream>
#include <vector>

void test_s_add()
{
    Service s;
    
    Product p(1, "Dorna", 6);
    
    s.add_product(1, "Dorna", 6);
    
    assert(s.get_size() == 1);
    assert(s.get_all()[0] == p);
}

void test_s_delete()
{
    Service s;
    
    Product p(1, "Dorna", 6);
    s.add_product(1, "Dorna", 6);
    
    s.delete_product(p);
    
    assert(s.get_size() == 0);
}

void test_s_update()
{
    Service s;
    
    Product p(1, "Dorna", 6);
    
    s.add_product(1, "Dorna", 6);
    s.add_product(2, "Milka", 8);
    s.add_product(3, "Jacobs", 5);
    s.add_product(4, "KitKat", 7);
    s.update_product(2, 3, "Illy", 7);
    
    assert(s.get_all()[2].get_name() == "Illy");
    assert(s.get_all()[2].get_price() == 7);
}

void test_service()
{
    test_s_add();
    test_s_update();
    test_s_delete();
}
*/
