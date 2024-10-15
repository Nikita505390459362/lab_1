#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Keeper.h"
#include "PositiveHero.h"
#include "Monster.h"
#include "Villain.h"
#include "windows.h"

void printMenu() {
    std::cout << "Меню:\n";
    std::cout << "1. Добавить героя\n";
    std::cout << "2. Удалить героя\n";
    std::cout << "3. Показать всех героев\n";
    std::cout << "4. Сохранить в файл\n";
    std::cout << "5. Загрузить из файла\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите опцию: ";
}


std::unique_ptr<Hero> createHero() {
    int type;
    std::cout << "Выберите тип героя:\n";
    std::cout << "1. Положительный герой\n";
    std::cout << "2. Монстр\n";
    std::cout << "3. Злодей\n";
    std::cout << "Ваш выбор: ";
    std::cin >> type;

    std::string name;
    std::cout << "Введите имя героя: ";
    std::cin >> name;

    switch (type) {
        case 1: {
            std::string weaponType;
            std::vector<std::string> skills;
            std::string skill;
            int numSkills;

            std::cout << "Введите тип оружия: ";
            std::cin >> weaponType;
            std::cout << "Введите количество навыков: ";
            std::cin >> numSkills;

            for (int i = 0; i < numSkills; ++i) {
                std::cout << "Введите навык " << i + 1 << ": ";
                std::cin >> skill;
                skills.push_back(skill);
            }

            return std::make_unique<PositiveHero>(name, weaponType, skills);
        }
        case 2: {
            std::string appearanceDescription;
            std::cout << "Введите описание внешности монстра: ";
            std::cin.ignore();
            std::getline(std::cin, appearanceDescription);
            return std::make_unique<Monster>(name, appearanceDescription);
        }
        case 3: {
            std::string weaponType, crime, habitat;
            std::vector<std::string> skills;
            std::string skill;
            int numSkills;

            std::cout << "Введите тип оружия: ";
            std::cin >> weaponType;
            std::cout << "Введите количество навыков: ";
            std::cin >> numSkills;

            for (int i = 0; i < numSkills; ++i) {
                std::cout << "Введите навык " << i + 1 << ": ";
                std::cin >> skill;
                skills.push_back(skill);
            }

            std::cout << "Введите преступление: ";
            std::cin.ignore();
            std::getline(std::cin, crime);

            std::cout << "Введите место обитания: ";
            std::getline(std::cin, habitat);

            return std::make_unique<Villain>(name, weaponType, skills, crime, habitat);
        }
        default:
            std::cout << "Неверный тип героя. Герой не создан.\n";
            return nullptr;
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Keeper keeper;
    int choice;


    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                auto hero = createHero();
                if (hero) {
                    keeper.addHero(std::move(hero));
                } else {
                    std::cout << "Ошибка при создании героя\n";
                }
                break;
            }
            case 2: {
                size_t index;
                std::cout << "Введите индекс героя для удаления: ";
                std::cin >> index;
                keeper.removeHero(index);
                break;
            }
            case 3: {
                keeper.printAllHeroes();
                break;
            }
            case 4: {
                std::string filename;
                std::cout << "Введите имя файла для сохранения: ";
                std::cin >> filename;
                keeper.saveToFile(filename);
                break;
            }
            case 5: {
                std::string filename;
                std::cout << "Введите имя файла для загрузки: ";
                std::cin >> filename;
                keeper.loadFromFile(filename);
                break;
            }
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

