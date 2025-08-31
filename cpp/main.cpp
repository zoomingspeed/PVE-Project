#include <iostream>
#include "../include/functions.h"
#include <algorithm>
#include <random>
#include <typeinfo>

int main() {
    Player player;
    Enemy enemy;
    bool playerTurn = true;
    bool gameRunning = true;
    int playerInput;
    std::string attackList[4] = {
                            "Swing",
                            "Dice",
                            "Parry",
                            "Slice"
                        };
    std::cout << "Hello, and welcome to my player versus enemy game project!" << std::endl;
    while (gameRunning)
    {
        if (playerTurn) 
        {
            std::cout << "Pick an attack! (Swing: 1, Dice: 2, Parry: 3, Slice: 4): ";
            std::cin >> playerInput;
            if (typeid(playerInput) == typeid(int) && playerInput < 5)
            {
                std::random_device random;
                std::mt19937 rng(random());
                std::uniform_real_distribution<float> numbers(1, 2);
                std::uniform_int_distribution<int> chance(1, 15);
                float randomDamageMultiplier = numbers(rng);
                int nothingHappens = chance(rng);
                int damage = player.SetDamage(PlayerStats::damage, PlayerStats::power, randomDamageMultiplier);
                if (nothingHappens == 1)
                {
                    std::cout << "You missed! Enemy turn." << std::endl;
                    playerTurn = false;
                }
                else 
                {
                    std::cout << "The enemy has been hit with: " << attackList[playerInput] << std::endl;
                    enemy.RemoveHealth(damage);
                    if (enemy.health <= 0) {gameRunning = false; std::cout << "Congratulations, you won the game!" << std::endl;}
                    playerTurn = false;
                }
            }
            else
            {
                std::cout << "That is not a valid integer! Try again." << std::endl;
            }
        }
        else
        {
            std::random_device rd;
            std::mt19937 rng(rd());
            std::uniform_int_distribution<int> attack(0, 3);
            std::uniform_int_distribution<int> missChance(1, 15);
            std::uniform_real_distribution<float> randomMultiplier(1, 2);
            int randomAttack = attack(rng);
            int missedAttack = missChance(rng);
            float randomDamageMultiplier = randomMultiplier(rng);
            int damage = enemy.SetDamage(EnemyStats::damage, EnemyStats::power, randomDamageMultiplier);
            if (missedAttack == 1)
            {
                std::cout << "You got lucky! The enemy missed. Your turn." << std::endl;
                playerTurn = true;
            }
            else
            {
                std::cout << "You have been hit with: " << attackList[randomAttack] << std::endl;
                player.RemoveHealth(damage);
                if (player.health <= 0) {gameRunning = false; std::cout << "Oh no! You lost. That's too bad." << std::endl;}
                playerTurn = true;
            }
        }
    }
}