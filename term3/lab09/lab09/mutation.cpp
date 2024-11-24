#include "mutation.h"
#include <random>

vector<int> mutate(vector<int> descendant, int chance) {
    static std::random_device rd;  // Источник случайности
    static std::mt19937 gen(rd()); // Генератор случайных чисел
    std::uniform_int_distribution<> dist(0, 99); // Для шанса мутации
    std::uniform_int_distribution<> indexDist(1, descendant.size() - 1); // Для индексов

    // Проверка шанса мутации
    if (dist(gen) < chance) {
        // Выбираем два разных индекса
        int index1 = indexDist(gen);
        int index2;
        do {
            index2 = indexDist(gen);
        } while (index1 == index2 || index1 == 0 || index2 == 0);

        // Выполняем обмен
        std::swap(descendant[index1], descendant[index2]);

        index1 = indexDist(gen);
        index2;
        do {
            index2 = indexDist(gen);
        } while (index1 == index2 || index1 == 0 || index2 == 0);

        // Выполняем обмен
        std::swap(descendant[index1], descendant[index2]);
    }

    return descendant;
}

