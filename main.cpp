#include <iostream>
#include "functions.h"

int main() {
    Player player;
    Enemy enemy;
    bool playerTurn = true;
    std::cout << "Hello, and welcome to my pve game project! It's your turn first." << std::endl;
    while (player.health > 0 || enemy.health > 0)
    {
        if (playerTurn) 
        {
            std::cout << "Pick an attack! (Swing: 1, Dice: 2, Parry: 3, )";
        }
    }
}