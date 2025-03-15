#include "project1.cpp"
#include "project2.cpp"
#include "cursor_info.h"
#include "arrow_menu.h"
#include <iostream>
#include <string>

#define fastErrInfo std::cout << "Некорректный ввод. Введите информацию еще раз: ";
//#define DEBUG

int main() {
	setlocale(0,"ru");

    const std::string mainMenu[]{
        "Лабораторная работа №1",
        "Лабораторная работа №2",
        "Лабораторная работа №3",
        "Выход из программы"
    };
    int mainMenuCount = sizeof(mainMenu) / sizeof(mainMenu[0]);

    const std::string secondaryMenu[]{
        "Посмотреть задание",
        "Посмотреть задание и выполнить работу",
        "Вернуться в выбор лабораторной работы",
        "Выход из программы"
    };
    int secondaryMenuCount = sizeof(secondaryMenu) / sizeof(secondaryMenu[0]);

    while (true) {
        hideCursor();
        int choice = showMenu(".../mainMenu/\n-------------------------------------------", mainMenu, mainMenuCount);
        switch (choice) {
        case 0: { // Лабораторная работа №1
            std::cout << "\nВы выбрали: " << mainMenu[choice] << std::endl;
            while (true) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/\n-------------------------------------------", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case 0: { // Посмотреть задание
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n1. создать программу на языке С / С++, которая позволяет выбрать номер лабораторной работы семестра(1, 2, 3, 4…),\n2. создать массив объектов указанных классов,\n3. считать данные объектов с клавиатуры\n4. вывести данные объектов на экран и в файл\n5. создать методы установки значений полей класса.Методы должны проверять корректность задаваемых параметров\n6. создать конструктор с параметрами, конструктор без параметров, конструктор копирования, деструктор.\n\n3. Создать класс Employee(сотрудник).Класс должен включать поле int для хранения идентификационного номера сотрудника и поле float для хранения величины его оклада.В классе Employee должно быть поле типа класса Date(дата) и перечисления Position(должность).Поле типа Date необходимо использовать для хранения даты приема сотрудника на работу. Поле типа Position использовать для хранения статуса сотрудника : лаборант, секретарь, менеджер и т.д.\n" << std::endl;
                    system("pause");
                    break;
                }
                case 1: { // Посмотреть задание и выполнить работу
                    int day, month, year, id, empPosition, empCount = 0;
                    float salary;

                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n1. создать программу на языке С / С++, которая позволяет выбрать номер лабораторной работы семестра(1, 2, 3, 4…),\n2. создать массив объектов указанных классов,\n3. считать данные объектов с клавиатуры\n4. вывести данные объектов на экран и в файл\n5. создать методы установки значений полей класса.Методы должны проверять корректность задаваемых параметров\n6. создать конструктор с параметрами, конструктор без параметров, конструктор копирования, деструктор.\n\n3. Создать класс Employee(сотрудник).Класс должен включать поле int для хранения идентификационного номера сотрудника и поле float для хранения величины его оклада.В классе Employee должно быть поле типа класса Date(дата) и перечисления Position(должность).Поле типа Date необходимо использовать для хранения даты приема сотрудника на работу. Поле типа Position использовать для хранения статуса сотрудника : лаборант, секретарь, менеджер и т.д.\n" << std::endl;
                    showCursor();

                    std::cout << "Введите количество сотрудников: ";
                    while (!(std::cin >> empCount) || std::cin.peek() != '\n') {
                        fastErrInfo
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

                    if (empCount > 0) {
                        Employee* employees = new Employee[empCount];

                        for (int i = 0; i < empCount; i++) {
                            std::cout << "Сотрудник под номером: " << i + 1 << std::endl;
                            std::cout << "Введите идентификационный номер сотрудника: ";
                            while (!(std::cin >> id) || id < 0 || std::cin.peek() != '\n') {
                                fastErrInfo
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            std::cout << "Введите величину оклада сотрудника: ";
                            while (!(std::cin >> salary) || salary < 0 || std::cin.peek() != '\n') {
                                fastErrInfo
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }

                            std::cout << "Введите день, месяц и год приема на работу:\n";
                            while (true) {
                                if (!(std::cin >> day >> month >> year) || std::cin.peek() != '\n') {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    fastErrInfo
                                    continue;
                                }
                                if (isValidDate(day, month, year)) break;
                                else {
                                    fastErrInfo
                                }
                            }
                            Date hireDate;
                            hireDate.SetDate(day, month, year);

                            std::cout << "Введите позицию сотрудника (1 - LABORANT, 2 - SECRETAR, 3 - MANAGER): ";
                            while (!(std::cin >> empPosition) || empPosition < 1 || std::cin.peek() != '\n') {
                                fastErrInfo
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }

                            employees[i].SetEmployee(id, salary, hireDate, static_cast<Position>(empPosition - 1));
                        }

                        std::cout << "\nИнформация о сотрудниках:\n";
                        for (int i = 0; i < empCount; i++) {
                            employees[i].Printf();
                            std::cout << std::endl;
                        }

                        std::ofstream outFile("employees.txt");
                        if (outFile.is_open()) {
                            for (int i = 0; i < empCount; i++) {
                                employees[i].WriteToFile(outFile);
                            }
                            outFile.close();
                            std::cout << "\nИнформация о сотрудниках успешно записана в файл employees.txt" << std::endl;
                        }
                        else {
                            std::cout << "Ошибка открытия файла для записи!" << std::endl;
                        }

                        delete[] employees;
                    }
                    hideCursor();

                    system("pause");
                    break;
                }
                case 2: { // Вернуться в выбор лабораторной работы
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    goto mainMenu;
                }
                case 3: { // Выход из программы
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                }
            }
        }
        case 1: { // Лабораторная работа №2
            std::cout << "\nВы выбрали: " << mainMenu[choice] << std::endl;
            while (true) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/\n-------------------------------------------", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case 0: { // Посмотреть задание
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n 1. создать программу на языке С / С++, которая позволяет выбрать номер лабораторной работы семестра(1, 2, 3, 4…),\n2. создать массив объектов указанных классов,\n3. считать данные объектов с клавиатуры\n4. вывести данные объектов на экран и в файл\n5. создать методы установки значений полей класса.Методы должны проверять корректность задаваемых параметров\n6. создать конструктор с параметрами, конструктор без параметров, конструктор копирования, деструктор.\n\n3. Создать класс QuadraticEquation для решения квадратного уравнения.Установить ширину поля в 10 символов, точность 4 цифры, заполнить пробелы символом «#».Обязательно предусмотреть варианты двух, одного и отсутствия корней.Написать собственный манипулятор.\n" << std::endl;
                    system("pause");
                    break;
                }
                case 1: { // Посмотреть задание и выполнить работу
                    int rootsIterCount = 0;
                    double a, b, c;

                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n 1. создать программу на языке С / С++, которая позволяет выбрать номер лабораторной работы семестра(1, 2, 3, 4…),\n2. создать массив объектов указанных классов,\n3. считать данные объектов с клавиатуры\n4. вывести данные объектов на экран и в файл\n5. создать методы установки значений полей класса.Методы должны проверять корректность задаваемых параметров\n6. создать конструктор с параметрами, конструктор без параметров, конструктор копирования, деструктор.\n\n3. Создать класс QuadraticEquation для решения квадратного уравнения.Установить ширину поля в 10 символов, точность 4 цифры, заполнить пробелы символом «#».Обязательно предусмотреть варианты двух, одного и отсутствия корней.Написать собственный манипулятор.\n" << std::endl;
                    showCursor();

                    while (true) {
                        std::cout << "Введите количество квадратных уравнений: ";
                        while (!(std::cin >> rootsIterCount) || std::cin.peek() != '\n') {
                            fastErrInfo
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        if (rootsIterCount > 0) {
                            QuadraticEquation* quadraticEquations = new QuadraticEquation[rootsIterCount];

                            for (int i = 0; i < rootsIterCount; i++) {
                                std::cout << "Введите коэффициенты a, b, c для уравнения:  " << i + 1 << std::endl;
                                while (!(std::cin >> a >> b >> c) || std::cin.peek() != '\n') {
                                    fastErrInfo
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                quadraticEquations[i].SetQuadraticEquation(a, b, c);
                            }

                            std::cout << "\nИнформация о корнях:\n";
                            for (int i = 0; i < rootsIterCount; i++) {
                                quadraticEquations[i].Printf();
                                std::cout << std::endl;
                            }

                            std::ofstream outFile2("quadraticEquations.txt");
                            if (outFile2.is_open()) {
                                for (int i = 0; i < rootsIterCount; i++) {
                                    quadraticEquations[i].WriteToFile(outFile2);
                                }
                                outFile2.close();
                                std::cout << "\nИнформация об уранениях успешно записана в файл quadraticEquations.txt" << std::endl;
                            }
                            else {
                                std::cout << "Ошибка открытия файла для записи!" << std::endl;
                            }

                            delete[] quadraticEquations;
                            break;
                        }
                        else {
                            fastErrInfo
                        }
                    }    
                    hideCursor();

                    system("pause");
                    break;
                }
                case 2: { // Вернуться в выбор лабораторной работы
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    goto mainMenu;
                }
                case 3: { // Выход из программы
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                }
            }
        }
        case 2: { // Лабораторная работа №3
            std::cout << "\nВы выбрали: " << mainMenu[choice] << std::endl;
        }
        case 3: {// Выход из программы
            std::cout << "\nВы выбрали: " << mainMenu[choice] << std::endl;
            return 0;
        }
          mainMenu:;
        }
    }
	return 0;
}