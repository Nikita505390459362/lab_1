#ifndef POSITIVE_HERO_H
#define POSITIVE_HERO_H

#include "Hero.h"
#include <iostream>

class PositiveHero : public Hero {
public:
    PositiveHero(const std::string& name, const std::string& weaponType, const std::vector<std::string>& skills)
            : Hero(name, weaponType, skills) {}

    void printInfo() const override {
        std::cout << "Positive Hero: " << name << "\nWeapon: " << weaponType << "\nSkills: ";
        for (const auto& skill : skills) {
            std::cout << skill << " ";
        }
        std::cout << std::endl;
    }
};

#endif // POSITIVE_HERO_H
