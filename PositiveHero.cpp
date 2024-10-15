#include "PositiveHero.h"
#include <iostream>


PositiveHero::PositiveHero(const std::string& name, const std::string& weaponType, const std::vector<std::string>& skills)
        : Hero(name, weaponType, skills) {}


void PositiveHero::printInfo() const {
    std::cout << "Positive Hero: " << name << "\nWeapon: " << weaponType << "\nSkills: ";
    for (const auto& skill : skills) {
        std::cout << skill << " ";
    }
    std::cout << std::endl;
}
