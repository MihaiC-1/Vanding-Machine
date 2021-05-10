//
//  main.cpp
//  Lab_6
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <iostream>

#include "testProduct.hpp"
#include "testRepo.hpp"
#include "testService.hpp"
#include "UI.hpp"

using namespace std;

int main() {
    test_product();
    //test_repo_all();
    //test_service();
    
    RepoFile<Product> repo("products.txt");
    Money money("money.txt");
    Service serv(repo, money);
    UI u(serv);
    u.run_UI();
    
    return 0;
}
