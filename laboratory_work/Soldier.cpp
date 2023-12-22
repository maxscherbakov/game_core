#include "Soldier.h"
#include <iostream>

void Soldier:: passive_ability() {
    if (num_shot == 2) {
        damage += 80;
    } else if (num_shot == 0) {
        damage = 100;
    }
    num_shot = (num_shot + 1) % 3;
}

void Soldier:: active_ability() {
    if (med_chest > 0) {
        med_chest -= 1;
        health += 40;
    } else {
        std:: cout << "The first-aid kits are out.\n";
    }
}