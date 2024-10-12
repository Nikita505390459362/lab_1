#ifndef KEEPER_H
#define KEEPER_H

#include "Hero.h"
#include <memory>
#include <string>

class Keeper {
private:
    std::unique_ptr<std::unique_ptr<Hero>[]> heroes;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    Keeper();
    ~Keeper();

    void addHero(std::unique_ptr<Hero> hero);
    void removeHero(size_t index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void printAllHeroes() const;
};

#endif // KEEPER_H

