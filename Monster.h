#ifndef MONSTER_H
#define MONSTER_H

#include "Hero.h"
#include <iostream>

class Monster : public Hero {
private:
    std::string appearanceDescription;

public:
    Monster(const std::string& name, const std::string& appearanceDescription)
            : Hero(name, "", {}), appearanceDescription(appearanceDescription) {}

    void printInfo() const override {
        std::cout << "Monster: " << name << "\nAppearance: " << appearanceDescription << std::endl;
    }
};

#endif // MONSTER_H
