#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>   // Для SetConsoleCP и SetConsoleOutputCP

using namespace std;

int main() {
    // Устанавливаем кодировку консоли в UTF-8.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1. Меню
    string pizzaNames[4] = { "Cheese Pizza", "Hawaiian Pizza", "BBQ Chicken Pizza", "Seafood Delight Pizza" };
    double pizzaPrices[4] = { 6.75, 8.95, 14.5, 10.25 };

    string drinkNames[3] = { "Pepsi", "Aquafina", "Crush Orange" };
    double drinkPrices[3] = { 1.79, 2.5, 3.09 };

    int pizzaID, drinkID;
    int pizzaAmount, drinkAmount;

    cout << "--- Добро пожаловать в мини-пиццерию! ---\n\n";

    // Вывод меню пицц
    cout << "Выберите пиццу (введите код):\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << " - " << pizzaNames[i] << " $" << pizzaPrices[i] << "\n";
    }
    cin >> pizzaID;
    cout << "Введите количество пицц: ";
    cin >> pizzaAmount;

    // Вывод меню напитков
    cout << "\nВыберите напиток (введите код):\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " - " << drinkNames[i] << " $" << drinkPrices[i] << "\n";
    }
    cin >> drinkID;
    cout << "Введите количество напитков: ";
    cin >> drinkAmount;

    // Проверка на корректность ввода
    if (pizzaID < 1 || pizzaID > 4 || drinkID < 1 || drinkID > 3 || pizzaAmount < 0 || drinkAmount < 0) {
        cout << "Ошибка: неверно введен код или количество!\n";
        return 1;
    }

    // Получаем цены выбранных продуктов
    double selectedPizzaPrice = pizzaPrices[pizzaID - 1];
    double selectedDrinkPrice = drinkPrices[drinkID - 1];

    // 2. Расчет пицц (каждая пятая в подарок)
    int pizzasToPay = pizzaAmount;
    if (pizzaAmount >= 5) {
        int freePizzas = pizzaAmount / 5;
        pizzasToPay = pizzaAmount - freePizzas;
        cout << "\n[Акция] Каждая 5-я пицца в подарок! Вы платите за " << pizzasToPay << " шт.\n";
    }
    double pizzasTotal = pizzasToPay * selectedPizzaPrice;

    // 3. Расчет напитков (скидка 15% если цена > 2$ и кол-во >= 3)
    double drinksTotal = drinkAmount * selectedDrinkPrice;
    if (selectedDrinkPrice > 2.0 && drinkAmount >= 3) {
        drinksTotal = drinksTotal * 0.85;
        cout << "[Акция] Скидка 15% на выбранный напиток!\n";
    }

    // 4. Итоговая сумма и общая скидка
    double totalSum = pizzasTotal + drinksTotal;
    if (totalSum > 50.0) {
        totalSum = totalSum * 0.8;
        cout << "[Акция] Скидка 20% на весь заказ (сумма > 50$)!\n";
    }

    // 5. Вывод чека
    cout << "\n--- ВАШ ЧЕК ---\n";
    cout << fixed << setprecision(2);
    cout << pizzaNames[pizzaID - 1] << " - " << pizzaAmount << " шт. - $" << selectedPizzaPrice
        << " (К оплате: " << pizzasToPay << " шт.)\n";
    cout << drinkNames[drinkID - 1] << " - " << drinkAmount << " шт. - $" << selectedDrinkPrice << "\n";
    cout << "------------------------\n";
    cout << "ИТОГО К ОПЛАТЕ: $" << totalSum << "\n";
    cout << "Приятного аппетита!\n";

    return 0;
}