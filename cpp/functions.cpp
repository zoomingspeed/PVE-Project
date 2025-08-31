#include "../include/functions.h"
#include <iostream>
#include "../include/constants.h"

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

int Character::SetDamage(int damage, float power, float randomMultiplier)
{
  int totalDamage = (damage * power) * randomMultiplier;
  this->damage = totalDamage;
  return totalDamage;
}

int Character::RemoveHealth(int health)
{
  int newHealth = this->health - health;
  this->health = newHealth;
  if (newHealth <= 0) {std::cout << "The new health is 0!" << std::endl;} else {std::cout << "The new health is: " << newHealth << std::endl;}
  return newHealth;
}