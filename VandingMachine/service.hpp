//
//  service.hpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include "repoFile.hpp"
#include "product.hpp"
#include "money.hpp"
#include <vector>
#include <string>

class Service
{
private:
    RepoFile<Product> repo;
    Money money;
public:
    Service();
    Service(RepoFile<Product>& repo, Money money);
    ~Service();
    long get_size_repo();
    vector<Product> get_all();
    void add_product(int code, string name, int price);
    void update_product_by_code(int code, string n_name, int n_price);
    void delete_product_by_code(int code);
    Product get_product_by_code(int code);
    
    void save_to_file_product();
    
    void save_to_file_money(int no_1_ron, int no_5_ron, int no_10_ron);
    void get_money();
    void buy_product(int code, int& input_sum);
    void get_change(int& input_sum);
};
