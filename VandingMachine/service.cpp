//
//  service.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "service.hpp"

Service::Service()
{
}

Service::Service(RepoFile<Product> &repo, Money money)
{
    this->repo = repo;
    this->money = money;
}

Service::~Service()
{
    
}

long Service::get_size_repo()
{
    return this->repo.get_size();
}

vector<Product> Service::get_all()
{
    return this->repo.get_all();
}

void Service::add_product(int code, string name, int price)
{
    Product p(code, name, price);
    this->repo.add_product(p);
}

void Service::update_product_by_code(int code, string n_name, int n_price)
{
    Product p(code, n_name, n_price);
    this->repo.update_product_by_code(p, code);
}

void Service::delete_product_by_code(int code)
{
    this->repo.delete_product_by_code(code);
}

Product Service::get_product_by_code(int code)
{
    return this->repo.get_product_by_code(code);
}

void Service::save_to_file_product()
{
    this->repo.save_to_file();
}

void Service::save_to_file_money(int no_1_ron, int no_5_ron, int no_10_ron)
{
    this->money.set_no_1_ron(this->money.get_no_1_ron() + no_1_ron);
    this->money.set_no_5_ron(this->money.get_no_5_ron() + no_5_ron);
    this->money.set_no_10_ron(this->money.get_no_10_ron() + no_10_ron);
    this->money.save_to_file_money();
}

void Service::buy_product(int code, int &input_sum)
{
    int product_price = 0;
    for (int i = 0; i < this->repo.get_size(); i++)
        if (this->repo.get_all()[i].get_code() == code)
        {
            product_price = this->repo.get_all()[i].get_price();
            break;
        }
    if (input_sum >= product_price)
        input_sum = input_sum - product_price;
    else
        cout << "                                                  You don't have enough money to buy this product." << endl;
}

void Service::get_money()
{
    cout << "                                                            1 RON   X   " << this->money.get_no_1_ron() << endl;
    cout << "                                                            5 RON   X   " << this->money.get_no_5_ron() << endl;
    cout << "                                                            10 RON  X   " << this->money.get_no_10_ron() << endl;
}

void Service::get_change(int &input_sum)
{
    int copy = input_sum;
    int n_1 = 0, n_5 = 0, n_10 = 0;
    while (input_sum != 0)
    {
        if ((input_sum >= 10) && (n_10 < this->money.get_no_10_ron()))
        {
            n_10++;
            input_sum -= 10;
        }
        else if ((input_sum >= 5) && (n_5 < this->money.get_no_5_ron()))
        {
            n_5++;
            input_sum -= 5;
        }
        else if ((input_sum >= 1) && (n_1 < this->money.get_no_1_ron()))
        {
            n_1++;
            input_sum -= 1;
        }
        else if (input_sum > 0)
        {
            cout << "                                                            Don't have money for change." << endl;
            input_sum = copy;
            return;
        }
    }
    this->save_to_file_money(-n_1, -n_5, -n_10);
}
