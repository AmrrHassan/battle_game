//
// Created by Amr Hafez on 2020-08-23.
//

#include "voldemort.h"

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

voldemort::voldemort() : wizard::wizard() {
    name = "Lord Voldemort";
    spells.insert({"Taboo", 80});
    spells.insert({"Confringo", 55});
    spells.insert({"Expulso", 60});

}



