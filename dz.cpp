#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Константы
const int CATEGORY_COUNT = 3;
const int DRINKS_PER_CATEGORY = 4;
const double PETRUSHKA_DISCOUNT = 0.05;
const int PETRUSHKA_MIN_QUANTITY = 3;
const double TOTAL_DISCOUNT = 0.13;
const double TOTAL_MIN_AMOUNT = 2500.0;
const int ONION_FREE_EVERY = 4;

// Массивы с данными
string categories[CATEGORY_COUNT] = {
    "Фруктовые соки",
    "Овощные соки",
    "Чаи"
};

string drinks[CATEGORY_COUNT][DRINKS_PER_CATEGORY] = {
    {"Яблочный сок", "Апельсиновый сок", "Абрикосовый сок", "Грушевый сок"},
    {"Томатный сок", "Луковый сок", "Огуречный сок", "-"},
    {"Чесночный чай", "Петрушечный чай", "-", "-"}
};

double prices[CATEGORY_COUNT][DRINKS_PER_CATEGORY] = {
    {120.0, 130.0, 100.0, 110.0},
    {100.0, 150.0, 140.0, 0.0},
    {90.0, 80.0, 0.0, 0.0}
};

int counts[CATEGORY_COUNT][DRINKS_PER_CATEGORY] = {
    {100, 80, 50, 60},
    {50, 35, 20, 0},
    {15, 20, 0, 0}
};

// Функции
void showMenu();
void showAssortment(double& totalPrice);
void showDiscounts();
void makePayment(double& totalPrice);
void showCategory(int category, double& totalPrice);
void clearScreen();

int main()
{
    setlocale(LC_ALL, "ru");

    double totalPrice = 0;
    char choice;

    while (true)
    {
        showMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            showAssortment(totalPrice);
            break;
        case '2':
            showDiscounts();
            break;
        case '3':
            makePayment(totalPrice);
            break;
        case '4':
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неверный выбор!" << endl;
            Sleep(1000);
        }
        clearScreen();
    }
}

void showMenu()
{
    cout << "=========================================" << endl;
    cout << "         МАГАЗИН 'СОКИ НИКИТЫ'         " << endl;
    cout << "=========================================" << endl;
    cout << "1 - Посмотреть ассортимент" << endl;
    cout << "2 - Узнать о скидках" << endl;
    cout << "3 - Оплатить покупки" << endl;
    cout << "4 - Выйти из магазина" << endl;
    cout << "=========================================" << endl;
}

void showAssortment(double& totalPrice)
{
    int categoryChoice;

    cout << "Выберите категорию:" << endl;
    cout << "1 - Фруктовые соки" << endl;
    cout << "2 - Овощные соки" << endl;
    cout << "3 - Чаи" << endl;
    cout << "0 - Вернуться в меню" << endl;
    cout << "Ваш выбор: ";
    cin >> categoryChoice;

    if (categoryChoice == 0) return;

    if (categoryChoice >= 1 && categoryChoice <= 3)
    {
        showCategory(categoryChoice - 1, totalPrice);
    }
    else
    {
        cout << "Неверная категория!" << endl;
        Sleep(1000);
    }
}

