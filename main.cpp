#include <iostream>
#include <memory>
#include "Keeper.h"
#include "Hero.h"

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
    return nullptr;
}

int main() {
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

