#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    const int CATEGORY_COUNT = 3;
    const int DRINKS_PER_CATEGORY = 4;
    const double PETRUSHKA_DISCOUNT = 0.05;
    const int PETRUSHKA_MIN_QUANTITY = 3;
    const double FULLPRICE_DISCOUNT = 0.13;
    const double TOTAL_DISCOUNT = 0.13;        
    const double TOTAL_MIN_AMOUNT = 2500.0;    
    const int ONION_FREE_EVERY = 4;

    int categoryDrink;
    string choiceBuy;
    int quantity = 0;
    bool categoryChoice = true;
    double priceDrinks = 0;
    char choiceMenu;
    int onionJuiceBought = 0;

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

    unsigned int count[CATEGORY_COUNT][DRINKS_PER_CATEGORY] = {
        {100, 80, 50, 60},
        {50, 35, 20},
        {15, 20}
    };

    bool choice = true;
    do
    {
        categoryChoice = true;
        cout << "\t\t\t\t==========Магазин 'Соки Никиты'==========" << endl;

        cout << "1 - Ассортимент магазина \n2 - Скидки магазина \n3 - Оплатить \n4 - Выход" << endl;
        cout << "Выбор: ";
        cin >> choiceMenu;
        if (choiceMenu == '1')
        {
            system("cls");
            cout << "\n" << "Выберите категорию напитков: \n1 - Фруктовые соки \n2 - Овощные соки \n3 - Чаи: => ";
            cin >> categoryDrink;
            system("cls");

            if (categoryDrink == 1)
            {
                while (categoryChoice == true)
                {
                    cout << "--- Фруктовые соки ---" << endl;
                    for (int j = 0; j < DRINKS_PER_CATEGORY; j++) {
                        cout << j + 1 << ". " << drinks[0][j] << " - " << prices[0][j] << " руб." << " (кол во в литровых банках) = "
                            << count[0][j] << endl;
                    }
                    cout << "Добавьте в корзину, что хотите купить (для выхода напишите 'exit'): ";
                    cin >> choiceBuy;

                    if (choiceBuy == "1")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[0][0])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[0][0] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[0][0] * quantity);
                            count[0][0] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[0][0] << endl;
                        }
                    }
                    else if (choiceBuy == "2")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[0][1])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[0][1] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[0][1] * quantity);
                            count[0][1] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[0][1] << endl;
                        }
                    }
                    else if (choiceBuy == "3")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[0][2])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[0][2] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[0][2] * quantity);
                            count[0][2] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[0][2] << endl;
                        }
                    }
                    else if (choiceBuy == "4")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[0][3])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[0][3] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[0][3] * quantity);
                            count[0][3] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[0][3] << endl;
                        }
                    }
                    else if (choiceBuy == "exit")
                    {
                        cout << "Покупка завершена";
                        categoryChoice = false;
                        Sleep(1500);
                        system("cls");
                        break;
                    }
                }
            }
            else if (categoryDrink == 2)
            {
                while (categoryChoice == true)
                {
                    cout << "--- Овощные соки ---" << endl;
                    for (int j = 0; j < DRINKS_PER_CATEGORY; j++) {
                        if (drinks[1][j] == "-")
                        {
                            cout << " ";
                        }
                        else
                        {
                            cout << j + 1 << ". " << drinks[1][j] << " - " << prices[1][j] << " руб." << " (кол во в литровых банках) = "
                                << count[1][j] << endl;
                        }
                    }
                    cout << "Добавьте в корзину, что хотите купить (для выхода напишите 'exit'): ";
                    cin >> choiceBuy;

                    if (choiceBuy == "1")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;

                        if (quantity <= count[1][0])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[1][1] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[1][1] * quantity);
                            count[1][1] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[1][1] << endl;
                        }
                    }
                    else if (choiceBuy == "2")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[1][1])
                        {
                            int freeLiters = quantity / ONION_FREE_EVERY;
                            int paidLiters = quantity - freeLiters;
                            double totalPrice = prices[1][1] * paidLiters;

                            system("cls");
                            cout << "В корзину добавлено: " << drinks[1][1] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks + -totalPrice;
                            count[1][1] -= quantity;
                            onionJuiceBought += quantity;
                            cout << "Применина акция каждый 4-й литр лукового сока в подарок!" << endl;;
                            cout << "   - Бесплатных литров: " << freeLiters << "\n";
                            cout << "   - Платных литров: " << paidLiters << "\n" << endl;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[1][1] << endl;
                        }
                    }
                    else if (choiceBuy == "3")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[1][2])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[1][2] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[1][2] * quantity);
                            count[1][2] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[1][2] << endl;
                        }
                    }
                    else if (choiceBuy == "exit")
                    {
                        cout << "Покупка завершена";
                        categoryChoice = false;
                        Sleep(1500);
                        system("cls");
                    }
                }
            }
            else if (categoryDrink == 3)
            {
                while (categoryChoice == true)
                {
                    cout << "--- Чаи ---" << endl;
                    for (int j = 0; j < DRINKS_PER_CATEGORY; j++) {
                        if (drinks[2][j] == "-")
                        {
                            cout << " ";
                        }
                        else
                        {
                            cout << j + 1 << ". " << drinks[2][j] << " - " << prices[2][j] << " руб." << " (кол во в литровых банках) = "
                                << count[2][j] << endl;
                        }
                    }
                    cout << "Добавьте в корзину, что хотите купить (для выхода напишите 'exit'): ";
                    cin >> choiceBuy;

                    if (choiceBuy == "1")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[2][0])
                        {
                            system("cls");
                            cout << "В корзину добавлено: " << drinks[2][0] << " - " << quantity << " литр(а/ов)\n" << endl;
                            priceDrinks += (prices[2][0] * quantity);
                            count[2][0] -= quantity;
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[2][0] << endl;
                        }
                    }
                    else if (choiceBuy == "2")
                    {
                        cout << "\nВведите кол во в литрах: ";
                        cin >> quantity;
                        if (quantity <= count[2][1])
                        {
                            double pricePerLiter = prices[2][1];
                            double totalPrice = pricePerLiter * quantity;
                            if (quantity >= PETRUSHKA_MIN_QUANTITY)
                            {
                                double discountAmount = totalPrice * PETRUSHKA_DISCOUNT;
                                double finalPrice = totalPrice - discountAmount;

                                system("cls");
                                cout << "В корзину добавлено: " << drinks[2][1] << " - " << quantity << " литр(а/ов)\n" << endl;
                                priceDrinks += finalPrice;
                                cout << "Применина скидка 5% на петрушевый чай!" << endl;
                            }
                            else
                            {
                                system("cls");
                                cout << "В корзину добавлено: " << drinks[2][1] << " - " << quantity << " литр(а/ов)\n" << endl;
                                priceDrinks += (prices[2][1] * quantity);
                                count[2][1] -= quantity;
                            }
                        }
                        else
                        {
                            system("cls");
                            cout << "Недостаточно товара! Доступно: " << count[2][1] << endl;
                        }
                    }
                    else if (choiceBuy == "exit")
                    {
                        cout << "Покупка завершена";
                        categoryChoice = false;
                        Sleep(1500);
                        system("cls");
                    }
                }
            }
        }
        bool ftrue = true;
        int zero;

            if (choiceMenu == '2')
            {
                while (ftrue == true)
                {
                    system("cls");
                    cout << "\nСкидки магазина: \n\t" << endl;
                    cout << "1) При покупки 3л петрушевого чая, скидка 5% на них\n"
                        << "2) Если стоимость покупки превышает 1200 рублей, то скидка 13 % на весь чек\n"
                        << "3) Каждый четвертый литр лукового сока в подарок" << endl;
                    cout << "Вернуться в меню -> 0: ";
                    cin >> zero;
                    if (zero == 0)
                    {
                        ftrue = false;
                        system("cls");
                    }
                }
            }
            char pay;
            if (choiceMenu == '3')
            {
                double finalPrice = priceDrinks;
                if (priceDrinks >= TOTAL_MIN_AMOUNT)
                {
                    double discountAmount = priceDrinks * TOTAL_DISCOUNT;
                    finalPrice = priceDrinks - discountAmount;

                    cout << "Применина скидка 13% на весь чек!" << endl;
                    cout << "К оплате: " << priceDrinks;
                    cout << "\nОплатить?(y/n): ";
                    cin >> pay;
                    if (pay == 'y')
                    {
                        cout << "Оплата прошла успешно!";
                        priceDrinks = 0;
                    }
                    cout << "\nВернуться в меню -> 0: ";
                    cin >> zero;
                    if (zero == 0)
                    {
                        ftrue = false;
                        system("cls");
                    }
                }
                else
                {
                    cout << "К оплате: " << priceDrinks;
                    cout << "\nОплатить?(y/n): ";
                    cin >> pay;
                    if (pay == 'y')
                    {
                        cout << "Оплата прошла успешно!";
                        priceDrinks = 0;
                    }
                    cout << "\nВернуться в меню -> 0: ";
                    cin >> zero;
                    if (zero == 0)
                    {
                        ftrue = false;
                        system("cls");
                    }
                }
            }
            if (choiceMenu == '4')
            {
                return 0;
            }
        }        
   while (choice == true);
}