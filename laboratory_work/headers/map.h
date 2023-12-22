#ifndef MAP_H
#define MAP_H
#include "Tank.h"
#include "Soldier.h"

class Map {
    char map[20][20];
    Object * map_obj[20][20];
    std:: vector <Build> buildings;
    std:: vector <Chest> chests;
    std:: vector <Arena> arenas;

    public:
        Player * player;
        bool check_coordinates(int, int);
        void add_building(std:: string, int, int);
        void add_chest(std:: string, int, int);
        void add_arena(std:: string, int, int);
        void go_to(int, int);
        void clear_map();
        void screen();
        Object * search_obj(char);
        void chest_do();
        void building_do();
        void arena_do();
        void object_set(std:: string, std:: string, std:: string, int, int, int);
};

#endif // MAP_H