#ifndef ENEMY_H
#define ENEMy_H
#include "NPC.h"

class Enemy : public NPC {
    std:: string reward;
    int damage{10};
    public:
        Enemy(std:: string name_, std:: string phrase_, std:: string rew, int dam) :
            NPC(name_, phrase_), reward(rew), damage(dam)
        {}
        int get_damage() { return damage; }
        std::string get_reward() { return reward; }
        void reset_health(int health_) { health = health_; }
        bool alive{1};
};

#endif // ENEMY_H