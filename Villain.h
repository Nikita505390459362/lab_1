#ifndef VILLAIN_H
#define VILLAIN_H

#include "Hero.h"
#include <string>
#include <vector>


class Villain : public Hero {
private:
    std::string crime;

public:

    Villain(const std::string& name, const std::string& weaponType, const std::vector<std::string>& skills,
            const std::string& crime, const std::string& habitat);


    void printInfo() const override;

    const std::string &habitat;
};

#endif
