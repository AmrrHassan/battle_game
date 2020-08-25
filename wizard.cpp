//
// Created by Amr Hafez on 2020-08-23.
//

#include "wizard.h"
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

//Functions explanation in wizard.h file

// initialize wizard
wizard::wizard(){

}
// get wizard's name
string wizard::getName() {
    return name;
}

void wizard::setShield(){
    shield--;
}

int wizard::checkShield(){
    return shield;
}

void wizard::takeDamage(int damage) {
    health-=damage;
}


int wizard::getHealth(){
    return health;
}

void wizard::setEnergy(int newEnergy){
    energy -= newEnergy;
}


int wizard::getEnergy(){
    return energy;
}
