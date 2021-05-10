//
//  testRepo.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//
#include "testRepo.hpp"
#include "product.hpp"
#include "repoFile.hpp"
#include "repo.hpp"
#include <stdio.h>
#include <ctime>
#include <vector>
#include <string>

void test_load_from_file()
{
    Product p1(1, "milka", 3.5);
    Product p2(2, "pufuleti", 2);
    Product p3(3, "apa", 2.5);
    Product p4(4, "mar", 1);
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);

    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();
    for (int i = 0; i < repo.get_size(); i++)
        assert(repo.get_all()[i] == products[i]);
}

void test_save_to_file()
{
    Product p1(1, "milka", 3.5);
    Product p2(2, "pufuleti", 2);
    Product p3(3, "apa", 2.5);
    Product p4(4, "mar", 1);
    Product p5(5, "aer", 100);
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);
    products.push_back(p5);

    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();
    long initial_len = repo.get_size();
    Product p(5, "aer", 100);
    repo.add_product(p);
    repo.save_to_file();
    repo.load_from_file();
    for(int i = 0; i < initial_len + 1; i++)
        assert(repo.get_all()[i] == products[i]);
    repo.delete_product_by_code(5);
    repo.save_to_file();
}

void test_add_product()
{
    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();
    long initial_len = repo.get_size();
    Product p(5, "aer", 100);
    repo.add_product(p);

    assert(repo.get_all()[initial_len].get_code() == 5);
    assert(repo.get_all()[initial_len].get_name() == "aer");
    assert(abs(repo.get_all()[initial_len].get_price()-100) < 0.0001);

    repo.delete_product_by_code(5);
    repo.save_to_file();
}

void test_get_all()
{
    Product p1(1, "milka", 3.5);
    Product p2(2, "pufuleti", 2);
    Product p3(3, "apa", 2.5);
    Product p4(4, "mar", 1);
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);

    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();
    for (int i = 0; i < repo.get_size(); i++)
        assert(repo.get_all()[i] == products[i]);
}

void test_get_size()
{
    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();

    assert(repo.get_size() == 4);
}

void test_delete_by_code()
{
    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();
    long initial_len = repo.get_size();
    repo.delete_product_by_code(4);

    assert(repo.get_size() == initial_len - 1);
    assert(repo.get_all()[initial_len - 2].get_code() == 3);

    Product p4(4, "mar", 1);
    repo.add_product(p4);
    repo.save_to_file();
}

void test_update_by_code()
{
    RepoFile<Product> repo;
    repo.set_file("products_test.txt");
    repo.load_from_file();
    Product p1(2, "capsuni", 10);
    Product p2(2, "pufuleti", 2);
    repo.update_product_by_code(p1, 2);

    assert(repo.get_product_by_code(2) == p1);

    repo.update_product_by_code(p2, 2);
    repo.save_to_file();
}

void test_repo()
{
    test_load_from_file();
    test_save_to_file();
    test_get_size();
    test_get_all();
    test_add_product();
    test_delete_by_code();
    test_update_by_code();
}

