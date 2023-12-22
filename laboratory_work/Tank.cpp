#include "Tank.h"
#include <iostream>

void Tank:: passive_ability() {
    if (armor > 0) {
        if (175-health > armor) {
            health += armor;
            armor = 0;
        } else {
            armor -= (175-health);
            health = 175;
        }
    }
}

void Tank:: active_ability() {
    if (grenade > 0) {
        damage += 30;
        grenade -= 1;
    } else {
        std:: cout << "The grenades ran out.\n";
    }
}
