#include <iostream>
#include "MRU.h"
#include "CLOCK.h"

void menuMRU() {

    int frames, option;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << ">>>>>>>>>> INICIALIZAR BUFFER MRU <<<<<<<<<<" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Total de frames: ";
    std::cin >> frames;

    MRU mru(frames);

    do {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << ">>>>>>>>>>>>       MENU MRU      <<<<<<<<<<<<" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "1. Insertar" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Mostrar contenido" << std::endl;
        std::cout << "4. Mostrar hits/misses" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "---------------------------------------------\n" << std::endl;
        std::cin >> option;

        switch (option) {
        case 1: {
            std::string pag;
            std::cout << "Introduce la pag a insertar: ";
            std::cin >> pag;
            mru.insertar(pag);
            break;
        }
        case 2: {
            std::string pag;
            std::cout << "Introduce la pag a buscar: ";
            std::cin >> pag;
            std::cout << mru.buscar(pag) << std::endl;
            break;
        }
        case 3: {
            mru.mostrarContenido();
            break;
        }
        case 4: {
            mru.mostrarHitsMisses();
            break;
        }
        case 5: {
            std::cout << "Chaito" << std::endl;
            break;
        }
        default: {
            std::cout << "opcion invalida, intente de nuevo" << std::endl;
        }
        }
    } while (option != 5);
}

void menuCLOCK() {

    int frames, option;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << ">>>>>>>>  INICIALIZAR BUFFER CLOCK  <<<<<<<<<" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Total de frames: ";
    std::cin >> frames;

    CLOCK clock(frames);

    do {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << ">>>>>>>>>>>>     MENU CLOCK     <<<<<<<<<<<<<" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "1. Insertar" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Mostrar contenido" << std::endl;
        std::cout << "4. Mostrar hits/misses" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "---------------------------------------------\n" << std::endl;
        std::cin >> option;

        switch (option) {

            case 1: {
                std::string pag;
                std::cout << "Introduce la pag a insertar: ";
                std::cin >> pag;
                clock.insertar(pag);
                break;
            }

            case 2: {
                std::string pag;
                std::cout << "Introduce la pag a buscar: ";
                std::cin >> pag;
                std::cout << clock.buscar(pag) << std::endl;
                break;
            }

            case 3: {
                clock.mostrarContenido();
                break;
            }

            case 4: {
                clock.mostrarHitsMisses();
                break;
            }

            case 5: {
                std::cout << "Chaito" << std::endl;
                break;
            }

            default: {
                std::cout << "opcion invalida, intente de nuevo" << std::endl;
            }

        }

    } while (option != 5);
}

int main() {

    int option;

    do {

        std::cout << "---------------------------------------------" << std::endl;
        std::cout << ">>>>>>>>>>>>>        MENU       <<<<<<<<<<<<<" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "1. Menu MRU" << std::endl;
        std::cout << "2. Menu CLOCK" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "---------------------------------------------\n" << std::endl;

        std::cin >> option;

        switch (option) {

            case 1:
                menuMRU();
                break;

            case 2:
                menuCLOCK();
                break;

            case 3:
                std::cout << "Chaito" << std::endl;
                break;

            default:
                std::cout << "Opción inválida, intente de nuevo" << std::endl;
        }

    } while (option != 3);

    return 0;
}
