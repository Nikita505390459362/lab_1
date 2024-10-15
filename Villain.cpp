#include "Villain.h"
#include <iostream>


Villain::Villain(const std::string& name, const std::string& weaponType, const std::vector<std::string>& skills,
                 const std::string& crime, const std::string& habitat)
        : Hero(name, weaponType, skills), crime(crime), habitat(habitat) {}


void Villain::printInfo() const {
    std::cout << "Villain: " << name << "\nWeapon: " << weaponType << "\nCrime: " << crime << "\nHabitat: " << habitat << "\nSkills: ";
    for (const auto& skill : skills) {
        std::cout << skill << " ";
    }
    std::cout << std::endl;
}
