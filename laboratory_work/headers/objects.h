#ifndef OBJECTS_H
#define OBJECTS_H

#include "NPC.h"
#include "enemy.h"

class Object {
    protected:
        Object(std:: string obj_name, int x_, int y_) {
            object_name = obj_name;
            x = x_; 
            y = y_;
        }
        std:: string object_name;
        int x;
        int y;
    public:
        int get_x() { return x; };
        int get_y() { return y; };
        virtual void scan_obj() = 0;
        virtual NPC * search_npc(std:: string);
        virtual NPC_trader * search_trader(std:: string);
        virtual Enemy * search_enemy(std:: string);
        virtual bool drop(std:: string) = 0;
        virtual void add(std:: string, std:: string, std:: string, int) = 0;
};

class Chest : public Object {
    std:: vector <std:: string> chest_list{};
    public:
        Chest(std:: string obj_name, int x_, int y_) : 
            Object(obj_name, x_, y_)
        {}
        void add(std::string, std:: string, std:: string, int);
        bool drop(std:: string);
        void scan_obj();
};

class Build : public Object {
    std:: vector <NPC> NPC_in{};
    std:: vector <NPC_trader> traders{};
    bool drop(std:: string);
    public:
        Build(std:: string obj_name, int x_, int y_) : 
        Object(obj_name, x_, y_)
        {}
        void add(std:: string, std:: string, std:: string, int);
        void scan_obj();
        NPC * search_npc(std:: string);
        NPC_trader * search_trader(std:: string);
};

class Arena : public Object {
    std:: vector <Enemy> enemies;
    bool drop(std:: string);
    public:
        Arena(std:: string obj_name, int x_, int y_) : 
        Object(obj_name, x_, y_)
        {}
        void add(std:: string, std:: string, std:: string, int);
        void scan_obj();
        Enemy * search_enemy(std:: string);
};

#endif // OBJECTS_H