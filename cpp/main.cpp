#include <iostream>
#include "../include/functions.h"
#include <algorithm>
#include <random>
#include <typeinfo>
#include <chrono>
#include <thread>

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
        std::random_device random;
        std::mt19937 rng(random());
        std::uniform_real_distribution<float> numbers(1, 2);
        std::uniform_int_distribution<int> chance(1, 15);
        std::uniform_int_distribution<int> attack(0, 3);
        float playerDamageMultiplier = numbers(rng);
        float enemyDamageMultiplier = numbers(rng);
        int nothingHappens = chance(rng);
        int playerDamage = player.SetDamage(PlayerStats::damage, PlayerStats::power, playerDamageMultiplier);
        int enemyDamage = enemy.SetDamage(EnemyStats::damage, EnemyStats::power, enemyDamageMultiplier);
        int enemyAttack = attack(rng);
        int missedAttack = chance(rng);
        if (playerTurn) 
        {
            std::cout << "Pick an attack! (Swing: 0, Dice: 1, Parry: 2, Slice: 3): ";
            std::cin >> playerInput;
            if (typeid(playerInput) == typeid(int) && playerInput < 4)
            {
                std::cout << "Rendering player attack..." << std::endl;
                std::this_thread::sleep_for (std::chrono::seconds(3));
                if (nothingHappens == 1)
                {
                    std::cout << "You missed! Enemy turn." << std::endl;
                    playerTurn = false;
                }
                else 
                {
                    if (playerInput == 2)
                    {
                        playerDamage = 0;
                    }
                    enemy.RemoveHealth(playerDamage);
                    std::cout << "The enemy has been hit with: " << attackList[playerInput] << std::endl;
                    if (enemy.health <= 0) {gameRunning = false; std::cout << "Congratulations, you won the game!" << std::endl;}
                    else {std::cout << "Enemy health: " << enemy.health << std::endl;}
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
            std::cout << "Rendering enemy attack..." << std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(3));
            if (missedAttack == 1)
            {
                std::cout << "You got lucky! The enemy missed. Your turn." << std::endl;
                playerTurn = true;
            }
            else
            {
                if (enemyAttack == 2 && playerInput == 2)
                {
                    enemyDamage = 0;
                    std::cout << "You both tried to parry an attack, and yet none of you attacked. No damage." << std::endl;
                }
                else if (enemyAttack == 2 && playerInput != 2)
                {
                    enemyDamage = 0;
                    playerDamageMultiplier = 0.5;
                }
                else if (playerInput == 2 && enemyAttack != 2)
                {
                    enemyDamageMultiplier = 0.5;
                }
                player.RemoveHealth(enemyDamage);
                std::cout << "You have been hit with: " << attackList[enemyAttack] << std::endl;
                if (player.health <= 0) {gameRunning = false; std::cout << "Your health is at 0. Oh well, you lost." << std::endl;} 
                else {std::cout << "Your new health: " << player.health << std::endl;}
                playerTurn = true;
            }
        }
    }
}