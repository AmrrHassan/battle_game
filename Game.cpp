//
// Created by Amr Hafez on 2020-08-23.
//

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <ctype.h>
#include <vector>
#include <cmath>
#include "Game.h"

Game::Game() {

}

void Game::gameMenu() {

    string answer;

    while(true){
        cout << "** Welcome to Harry Potter VS Voldemort" << endl << endl;
        player1 = new Harry();
        player2 = new voldemort();
        fight();

        cout << "Would you like to play again? (Y/N)" << endl << endl;
        cin.ignore(256, '\n');
        getline(cin, answer);

        for (int i = 0; i < answer.length(); i++) {
            answer[i] = toupper(answer[i]);
        }

        while (answer != "Y" && answer != "N") {
            cout << "Invalid input. Please enter 'Y' to play again or 'N' to exit." << endl << endl;
            getline(cin, answer);
        }


        if (answer == "N") {
            cout << "Bye" << endl;
            break;
        }



    }

}

void Game::fight(){
    int round = 1;
    int damage1, damage2;

    string spell1, spell2;
    while(player1->getHealth() > 0 && player2->getHealth() > 0){
        int flag1 = 0;
        int flag2 = 0;
        int errors = 0;
        cout << "Harry Potter's spells:" << endl;
        for(auto elem : player1->spells)
        {
            cout << elem.first << ", ";
        }

        cout << endl <<  "Voldemort's spells: " << endl;
        for(auto elem : player2->spells)
        {
            cout << elem.first << ", ";
        }
        cout << endl;

        while(flag1 == 0 || flag2 == 0) {
            if (errors > 0){
                cout << "Wrong input, please check your wand and try again..." << endl << endl;
            }
            cout << "Enter the two spells Harry then Voldemort:" << endl << endl;
            cin >> spell1 >> spell2;

//        check both spells

            for (auto itr = player1->spells.find(spell1); itr != player1->spells.end(); itr++) {
                if (itr->first == spell1) {
                    damage1 = itr->second;
                    flag1 = 1;
                    break;
                }

            }
            for (auto itr = player2->spells.find(spell2); itr != player2->spells.end(); itr++) {
                if (itr->first == spell2) {
                    damage2 = itr->second;
                    flag2 = 1;
                    break;
                }
            }
            if (damage1 == 0){
                int x =player1->checkShield();
                player1->setShield();
                if (x == 0){
                    flag1 = 0;
                    cout<< "No shield for Harry, try again" << endl;
                }

            }
            else if (damage2 == 0){
                int x =player2->checkShield();
                player2->setShield();
                if (x == 0){
                    flag2 = 0;
                    cout<< "No shield for Voldemort, try again" << endl;
                }
            }
            errors++;
        }


        int totalDamage;
        totalDamage = abs(damage1 - damage2);
        player1->setEnergy(damage1);
        player2->setEnergy(damage2);
        if(damage1 != 0 && damage2 != 0){
            if (damage1 < damage2){
                player1->takeDamage(totalDamage);
            }
            else{
                player2->takeDamage(totalDamage);
            }
        }
        cout << "Round: "<< round << endl << endl;
        cout << "\t" << player1->getName() << "\t" << player2->getName() << "\t" << endl << endl;
        cout << "Health: " << player1->getHealth() << "\t \t \t" << player2->getHealth() << "\t" << endl << endl;
        cout << "Energy: " << player1->getEnergy() << "\t \t \t" << player2->getEnergy() << "\t" << endl << endl;
        round++;


    }
    if (player1->getHealth() <= 0 || player1->getEnergy()<=0){
        cout << "Voldemort Won"<<endl ;
    }
    else if (player2->getHealth() <= 0 || player2->getEnergy()<=0){
        cout << "Harry Won" << endl;
    }

}