void showCategory(int category, double& totalPrice)
{
    string choiceBuy;
    int quantity;

    while (true)
    {
        clearScreen();
        cout << "=== " << categories[category] << " ===" << endl;

        // Показываем напитки в категории
        for (int i = 0; i < DRINKS_PER_CATEGORY; i++)
        {
            if (drinks[category][i] != "-")
            {
                cout << i + 1 << ". " << drinks[category][i] << " - "
                    << prices[category][i] << " руб. (осталось: "
                    << counts[category][i] << " л)" << endl;
            }
        }

        cout << "\nВведите номер напитка для покупки (или '0' для выхода): ";
        cin >> choiceBuy;

        if (choiceBuy == "0") break;

        // Простая проверка ввода
        int drinkNum = 0;
        bool validInput = true;

        // Проверяем, что ввод - цифра
        for (int i = 0; i < choiceBuy.length(); i++)
        {
            if (!isdigit(choiceBuy[i]))
            {
                validInput = false;
                break;
            }
        }

        if (!validInput)
        {
            cout << "Неверный ввод! Введите число." << endl;
            Sleep(1000);
            continue;
        }

        drinkNum = stoi(choiceBuy);

        if (drinkNum < 1 || drinkNum > DRINKS_PER_CATEGORY || drinks[category][drinkNum - 1] == "-")
        {
            cout << "Неверный номер напитка!" << endl;
            Sleep(1000);
            continue;
        }

        cout << "Сколько литров хотите купить? ";
        cin >> quantity;

        if (quantity <= 0)
        {
            cout << "Количество должно быть больше 0!" << endl;
            Sleep(1000);
            continue;
        }

        // Добавляем в корзину
        int drinkIndex = drinkNum - 1;

        if (quantity <= counts[category][drinkIndex])
        {
            double price = prices[category][drinkIndex];
            double cost = price * quantity;

            // Применяем акции
            if (category == 2 && drinkIndex == 1 && quantity >= PETRUSHKA_MIN_QUANTITY)
            {
                // Скидка на петрушечный чай
                double discount = cost * PETRUSHKA_DISCOUNT;
                cost -= discount;
                cout << "Применена скидка 5%: -" << discount << " руб." << endl;
            }
            else if (category == 1 && drinkIndex == 1)
            {
                // Акция на луковый сок
                int freeLiters = quantity / ONION_FREE_EVERY;
                int paidLiters = quantity - freeLiters;
                cost = price * paidLiters;
                cout << "Акция: " << freeLiters << " литр(а) лукового сока бесплатно!" << endl;
            }

            totalPrice += cost;
            counts[category][drinkIndex] -= quantity;

            cout << "Добавлено в корзину: " << drinks[category][drinkIndex]
                << " - " << quantity << " л" << endl;
            cout << "Стоимость: " << cost << " руб." << endl;
            cout << "Общая сумма: " << totalPrice << " руб." << endl;
        }
        else
        {
            cout << "Недостаточно товара! Доступно: " << counts[category][drinkIndex] << " л" << endl;
        }

        cout << "\nНажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    }
}

void showDiscounts()
{
    clearScreen();
    cout << "=========================================" << endl;
    cout << "           АКЦИИ И СКИДКИ              " << endl;
    cout << "=========================================" << endl;
    cout << "1. Петрушечный чай:" << endl;
    cout << "   - При покупке от 3 литров - скидка 5%" << endl;
    cout << endl;
    cout << "2. Луковый сок:" << endl;
    cout << "   - Каждый 4-й литр - бесплатно!" << endl;
    cout << endl;
    cout << "3. Общая скидка:" << endl;
    cout << "   - При сумме покупки от 2500 руб. - скидка 13%" << endl;
    cout << "=========================================" << endl;

    cout << "Нажмите 0 для возврата в меню: ";
    int zero;
    cin >> zero;
}

void makePayment(double& totalPrice)
{
    clearScreen();
    cout << "=========================================" << endl;
    cout << "               ОПЛАТА                  " << endl;
    cout << "=========================================" << endl;

    if (totalPrice == 0)
    {
        cout << "Ваша корзина пуста!" << endl;
    }
    else
    {
        double finalPrice = totalPrice;

        if (totalPrice >= TOTAL_MIN_AMOUNT)
        {
            double discount = totalPrice * TOTAL_DISCOUNT;
            finalPrice = totalPrice - discount;

            cout << "Сумма покупки: " << totalPrice << " руб." << endl;
            cout << "Скидка 13%: -" << discount << " руб." << endl;
            cout << "Итого к оплате: " << finalPrice << " руб." << endl;
        }
        else
        {
            cout << "Итого к оплате: " << totalPrice << " руб." << endl;
        }

        cout << "\nОплатить? (y/n): ";
        char pay;
        cin >> pay;

        if (pay == 'y' || pay == 'Y')
        {
            cout << "ОПЛАТА ПРОШЛА УСПЕШНО!" << endl;
            cout << "Спасибо за покупку!" << endl;
            totalPrice = 0;
        }
        else
        {
            cout << "Оплата отменена." << endl;
        }
    }

    cout << "Нажмите Enter для продолжения...";
    cin.ignore();
    cin.get();
}

void clearScreen()
{
    system("cls");
}