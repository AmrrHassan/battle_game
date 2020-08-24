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



//chang wizard's health

wizard::wizard(){

}

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

//get wizard's health

int wizard::getHealth(){
    return health;
}

void wizard::setEnergy(int newEnergy){
    energy -= newEnergy;
}

//get wizard's health

int wizard::getEnergy(){
    return energy;
}
