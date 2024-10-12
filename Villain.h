#ifndef VILLAIN_H
#define VILLAIN_H

#include "Hero.h"
#include <iostream>

class Villain : public Hero {
private:
    std::string crime;
    std::string habitat;

public:
    Villain(const std::string& name, const std::string& weaponType, const std::vector<std::string>& skills,
            const std::string& crime, const std::string& habitat)
            : Hero(name, weaponType, skills), crime(crime), habitat(habitat) {}

    void printInfo() const override {
        std::cout << "Villain: " << name << "\nWeapon: " << weaponType << "\nCrime: " << crime << "\nHabitat: " << habitat << "\nSkills: ";
        for (const auto& skill : skills) {
            std::cout << skill << " ";
        }
        std::cout << std::endl;
    }
};

#endif // VILLAIN_H

Найти еще