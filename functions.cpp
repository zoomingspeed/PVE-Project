#include "functions.h"
#include <iostream>
#include "constants.h"

Character::Character(int health, int damage, float power)
  : health(health),
    damage(damage),
    power(power)

{
  // normally, variables would go here, but since theres nothing to configure, I just leave it empty
}          


Player::Player() 
  : Character(PlayerStats::health,
              PlayerStats::damage,
              PlayerStats::power)
{

}
    
Enemy::Enemy()
  : Character(EnemyStats::health,
              EnemyStats::damage,
              EnemyStats::power)
{
  // normally, variables would go here, but since theres nothing to configure, I just leave it empty
}

void Character::Attack(AttackType attack)
{
  int attackNumber;
  switch (attack) {
    case AttackType::swing:
      int attackNumber = AttackType::swing;
    case AttackType::dice:
      int attackNumber = AttackType::dice;
    case AttackType::parry:
      int attackNumber = AttackType::parry;
    case AttackType::slice:
      int attackNumber = AttackType::slice;
    default:
      int attackNumber = 0;
  }
}

int Character::RemoveHealth(int health)
{
  int healthRemoved;
  int newHealth = health - healthRemoved;
  this->health = newHealth;
}