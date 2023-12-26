#include "map.h"
#include <iostream>
using namespace std;

enum Move {
    RIGHT = 1, LEFT = 2, DOWN = 3, UP = 4, 
    CHEST = 5, BUILDING = 6, ARENA = 7,
    INVENTORY = 8
};

void create_object(Map * map) {
    map->clear_map();
    map->add_arena("Arena1", 4, 4);
    map->add_chest("Chest1", 1, 3);
    map->add_building("Tavern1", 5, 1);
    map->object_set("helmet", "", "", 0, 1, 3);
    map->object_set("amulet", "", "", 0, 1, 3);
    map->object_set("Trader1", "Bottle beer = 10 cent", "Bottle beer", 10, 5, 1);
    map->object_set("Enemy1", "I'll kill you.", "reward1", 20, 4, 4);
}

int main() {
    Map world;
    create_object(&world);
    world.player = 0;
    int move;
    cout << "Select a class.\n1 - tank\n2 - soldier\n";
    cin >> move;
    if (move == 1) world.player = new Tank;
    else if (move == 2) world.player = new Soldier;
    else return 0;
    while (true) {
        world.screen();
        cin >> move;
        switch ( move ) {
        case RIGHT:
            world.go_to((world.player->x) + 1, world.player->y); 
            break;
        case LEFT:
            world.go_to(world.player->x-1, world.player->y); 
            break;
        case UP:
            world.go_to(world.player->x, world.player->y-1);
            break;
        case DOWN: 
            world.go_to(world.player->x, world.player->y+1);
            break;
        case CHEST:
            world.chest_do();
            break;
        case BUILDING: 
            world.building_do();
            break;
        case ARENA:
            world.arena_do();
            break;
        case INVENTORY:
            world.player->check_inventory();
            break;
        default:
            cout << "Number not found.\n";
            break;
        }


    }
}