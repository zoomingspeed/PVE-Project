#pragma once
#include <iostream>
#include "../include/constants.h"

class Character
{
public:
    int health;
    float power;
    float randomMultiplier = 1;
    int damage;

    enum AttackType {
        swing,
        dice,
        parry,
        slice
    };
    
    void Attack(AttackType attack);
    int SetDamage(int damage, float power, float randomMultiplier);
    int RemoveHealth(int health);
    Character(int health, int damage, float power);
};

class Player : public Character
{
public:
    Player();
};

class Enemy : public Character
{
public: 
    Enemy();
};