//
// Created by Amr Hafez on 2020-08-23.
//
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include "Harry.h"

using namespace std;

Harry::Harry() : wizard::wizard() {
    name = "Harry Potter";
    spells.insert({"Reducto", 60});
    spells.insert({"Fiendfyre", 50});
    spells.insert({"Nebulus", 40});


}


