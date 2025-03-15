#include "arrow_menu.h"
#include <iostream>
#include <conio.h>

int showMenu(const std::string& title, const std::string options[], int optionCount)
{
    int choice = 0;
    while (true) {
        system("cls");
        std::cout << title << std::endl;
        for (int i = 0; i < optionCount; ++i) {
            if (i == choice) {
                std::cout << "--> " << options[i] << std::endl;
            }
            else {
                std::cout << "   " << options[i] << std::endl;
            }
        }

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) {
                choice--;
                if (choice < 0) {
                    choice = optionCount - 1;
                }
            }
            else if (key == 80) { 
                choice++;
                if (choice >= optionCount) {
                    choice = 0; 
                }
            }
        }
        else if (key == 13) { // enter
            return choice;
        }
    }
}