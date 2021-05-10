//
//  UI.hpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include "service.hpp"
#include <string>

class UI
{
private:
    Service serv;
    void display_menu();
    void add();
    void update();
    void _delete();
    void display();
    void buy_product();
    void show_money();
public:
    UI();
    UI(Service serv);
    ~UI();
    void run_UI();
};
