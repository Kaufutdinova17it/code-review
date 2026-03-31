#include "Header.h"
#include <fstream>
#include <iostream>
#include <vector>

void SolveTurtle() {
    setlocale(LC_ALL, "ru");

    std::ifstream file_in("21.txt");
    std::ofstream file_out("22.txt");

    // FIX_ME: переменные не по Google Style
    // Старый код:
    // int n, res;
    // Новый код:
    int n = 0;
    int result = 0;

    // FIX_ME: нет проверки открытия файла
    if (!file_in.is_open()) {
        std::cout << "Ошибка: входной файл не найден\n";
        return;
    }

    file_in >> n;

    // FIX_ME: ошибка не завершает программу
    // Старый код:
    // if (n < 1 || n > 80) { cout << "Ошибка"; }
    // Новый код:
    if (n < 1 || n > 80) {
        std::cout << "Ошибка: n должно быть в диапазоне 1..80\n";
        return;
    }

    // FIX_ME: имена matr, dosk не по Google Style
    // Старый код:
    // vector<vector<int>> matr, dosk;
    // Новый код:
    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // Чтение матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(file_in >> board[i][j])) {
                std::cout << "Ошибка: недостаточно данных в файле\n";
                return;
            }

            // FIX_ME: break не останавливает программу
            // Старый код:
            // if (matr[i][j] > 100) { cout << "..."; break; }
            // Новый код:
            if (board[i][j] < 0 || board[i][j] > 100) {
                std::cout << "Ошибка: элементы должны быть в диапазоне 0..100\n";
                return;
            }
        }
    }

    // Динамика: движение только влево и вниз
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == 0 && j == n - 1) {
                dp[i][j] = board[i][j];
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j + 1] + board[i][j];
            }
            else if (j == n - 1) {
                dp[i][j] = dp[i - 1][j] + board[i][j];
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j + 1]) + board[i][j];
            }
        }
    }

    result = dp[n - 1][0];

    file_out << result;
    std::cout << "Максимальная сумма записана в файл: " << result << "\n";
}
