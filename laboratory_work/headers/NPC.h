#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>

class Man {
    protected:
        std:: string name;
        int health{100};

};

class NPC : public Man {
    std:: string phrase;
    public:
        NPC (std:: string name_, std:: string phrase_) {
            name = name_;
            phrase = phrase_;
        }
        int get_health() {return health; }
        std:: string get_phrase() { return phrase; }
        std:: string get_name() { return name; }
};

class NPC_trader : public NPC {
    std:: string product;
    int cost;
    public:
        NPC_trader (std:: string name_, std:: string phrase_, std:: string product_, int cost_) :
            NPC(name_, phrase_),
            product(product_),
            cost(cost_)
        {}
        std:: string get_product() { return product; }
        int get_cost() { return cost; }
};

#endif // NPC_H