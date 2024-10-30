#pragma once
#include <string>
#include <iostream>
#include <unordered_map>

// reutilizando la list de LRU

struct Nodo {
    std::string valor;
    Nodo* prev;
    Nodo* next;
    Nodo(const std::string& val) : valor(val), prev(nullptr), next(nullptr) {}
};

class ListaDoble {

    Nodo* head;
    Nodo* tail;

public:

    ListaDoble() : head(nullptr), tail(nullptr) {}

    void insertarAlFrente(Nodo* nodo) {

        if (!head) head = tail = nodo;

        else {
            nodo->next = head;
            head->prev = nodo;
            head = nodo;
        }
    }

    void eliminarNodo(Nodo* nodo) {

        if (!nodo) return; // caso base

        if (nodo == head) head = head->next;

        if (nodo == tail) tail = tail->prev;

        if (nodo->prev) nodo->prev->next = nodo->next;
        if (nodo->next) nodo->next->prev = nodo->prev;

        if (!head) tail = nullptr;

        nodo->prev = nodo->next = nullptr;
    }

    Nodo* eliminarUltimo() {

        Nodo* nodo = tail;
        if (tail) {
            eliminarNodo(tail);
        }
        return nodo;
    }

    void moverAlFrente(Nodo* nodo) { // por si es llamada una pagina que ya esta en el frame

        eliminarNodo(nodo);
        insertarAlFrente(nodo);

    }

    void mostrar() {

        Nodo* actual = head;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << ">>>>>>>>>>>>>      LISTA MRU    <<<<<<<<<<<<<" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;

        while (actual) {
            std::cout << actual->valor << " --> ";
            actual = actual->next;
        }
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }

    Nodo* obtenerHead() const {
        return head;
    }
};

class MRU {

    int capacidad;
    int hits;
    int misses;
    ListaDoble lista;
    std::unordered_map<std::string, Nodo*> frames;

public:
    MRU(int cap);
    void insertar(const std::string& pag);
    std::string buscar(const std::string& pag);
    void mostrarContenido();
    void mostrarHitsMisses();
};
