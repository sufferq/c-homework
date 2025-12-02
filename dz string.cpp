#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

unsigned const int VAGONS_NUMBER = 18;
unsigned const int PLACES_IN_VAGONS = 36;

//---------------------------Функции-------------------------------
void random_train(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void empty_train(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void startmenu(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void choosePlace(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void displayTrain(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void secondStartMenu(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void statistics(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]);
void waitForReturn();
//-----------------------------------------------------------------

void waitForReturn() {
    cout << "\nНажмите любую клавишу для возврата в меню...";
    system("pause > nul");
    system("cls");
}

void random_train(int train[VAGONS_NUMBER][PLACES_IN_VAGONS])
{
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < VAGONS_NUMBER; i++) {
        for (int j = 0; j < PLACES_IN_VAGONS; j++) {
            train[i][j] = rand() % 2;
        }
    }
    cout << "Поезд заполнен случайными числами." << endl;
    Sleep(1500);
    system("cls");
}

void empty_train(int train[VAGONS_NUMBER][PLACES_IN_VAGONS])
{
    for (int i = 0; i < VAGONS_NUMBER; i++) {
        for (int j = 0; j < PLACES_IN_VAGONS; j++) {
            train[i][j] = 0;
        }
    }
    cout << "Все места в поезде свободны." << endl;
    Sleep(1500);
    system("cls");
}

void displayTrain(int train[VAGONS_NUMBER][PLACES_IN_VAGONS]) {
    int chooseplace;

    cout << "\n============= ИНФОРМАЦИЯ О ПРОДАННЫХ БИЛЕТАХ =============" << endl;
    cout << "Вагоны: " << VAGONS_NUMBER << ", Мест в вагоне: " << PLACES_IN_VAGONS << endl;
    cout << "Символы: '0' - свободно, '1' - занято\n" << endl;

    cout << setw(4) << "В/М";
    for (int j = 0; j < PLACES_IN_VAGONS; j++) {
        cout << setw(3) << (j + 1);
    }
    cout << endl;

    cout << string(4 + PLACES_IN_VAGONS * 3, '-') << endl;

    for (int i = 0; i < VAGONS_NUMBER; i++) {
        cout << setw(3) << (i + 1) << "|";
        for (int j = 0; j < PLACES_IN_VAGONS; j++) {
            cout << setw(3) << (train[i][j] == 0 ? '0' : '1');
        }
        cout << endl;
    }

    cout << "\nЗабронировать место? -> (1 - Да / 0 - Вернуться):  ";
    cin >> chooseplace;

    if (chooseplace == 1)
    {
        system("cls");
        choosePlace(train);
    }
    else if (chooseplace == 0)
    {
        system("cls");
    }
}

void choosePlace(int train[VAGONS_NUMBER][PLACES_IN_VAGONS])
{
    int choice_brone;
    bool chooseplace2 = true;
    char exit;

    while (chooseplace2)
    {
        cout << "========== ФУНКЦИЯ ПО УПРАВЛЕНИЮ ЗАПОЛНЕНИЯ МЕСТ ==========" << endl;
        cout << "Забронировать место? -> 1\nСделать пустым -> 2\nВернуться -> 0 " << endl;
        cout << "Выбор: ";
        cin >> choice_brone;

        if (choice_brone == 1)
        {
            int choice_vagon, choice_place;

            cout << "Выберите вагон (1-" << VAGONS_NUMBER << "): ";
            cin >> choice_vagon;
            cout << "Выберите место (1-" << PLACES_IN_VAGONS << "): ";
            cin >> choice_place;

            if (choice_vagon < 1 || choice_vagon > VAGONS_NUMBER ||
                choice_place < 1 || choice_place > PLACES_IN_VAGONS) {
                cout << "Ошибка: неверный номер вагона или места!" << endl;
                Sleep(2000);
                system("cls");
                continue;
            }

            if (train[choice_vagon - 1][choice_place - 1] == 1) {
                cout << "Место уже занято!" << endl;
                Sleep(2000);
                system("cls");
                continue;
            }

            train[choice_vagon - 1][choice_place - 1] = 1;
            cout << "Место успешно забронировано!" << endl;
            cout << "Вернуться? (y/n): ";
            cin >> exit;

            if (exit == 'y' || exit == 'Y')
            {
                chooseplace2 = false;
                system("cls");
            }
            else
            {
                system("cls");
            }
        }
        else if (choice_brone == 2)
        {
            int choice_vagon, choice_place;

            cout << "Выберите вагон (1-" << VAGONS_NUMBER << "): ";
            cin >> choice_vagon;
            cout << "Выберите место (1-" << PLACES_IN_VAGONS << "): ";
            cin >> choice_place;

            if (choice_vagon < 1 || choice_vagon > VAGONS_NUMBER ||
                choice_place < 1 || choice_place > PLACES_IN_VAGONS) {
                cout << "Ошибка: неверный номер вагона или места!" << endl;
                Sleep(2000);
                system("cls");
                continue;
            }

            if (train[choice_vagon - 1][choice_place - 1] == 0) {
                cout << "Место уже свободно!" << endl;
                Sleep(2000);
                system("cls");
                continue;
            }

            train[choice_vagon - 1][choice_place - 1] = 0;
            cout << "Место освобождено!" << endl;
            cout << "Вернуться? (y/n): ";
            cin >> exit;

            if (exit == 'y' || exit == 'Y')
            {
                chooseplace2 = false;
                system("cls");
            }
            else
            {
                system("cls");
            }
        }
        else if (choice_brone == 0)
        {
            chooseplace2 = false;
            system("cls");
        }
        else
        {
            cout << "Неверный выбор!" << endl;
            Sleep(2000);
            system("cls");
        }
    }
}

void statistics(int train[VAGONS_NUMBER][PLACES_IN_VAGONS])
{
    int stat;
    bool staticBool = true;

    while (staticBool)
    {
        system("cls");
        cout << "========== СТАТИСТИКА ==========" << endl;

        int totalFree = 0;
        int totalOccupied = 0;

        for (int i = 0; i < VAGONS_NUMBER; i++) {
            int freeInVagon = 0;
            for (int j = 0; j < PLACES_IN_VAGONS; j++) {
                if (train[i][j] == 0) {
                    freeInVagon++;
                }
            }
            totalFree += freeInVagon;
            int occupiedInVagon = PLACES_IN_VAGONS - freeInVagon;
            totalOccupied += occupiedInVagon;
        }

        cout << "Общая статистика:" << endl;
        cout << "Свободных мест во всех вагонах: " << totalFree << endl;
        cout << "Занятых мест во всех вагонах: " << totalOccupied << endl;
        cout << "Всего мест: " << VAGONS_NUMBER * PLACES_IN_VAGONS << endl;

        cout << "\n1 - Свободные места по вагонам\n0 - Вернуться\nВыбор: ";
        cin >> stat;

        if (stat == 1)
        {
            system("cls");
            cout << "=== СВОБОДНЫЕ МЕСТА ПО ВАГОНАМ ===" << endl;
            for (int i = 0; i < VAGONS_NUMBER; i++) {
                int freeInVagon = 0;
                for (int j = 0; j < PLACES_IN_VAGONS; j++) {
                    if (train[i][j] == 0) {
                        freeInVagon++;
                    }
                }
                int occupiedInVagon = PLACES_IN_VAGONS - freeInVagon;

                cout << "Вагон " << setw(2) << (i + 1) << ": "
                    << freeInVagon << " свободных, "
                    << occupiedInVagon << " занятых" << endl;
            }
            waitForReturn();
        }
        else if (stat == 0)
        {
            staticBool = false;
            system("cls");
        }
        else
        {
            cout << "Неверный выбор!" << endl;
            Sleep(1500);
        }
    }
}

void secondStartMenu(int train[VAGONS_NUMBER][PLACES_IN_VAGONS])
{
    int choiceMenu;
    bool MenuBool = true;

    while (MenuBool)
    {
        system("cls");
        cout << "\n========== ГЛАВНОЕ МЕНЮ ==========" << endl;
        cout << "1. Показать места в поезде" << endl;
        cout << "2. Показать статистику" << endl;
        cout << "3. Управление местами" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choiceMenu;

        if (choiceMenu == 1)
        {
            system("cls");
            displayTrain(train);
            waitForReturn();
        }
        else if (choiceMenu == 2)
        {
            statistics(train);
        }
        else if (choiceMenu == 3)
        {
            system("cls");
            choosePlace(train);
        }
        else if (choiceMenu == 4)
        {
            MenuBool = false;
            cout << "Выход из программы..." << endl;
            Sleep(1500);
        }
        else
        {
            cout << "Некорректный ввод!";
            Sleep(1500);
            system("cls");
        }
    }
}

void startmenu(int train[VAGONS_NUMBER][PLACES_IN_VAGONS])
{
    int choice;
    bool main = true;

    while (main)
    {
        cout << "========== СИСТЕМА БРОНИРОВАНИЯ МЕСТ В ПОЕЗДЕ ==========" << endl;
        cout << "Выберите режим заполнения:" << endl;
        cout << "1. Случайное заполнение" << endl;
        cout << "2. Все места свободны" << endl;
        cout << "3. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1)
        {
            random_train(train);
            secondStartMenu(train);
            main = false;
        }
        else if (choice == 2)
        {
            empty_train(train);
            secondStartMenu(train);
            main = false;
        }
        else if (choice == 3)
        {
            main = false;
            cout << "Выход из программы..." << endl;
            Sleep(1500);
        }
        else
        {
            cout << "Неверный выбор!" << endl;
            Sleep(1500);
            system("cls");
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int train[VAGONS_NUMBER][PLACES_IN_VAGONS];

    startmenu(train);

    return 0;
}