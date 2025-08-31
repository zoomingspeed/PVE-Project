#pragma once
#include <iostream>

namespace PlayerStats {
    constexpr int health = 100;
    constexpr double power = 1.5;
    constexpr int sword = 10;
    constexpr int damage = sword + 5;
}

namespace EnemyStats {
    constexpr int health = 100;
    constexpr double power = 1.2;
    constexpr int dagger = 5;
    constexpr int damage = dagger + 5;
}