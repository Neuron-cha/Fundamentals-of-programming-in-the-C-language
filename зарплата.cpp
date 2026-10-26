#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>   // Для SetConsoleCP и SetConsoleOutputCP

using namespace std;

// Функция для расчета зарплаты в зависимости от уровня продаж
double calculateSalary(double sales) {
    double baseSalary = 200.0;
    double percentage = 0.0;

    if (sales < 500) {
        percentage = 0.03; // 3%
    }
    else if (sales >= 500 && sales < 1000) {
        percentage = 0.05; // 5%
    }
    else {
        percentage = 0.08; // 8%
    }

    return baseSalary + (sales * percentage);
}

int main() {
    // Устанавливаем кодировку консоли в UTF-8
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int numManagers = 3;
    double sales[numManagers];
    double salaries[numManagers];

    cout << "--- Расчет зарплат менеджеров ---\n";

    // Ввод данных и расчет базовой зарплаты
    for (int i = 0; i < numManagers; i++) {
        cout << "Введите уровень продаж для менеджера " << i + 1 << ": $";
        cin >> sales[i];
        salaries[i] = calculateSalary(sales[i]);
    }

    // Поиск лучшего менеджера (у кого максимальные продажи)
    int bestManagerIndex = 0;
    for (int i = 1; i < numManagers; i++) {
        if (sales[i] > sales[bestManagerIndex]) {
            bestManagerIndex = i;
        }
    }

    // Начисление премии лучшему
    salaries[bestManagerIndex] += 200.0;
    cout << "\nЛучший менеджер: №" << bestManagerIndex + 1 << ". Ему начислена премия $200!\n\n";

    // Вывод результатов
    cout << fixed << setprecision(2);
    cout << "--- Итоговые зарплаты ---\n";
    for (int i = 0; i < numManagers; i++) {
        cout << "Менеджер " << i + 1 << " (Продажи: $" << sales[i] << ") -> Зарплата: $" << salaries[i] << "\n";
    }

    return 0;
}