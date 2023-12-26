#include "map.h"

bool Map:: check_coordinates(int x, int y) {
    if (x < 20 && x >= 0 && y < 20 && y >= 0 \
    && map[y][x] == ' ') return 1;
    return 0;
}

void Map:: add_building(std:: string loc_name, int x, int y) {
    if (check_coordinates(x, y)) {
        map[y][x] = 'b';
        map_obj[y][x] = new Build(loc_name, x, y);
    } else {
        std:: cout << "Это место занято.\n";
    }
}

void Map:: add_chest(std:: string loc_name, int x, int y) {
    if (check_coordinates(x, y)) {
        map[y][x] = 'c';
        map_obj[y][x] = new Chest(loc_name, x, y);
    } else {
        std:: cout << "Это место занято.\n";
    }
}

void Map:: add_arena(std:: string loc_name, int x, int y) {
    if (check_coordinates(x, y)) {
        map[y][x] = 'a';
        map_obj[y][x] = new Arena(loc_name, x, y);
    } else {
        std:: cout << "Это место занято.\n";
    }
}

void Map:: screen() {
    for (int i = 0; i < 30; ++i) { std:: cout << std:: endl; }
    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < 20; ++i) {
            if (map[j][i] != ' ') {
                std:: cout << map[j][i];
            } else {
                std:: cout << ' ';
            }
        }
        std:: cout << "|" << std:: endl;
    }
}

void Map:: clear_map() {
    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < 20; ++i) {
            map[j][i] = ' ';
        }
    }
    map[0][0] = 'p';
}

void Map:: go_to(int x_, int y_) {
    if (check_coordinates(x_, y_)) {
        map[player->y][player->x] = ' ';
        map[y_][x_] = 'p';
        player->x = x_;
        player->y = y_;
    }
}


void Map:: object_set(std:: string str1_, std:: string str2_, std:: string str3_, int int1_, int x, int y) {
    map_obj[y][x]->add(str1_, str2_, str3_, int1_);
}

Object * Map:: search_obj(char obj) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (map[player->y + j][player->x + i] == obj) return map_obj[player->y + j][player->x + i];
        }
    }
    return 0;
}

void Map:: chest_do() {
    std:: string move;
    Object * chest = search_obj('c');
    if (chest != 0) {
        std:: cout << "Chest is open. (put/take)\n";
        chest->scan_obj();
        std:: cin >> move;
        if (move == "put") {
            std:: cout << "Is item?\n";
            std:: cin >> move;
            player->put_in_chest(chest, move);
        } else if (move == "take") {
            std:: cout << "Is item?\n";
            std:: cin >> move;
            player->take_from_chest(chest, move);
        }
    } else {
        std:: cout << "Chest not found.\n";
    }
}

void Map:: building_do() {
    std:: string move;
    Object * building = search_obj('b');
    if (building != 0) {
        std:: cout << "You entered the building. (say/trade)\n";
        building->scan_obj();
        std:: cin >> move;
        if (move == "say") {
            std:: cout << "With whom?\n";
            std:: cin >> move;
            NPC * npc = building->search_npc(move);
            if (npc != 0) {
                std:: cout << npc->get_phrase();
            } else {
                std:: cout << "NPC not found.\n";
            }
        } else if (move == "trade") {
            std:: cout << "With whom?\n";
            std:: cin >> move;
            NPC_trader * trader = building->search_trader(move);
            if (trader != 0) {
                player->trade_whith(trader);
            } else {
                std:: cout << "Trader not found.\n";
            }
        }
    } else {
        std:: cout << "Build not found.\n";
    }
}

void Map:: arena_do() {
    std:: string move;
    Object * arena = search_obj('a');
    if (arena != 0) {
        std:: cout << "You entered the arena. (fight)\n";
        arena->scan_obj();
        std:: cin >> move;
        if (move == "fight") {
            std:: cout << "With whom?\n";
            std:: cin >> move;
            Enemy * enemy = arena->search_enemy(move);
            if (enemy != 0) {
                player->attack(enemy);
            } else {
                std:: cout << "Enemy not found.\n";
            }
        }
    } else {
        std:: cout << "Arena not Found.\n";
    }
}