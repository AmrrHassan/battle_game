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
    protected:
        int health = 100;
        int energy = 500;
        int shield = 3;
        string name;

    public:
        map<string, int> spells = {{"AvadaKedavra", 100}, {"Crucio", 40}, {"Imperio", 20}, {"shield", 0}};
        wizard();
        int getHealth(); // get wizard health
        void setShield();
        int checkShield();
        int getEnergy();
        void setEnergy(int energy);
        virtual void takeDamage(int damage);
        string getName();


};


#endif //TASK_2_WIZARD_H
