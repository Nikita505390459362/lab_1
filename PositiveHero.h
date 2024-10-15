#ifndef POSITIVE_HERO_H
#define POSITIVE_HERO_H

#include "Hero.h"
#include <vector>
#include <string>


class PositiveHero : public Hero {
public:
    PositiveHero(const std::string &name, const std::string &weaponType, const std::vector<std::string> &skills);

    void printInfo() const;
};

#endif