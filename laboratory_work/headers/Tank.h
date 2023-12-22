#ifndef TANK_H
#define TANK_H
#include "player.h"

class Tank : public Player {
    int armor{110};
    int grenade{3};
    public:
        Tank() {
            health = 175;
            damage = 70;
        }
        void passive_ability();
        void active_ability();
};

#endif // TANK_H