//
//  repoFile.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 06/04/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//
/*
#include "repoFile.hpp"
#include <fstream>
#include <string>

using namespace std;

RepoFile::RepoFile()
{
    this->file_in = "";
    this->file_out = "";
}

RepoFile::RepoFile(string new_file_in, string new_file_out)
{
    this->file_in = new_file_in;
    this->file_out = new_file_out;
    this->load_from_file();
}

RepoFile::~RepoFile()
{
    this->repo.~Repo();
}

void RepoFile::set_file_in(string n_file_in)
{
    this->file_in = n_file_in;
}

void RepoFile::set_file_out(string n_file_out)
{
    this->file_out = n_file_out;
}

void RepoFile::load_from_file()
{
    if(this->file_in != "")
    {
        this->repo.~Repo();
        ifstream f(this->file_in);
        int code, price;
        string name;
        while (! f.eof())
        {
            f >> code >> name >> price;
            this->repo.add_product(Product(code, name, price));
        }
        f.close();
    }
}

void RepoFile::save_to_file()
{
    if (this->file_out != "")
    {
        ofstream f(this->file_out);
        for (int i = 0; i < this->repo.get_size(); i++)
        {
            f << this->repo.get_all()[i] << endl;
        }
        f.close();
    }
}
*/
