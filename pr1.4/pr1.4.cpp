// main.cpp
#include "Figuri.h"
#include <iostream>

int main() {
    const int MAX_FIGURES = 3;
    Figura* figures[MAX_FIGURES];

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create Figures\n";
        std::cout << "2. Display Information\n";
        std::cout << "3. Resize Figures\n";
        std::cout << "4. Rotate Figures\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < MAX_FIGURES; ++i) {
                int figureType;
                std::cout << "Choose a figure type for Figure " << i + 1 << ": 1. Kruh, 2. Kvadrat, 3. Pryamokutnik: ";
                std::cin >> figureType;

                switch (figureType) {
                case 1:
                    figures[i] = new Kruh();
                    break;
                case 2:
                    figures[i] = new Kvadrat();
                    break;
                case 3:
                    figures[i] = new Pryamokutnik();
                    break;
                default:
                    std::cout << "Invalid choice. Exiting program." << std::endl;
                    return 1;
                }

                figures[i]->Read();
            }
            break;
        case 2:
            for (int i = 0; i < MAX_FIGURES; ++i) {
                std::cout << "Figure " << i + 1 << ": " << figures[i]->toString() << std::endl;
                figures[i]->Display();
                std::cout << std::endl;
            }
            break;
        case 3:
            for (int i = 0; i < MAX_FIGURES; ++i) {
                double factor;
                std::cout << "Enter the resize factor for Figure " << i + 1 << ": ";
                std::cin >> factor;
                figures[i]->Resize(factor);
            }
            break;
        case 4:
            for (int i = 0; i < MAX_FIGURES; ++i) {
                double angle;
                std::cout << "Enter the rotation angle for Figure " << i + 1 << ": ";
                std::cin >> angle;
                figures[i]->Rotate(angle);
            }
            break;
        case 0:
            break; // Exit the loop and end the program
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    // Clean up allocated memory
    for (int i = 0; i < MAX_FIGURES; ++i) {
        delete figures[i];
    }

    return 0;
}
