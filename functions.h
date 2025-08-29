#pragma once
#include <iostream>
#include "constants.h"

class Character
{
public:
    int health;
    float power;
    int damage;

    enum AttackType {
        swing = 1,
        dice = 2,
        parry = 3,
        slice = 4
    };
    
    void Attack(AttackType attack);
    int SetDamage(int weapon, int damage, float power);
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