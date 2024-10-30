#include "CLOCK.h"

CLOCK::CLOCK(int cap) : capacidad(cap), puntero(0), hits(0), misses(0) {
    frames.resize(capacidad);
}

void CLOCK::insertar(const std::string& nombre) {
    for (auto& frame : frames) {
        if (frame.pag == nombre) {
            frame.ref = true;
            hits++;
            return;
        }
    }

    misses++;

    while (frames[puntero].ref) {
        frames[puntero].ref = false; // solo le queda una oportunidad
        puntero = (puntero + 1) % capacidad;
    }

    frames[puntero] = Frame(nombre);
    puntero = (puntero + 1) % capacidad;
}

std::string CLOCK::buscar(const std::string& nombre) {
    for (auto& frame : frames) {
        if (frame.pag == nombre) {
            frame.ref = true; // se usa
            hits++;
            return nombre + " existe actualmente en la mem cache";
        }
    }
    misses++;
    return nombre + " no existe actualmente en la mem cache";
}

void CLOCK::mostrarContenido() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << ">>>>>>>>>>>>>    LISTA CLOCK    <<<<<<<<<<<<<" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (const auto& frame : frames) {
        std::cout << frame.pag << " [" << frame.ref << "] --> ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void CLOCK::mostrarHitsMisses() {
    std::cout << "Hits: " << hits << ", Misses: " << misses << std::endl;
}
