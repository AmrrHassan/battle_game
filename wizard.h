//
// Created by Amr Hafez on 2020-08-23.
//

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
#ifndef TASK_2_WIZARD_H
#define TASK_2_WIZARD_H


class wizard{
//    Parent class : wizard properties
    protected:
        int health = 100;
        int energy = 500;
        int shield = 3;
        string name;

    public:
//    wizard common spells associative array
        map<string, int> spells = {{"AvadaKedavra", 100}, {"Crucio", 40}, {"Imperio", 20}, {"shield", 0}};
//      new wizard fuction
        wizard();

        int getHealth(); // get wizard health
        void setShield(); // decrease number of shields by 1 function
        int checkShield(); // get wizard shield bum
        int getEnergy(); // get wizard energy
        void setEnergy(int energy); // decrease wizard energy
        virtual void takeDamage(int damage);
        string getName(); // receive damage wizard


};


#endif //TASK_2_WIZARD_H
