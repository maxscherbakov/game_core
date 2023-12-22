#ifndef SOLDIER_H
#define SOLDIER_H
#include "player.h"

class Soldier : public Player {
    int num_shot{0};
    int med_chest{3};
    public:
        Soldier() {
            health = 100;
            damage = 100;
        }
        void passive_ability();
        void active_ability();
};

#endif // SOLDIER_H