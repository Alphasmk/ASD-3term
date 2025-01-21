#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

vector<int> generate_boxes() {
    vector<int> boxes(100);
    for (int i = 0; i < 100; ++i) {
        boxes[i] = i + 1; 
    }
    shuffle(boxes.begin(), boxes.end(), mt19937(random_device{}()));
    return boxes;
}

bool random_choice(vector<int>& boxes, int prisoner_number) {
    vector<int> opened_boxes(100, 0);
    int attempts = 0;

    while (attempts < 50) {
        int choice = rand() % 100;
        if (!opened_boxes[choice]) { 
            opened_boxes[choice] = 1;
            if (boxes[choice] == prisoner_number) {
                return true;
            }
            ++attempts;
        }
    }
    return false;
}

bool loop_algorithm(vector<int>& boxes, int prisoner_number) {
    int attempts = 0;
    int current_box = prisoner_number - 1;

    while (attempts < 50) {
        if (boxes[current_box] == prisoner_number) {
            return true;
        }
        current_box = boxes[current_box] - 1;
        ++attempts;
    }
    return false; 
}

void оценка(int rounds) {
    int random_success = 0;
    int loop_success = 0;

    for (int i = 0; i < rounds; ++i) {
        vector<int> boxes = generate_boxes();
        bool all_random_success = true;
        bool all_loop_success = true;

        for (int prisoner = 1; prisoner <= 100; ++prisoner) {
            if (!random_choice(boxes, prisoner)) {
                all_random_success = false;
            }
            if (!loop_algorithm(boxes, prisoner)) {
                all_loop_success = false;
            }
        }

        if (all_random_success) {
            ++random_success;
        }
        if (all_loop_success) {
            ++loop_success;
        }
    }

    cout << "\nПодсчет успешных раундов:" << endl;
    cout << "1. Случайный выбор: " << random_success << " из " << rounds << endl;
    cout << "2. Алгоритм цикла: " << loop_success << " из " << rounds << endl;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    srand(time(0));
    int rounds;
    cout << "Введите количество раундов: ";
    cin >> rounds;

    оценка(rounds);
    return 0;
}
