//
//  money.hpp
//  Lab_6
//
//  Created by Comsa Mihai on 16/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include "repo.hpp"

using namespace std;

class Money
{
private:
    string file_name_money;
    int no_1_ron;
    int no_5_ron;
    int no_10_ron;
public:
    Money()
    {
        this->file_name_money = "";
    }

    Money(string file_name_money)
    {
        this->file_name_money = file_name_money;
        this->load_from_file_money();
    }

    ~Money()
    {
        
    }

    void set_file_name_money(string file_name_money)
    {
        this->file_name_money = file_name_money;
    }

    void load_from_file_money()
    {
        if (this->file_name_money != "")
        {
            ifstream f(this->file_name_money);
            int no_money;
            int type_money = 0;
            while(f >> type_money >> no_money)
            {
                if (type_money == 1)
                    this->no_1_ron = no_money;
                else if (type_money == 5)
                    this->no_5_ron = no_money;
                else if (type_money == 10)
                    this->no_10_ron = no_money;
            }
        }
    }

    void save_to_file_money()
    {
        if (this->file_name_money != "")
        {
            ofstream f(this->file_name_money);
            f << 1 << " " << this->no_1_ron << endl;
            f << 5 << " " << this->no_5_ron << endl;
            f << 10 << " " << this->no_10_ron;
        }
    }

    int get_no_1_ron()
    {
        return this->no_1_ron;
    }

    int get_no_5_ron()
    {
        return this->no_5_ron;
    }

    int get_no_10_ron()
    {
        return this->no_10_ron;
    }

    void set_no_1_ron(int no_1_ron)
    {
        this->no_1_ron = no_1_ron;
    }

    void set_no_5_ron(int no_5_ron)
    {
        this->no_5_ron = no_5_ron;
    }

    void set_no_10_ron(int no_10_ron)
    {
        this->no_10_ron = no_10_ron;
    }
};
