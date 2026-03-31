#include "Header.h"
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

void SolveArtifacts() {
    std::ifstream file("f.txt");

    // FIX_ME: Нет выхода при ошибке файла
    // if (!f.is_open()) cout << "Такого файла не существует";
    if (!file.is_open()) {
        std::cout << "Такого файла не существует\n";
        return;
    }

    int n, a, b;
    file >> n >> a >> b;
    if (!file || n <= 0 || a > b) {
        std::cout << "Некорректные параметры задачи\n";
        return;
    }

    // FIX_ME: Имена переменных не по Google Style (c, d)
    // vector<int> c(N), d(N);
    std::vector<int> weights(n);
    std::vector<int> volumes(n);

    //FIX_ME Не было проверки на входные данные
    for (int i = 0; i < n; i++) {
        if (!(file >> weights[i])) {
            std::cout << "Ошибка чтения весов\n";
            return;
        }
        if (weights[i] <= 0) {
            std::cout << "Некорректный вес артефакта №" << i + 1 << "\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!(file >> volumes[i])) {
            std::cout << "Ошибка чтения объёмов\n";
            return;
        }
        if (volumes[i] <= 0) {
            std::cout << "Некорректный объём артефакта №" << i + 1 << "\n";
            return;
        }
    }

    file.close();

    // FIX_ME: dp — ок, но Google Style требует snake_case
    // vector<int> dp(B + 1, INT_MAX);
    std::vector<int> dp(b + 1, INT_MAX);
    dp[0] = 0;

    // Динамика
    for (int i = 0; i < n; i++) {
        for (int w = b; w >= weights[i]; w--) {
            if (dp[w - weights[i]] != INT_MAX) {
                dp[w] = std::min(dp[w], dp[w - weights[i]] + volumes[i]);
            }
        }
    }

    int min_volume = INT_MAX;
    int best_weight = -1;

    for (int w = a; w <= b; w++) {
        if (dp[w] < min_volume) {
            min_volume = dp[w];
            best_weight = w;
        }
    }

    // FIX_ME: Вывод ":" вместо нормального сообщения
    // cout << ":";
    if (best_weight == -1) {
        std::cout << "Решение не найдено: невозможно набрать вес в диапазоне ["
            << a << ", " << b << "]\n";
        return;
    }

    std::cout << "Минимальный объём: " << min_volume << "\n";
    std::cout << "Вес: " << best_weight << "\n";
    std::cout << "Артефакты:\n";

    int w = best_weight;
    std::vector<int> chosen;

    for (int i = n - 1; i >= 0; i--) {
        // FIX_ME: Нет проверки dp[w - weights[i]] != INT_MAX
        // Старый код:
        // if (w >= c[i] && dp[w] == dp[w - c[i]] + d[i])
        // Новый код:
        if (w >= weights[i] && dp[w - weights[i]] != INT_MAX &&
            dp[w] == dp[w - weights[i]] + volumes[i]) {
            chosen.push_back(i + 1);
            w -= weights[i];
        }
    }

    // Вывод по возрастанию
    for (int i = chosen.size() - 1; i >= 0; i--) {
        int idx = chosen[i] - 1;
        std::cout << chosen[i] << ") Вес: " << weights[idx]
            << " Объём: " << volumes[idx] << "\n";
    }
}
