#pragma once
#include <iostream>
#include <vector>

class CLOCK {

    struct Frame { // structu especial para usar el ref para dar una segunda oportunidad (si es 1) o eliminarlo (si es 0)
        std::string pag;
        bool ref;

        Frame() : pag(""), ref(false) {}
        Frame(const std::string& p) : pag(p), ref(true) {}
    };

    int capacidad;
    int puntero;
    int hits;
    int misses;
    std::vector<Frame> frames;

public:

    CLOCK(int cap);
    void insertar(const std::string& pag);
    std::string buscar(const std::string& pag);
    void mostrarContenido();
    void mostrarHitsMisses();
};
