//
//  UI.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "UI.hpp"

using namespace std;

UI::UI()
{
    
}

UI::UI(Service serv)
{
    this->serv = serv;
}

UI::~UI()
{
    
}

void UI::display_menu()
{
    cout << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    cout << "                                 |                                 MENU                                         |" << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    cout << "                                                              0. Exit." << endl;
    cout << "                                                              1. Add product." << endl;
    cout << "                                                              2. Update product." << endl;
    cout << "                                                              3. Delete product." << endl;
    cout << "                                                              4. Display products." << endl;
    cout << "                                                              5. Buy product." << endl;
    cout << "                                                              6. Show money." << endl;
    cout << "                                 Pick an option : ";
}

void UI::add()
{
    int code, price;
    string name;
    cout << "Code of product = ";
    cin >> code;
    cout << "Name of product = ";
    cin >> name;
    cout << "Price of product = ";
    cin >> price;
    this->serv.add_product(code, name, price);
    this->serv.save_to_file_product();
}

void UI::update()
{
    int code;
    cout << "What code has the product you want to update? : ";
    cin >> code;
    int n_price;
    string n_name;
    cout << "New name of product = ";
    cin >> n_name;
    cout << "New price of product = ";
    cin >> n_price;
    this->serv.update_product_by_code(code, n_name, n_price);
    this->serv.save_to_file_product();
}

void UI::_delete()
{
    cout << "Write the product code you want to delete! " << endl;
    int code;
    cout << "Code of product = ";
    cin >> code;
    this->serv.delete_product_by_code(code);
    this->serv.save_to_file_product();
}

void UI::display()
{
    cout << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    cout << "                                 |                                 PRODUCTS                                     |" << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->serv.get_size_repo(); i++)
    {
        cout << "                                                      CODE : " << this->serv.get_all()[i].get_code() << " -- " << this->serv.get_all()[i].get_name() << " -- " << this->serv.get_all()[i].get_price() << " RON " << endl;
    }
}

void UI::show_money()
{
    cout << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    cout << "                                 |                                 MONEY                                        |" << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    this->serv.get_money();
}

void UI::buy_product()
{
    cout << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    cout << "                                 |                               Insert Money                                   |" << endl;
    cout << "                                 --------------------------------------------------------------------------------" << endl;
    int input_sum, no_10, no_5, no_1;
    cout << "                                                            How many of 10 RON :  ";
    cin >> no_10;
    cout << "                                                            How many of 5 RON :   ";
    cin >> no_5;
    cout << "                                                            How many of 1 RON :   ";
    cin >> no_1;
    this->serv.save_to_file_money(no_1, no_5, no_10);
    input_sum = no_1 * 1 + no_5 * 5 + no_10 * 10;
    while (input_sum != 0)
    {
        int code;
        this->display();
        cout << endl;
        cout << "                                 --------------------------------------------------------------------------------" << endl;
        cout << "                                 |                     What product do you want to buy ?                        |" << endl;
        cout << "                                 |                   Or you can take the rest with code 0.                      |" << endl;
        cout << "                                 --------------------------------------------------------------------------------" << endl;
        cout << "                                                              CODE =  ";
        cin >> code;
        cout << endl;
        if (code != 0)
        {
            this->serv.buy_product(code, input_sum);
            cout << "        Money left = " << input_sum << endl;
        }
        else
        {
            this->serv.get_change(input_sum);
            cout << "        Money left = " << input_sum << endl;
        }
    }
}

void UI::run_UI()
{
    bool ok = true;
    while (ok)
    {
        int op = 0;
        this->display_menu();
        cin >> op;
        switch (op) {
            case 0:
                ok = false;
                break;
            case 1:
                this->add();
                break;
            case 2:
                this->update();
                break;
            case 3:
                this->_delete();
                break;
            case 4:
                this->display();
                break;
            case 5:
                this->buy_product();
                break;
            case 6:
                this->show_money();
                break;
            default:
                cout << "Not an option!!" << endl;
                break;
        }
    }
}
