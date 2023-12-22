#include "objects.h"
NPC * Object:: search_npc(std:: string) { return 0; }
NPC_trader * Object:: search_trader(std:: string) { return 0;}
Enemy * Object:: search_enemy(std:: string) { return 0; }
void Chest:: add(std:: string item_, std:: string, std:: string, int) {
    chest_list.push_back(item_);
}

bool Chest:: drop(std:: string item) {
    for (int i = 0; i < chest_list.size(); ++i) {
        if (chest_list[i] == item) {
            chest_list.erase(chest_list.begin()+i);
            return 1;
        }
    }
    return 0;

}

void Chest:: scan_obj() {
    std:: cout << "Object: " << object_name << "\n";
    std:: cout << "Chest_list: ";
    for (auto i : chest_list) {
        std:: cout << i << " ";
    }
    std:: cout << '\n';
}

void Build:: add(std:: string name_, std:: string phrase_, std:: string product_, int cost_) {
    NPC_trader new_trader(name_, phrase_, product_, cost_);
    traders.push_back(new_trader);
}

void Build:: scan_obj() {
    std:: cout << "Object: " << object_name << "\n";
    std:: cout << "\nTraders in: ";
        for (auto i : traders) {
        std:: cout << i.get_name() << ": " << i.get_product() << " " << i.get_cost() << '\n';
    }
    std:: cout << "\n";
}

NPC_trader * Build:: search_trader(std:: string trader_name) {
    for (int i = 0; i < traders.size(); ++i) {
        if (traders[i].get_name() == trader_name) return &traders[i];
    }
    return 0;
}

NPC * Build:: search_npc(std:: string npc_name) {
    for (int i = 0; i < NPC_in.size(); ++i) {
        if (NPC_in[i].get_name() == npc_name) return &NPC_in[i];
    }
    return 0;
}

bool Build:: drop(std::string name_) {
    for (int i = 0; i < traders.size(); ++i) {
        if (traders[i].get_name() == name_) {
            traders.erase(traders.begin()+i);
            return 1;
        }
    }
    return 0;
}

void Arena:: add(std:: string name_, std:: string phrase_, std:: string reward, int damage) {
    Enemy new_enemy(name_, phrase_, reward, damage);
    enemies.push_back(new_enemy);
}

void Arena:: scan_obj() {
    std:: cout << "Object: " << object_name << "\n";
    std:: cout << "Enemies:\n";
    for (auto i : enemies) {
        std:: cout << "Name: " << i.get_name() << " health: " << i.get_health() << " Damage: " << i.get_damage();
        std:: cout << "\n";
    }
    std:: cout << '\n';
}

Enemy * Arena:: search_enemy(std:: string enemy_name) {
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i].get_name() == enemy_name) return &enemies[i];
    }
    return 0;
}

bool Arena:: drop(std::string enemy_name) {
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i].get_name() == enemy_name) {
            enemies.erase(enemies.begin()+i);
            return 1;
        }
    }
    return 0;
}

