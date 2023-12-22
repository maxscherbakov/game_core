#include "player.h"

bool Player:: near_with(Object * object) {
    return ((abs(x - object->get_x()) <= 1 || abs(y - object->get_y()) <= 1));
}

void Player:: take_from_chest(Object * chest, std:: string item) {
    if (near_with(chest)) {
        if (chest->drop(item)) inventory.push_back(item);
        else std:: cout << "There is no such thing.\n";
    }
}

void Player:: put_in_chest(Object * chest, std:: string item) {
    if (near_with(chest)) {
        for (int i = 0; i < inventory.size(); ++i) {
            if (inventory[i] == item) {
                chest->add(item, "", "", 0);
                inventory.erase(inventory.begin()+i);
                return;
            }
        }
    }
}

void Player:: trade_whith(NPC_trader * trader) {
    if (money >= trader->get_cost()) {
        money -= trader->get_cost();
        inventory.push_back(trader->get_product());
    } else {
        std:: cout << "Недостаточно средств.\n";
    }
}

void Player:: attack(Enemy * enemy) {
    if (enemy->alive) {
        if (damage > enemy->get_health()) {
            std:: cout << enemy->get_name() << " убит.\n";
            inventory.push_back(enemy->get_reward());
            enemy->alive = 0;
        } else {
            std:: string move;
            enemy->reset_health((enemy->get_health() - damage));
            health -= enemy->get_damage();
            std:: cout << "Use ability? (yes/no)\n";
            std:: cin >> move;
            if (move == "yes") active_ability();
        }
        passive_ability();
    }
}

void Player:: check_inventory() {
    std:: cout << "Health: " << health << '\n';
    std:: cout << "Money: " << money << '\n';
    std:: cout << "Inventory: ";
    for (auto i : inventory) {
        std:: cout << i << " ";
    }
    std:: cout << "\n";
}