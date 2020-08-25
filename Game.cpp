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
// seperate lines function
void seperateLine(){
    for (int i = 0; i < 30; i++) {
        cout << "=";
    }
    cout << endl;
}

void Game::gameMenu() {

    string answer; // input for Y/N

    while(true){
        cout << "** Welcome to Harry Potter VS Voldemort" << endl << endl;
//        initialize new wizards
        player1 = new Harry();
        player2 = new voldemort();
//        start fight
        fight();

        cout << "Would you like to play again? (Y/N)" << endl << endl;
        cin.ignore(256, '\n');
//        get answer if player wants to play again
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
    while(player1->getHealth() > 0 && player2->getHealth() > 0 && player1->getEnergy()> 0 && player2->getEnergy() >0){ // exit loop when one of the players die
        int flag1 = 0;
        int flag2 = 0;
        int errors = 0;
        seperateLine();
        cout << "Harry Potter's spells:" << endl;
        for(auto elem : player1->spells)
        {
//            print harry's spells
            cout << elem.first << ", ";
        }
        cout<<endl;
        seperateLine();

        cout <<  "Voldemort's spells: " << endl;
        for(auto elem : player2->spells)
        {
//            print veoldemort's spells
            cout << elem.first << ", ";
        }
        cout << endl;
        seperateLine();

        while(flag1 == 0 || flag2 == 0) {
//            if spells input is wrong re-prompt user
            if (errors > 0){
                cout << "Wrong input, please check your wand and try again..." << endl << endl;
            }
            cout << "Enter the two spells Harry then Voldemort:" << endl << endl;
            cin >> spell1 >> spell2;



            for (auto itr = player1->spells.find(spell1); itr != player1->spells.end(); itr++) { // get the number of damage done by spell
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
            if (damage1 == 0){ // deduct one shield when used from player
                int x =player1->checkShield();
                player1->setShield();
//                if no shields available, alert player
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


        int totalDamage; // differance between both attacks ( spells )
        totalDamage = abs(damage1 - damage2);
        player1->setEnergy(damage1);
        player2->setEnergy(damage2);
//        deduct energy from both players based on spell used
        if(damage1 != 0 && damage2 != 0){
            if (damage1 < damage2){
                player1->takeDamage(totalDamage);
            }
            else{
                player2->takeDamage(totalDamage);
            }
        }
//        print results with round number
        seperateLine();
        cout << "Round: "<< round << endl << endl;
        cout << "\t" << player1->getName() << "\t" << player2->getName() << "\t" << endl << endl;
        cout << "Health: " << player1->getHealth() << "\t \t \t" << player2->getHealth() << "\t" << endl << endl;
        cout << "Energy: " << player1->getEnergy() << "\t \t \t" << player2->getEnergy() << "\t" << endl << endl;
        round++;



    }
//    declare the winner of the game
    if (player1->getHealth() <= 0 || player1->getEnergy()<=0){
        cout << "Voldemort Won"<<endl ;
    }
    else if (player2->getHealth() <= 0 || player2->getEnergy()<=0){
        cout << "Harry Won" << endl;
    }

}