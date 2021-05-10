//
//  repoFile.hpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include "repo.hpp"
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

template <class T> class RepoFile : public Repo <T>
{
private:
    string file_name;
public:
    RepoFile() : Repo<T>()
    {
        this->file_name = "";
    }
    
    RepoFile(string new_file_name)
    {
        this->file_name = new_file_name;
        this->load_from_file();
    }
    
    ~RepoFile()
    {
        
    }
    
    void set_file(string new_file_name)
    {
        this->file_name = new_file_name;
    }
    
    void load_from_file()
    {
        if (this->file_name != "")
        {
            this->products.clear();
            ifstream f;
            f.open(this->file_name);
            int code, price;
            string name;
            while (f >> code >> name >> price)
            {
                T prod(code, name, price);
                this->add_product(prod);
            }
            f.close();
        }
        else
        {
            cout << "File not exist!" << endl;
        }
    }
    
    void save_to_file()
    {
        if (this->file_name != "")
        {
            ofstream f(this->file_name);
            for (int i = 0; i < this->products.size(); i++)
            {
                f << this->products[i] << endl;
            }
            f.close();
        }
        else
        {
            cout << "File not exist!" << endl;
        }
    }
};
