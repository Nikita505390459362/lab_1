#include "Keeper.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() : size(0), capacity(2) {
    heroes = std::make_unique<std::unique_ptr<Hero>[]>(capacity);
}

Keeper::~Keeper() {
}

void Keeper::resize(size_t newCapacity) {
    auto newHeroes = std::make_unique<std::unique_ptr<Hero>[]>(newCapacity);
    for (size_t i = 0; i < size; ++i) {
        newHeroes[i] = std::move(heroes[i]);
    }
    capacity = newCapacity;
    heroes = std::move(newHeroes);
}

void Keeper::addHero(std::unique_ptr<Hero> hero) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    heroes[size++] = std::move(hero);
}

void Keeper::removeHero(size_t index) {
    if (index < size) {
        for (size_t i = index; i < size - 1; ++i) {
            heroes[i] = std::move(heroes[i + 1]);
        }
        heroes[--size].reset();
    } else {
        std::cerr << "Index out of range" << std::endl;
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open file for writing" << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Failed to open file for reading" << std::endl;
        return;
    }

    size_t newSize;
    inFile.read(reinterpret_cast<char*>(&newSize), sizeof(newSize));
    resize(newSize);
    size = 0;

    for (size_t i = 0; i < newSize; ++i) {

    }
}

void Keeper::printAllHeroes() const {
    for (size_t i = 0; i < size; ++i) {
        heroes[i]->printInfo();
    }
}
