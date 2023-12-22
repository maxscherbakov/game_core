#ifndef PLAYER_H
#define PLAYER_H
#include "objects.h"

class Player : public Man {
    protected:
        int money{100};
        int damage{0};
        std:: vector <std:: string> inventory{};
    public:
        int x{0};
        int y{0};
        virtual void passive_ability() {};
        virtual void active_ability() {};
        void take_from_chest(Object *, std:: string);
        void put_in_chest(Object *, std:: string);
        void trade_whith(NPC_trader *);
        bool near_with(Object *);
        void attack(Enemy *);
        void check_inventory();
};

#endif // PLAYER_H