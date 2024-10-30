#include "MRU.h"

MRU::MRU(int cap) : capacidad(cap), hits(0), misses(0) {}

void MRU::insertar(const std::string& nombre) {

    if (frames.find(nombre) != frames.end()) {
        hits++;
        lista.moverAlFrente(frames[nombre]);
    }

    else {
        misses++;
       
        Nodo* nodoAEliminar = lista.obtenerHead();  
        if (frames.size() == capacidad && nodoAEliminar) {
            lista.eliminarNodo(nodoAEliminar);
            frames.erase(nodoAEliminar->valor);
            delete nodoAEliminar;
        }

        // insertar pag al frente
        Nodo* nuevoNodo = new Nodo(nombre);
        lista.insertarAlFrente(nuevoNodo);
        frames[nombre] = nuevoNodo;
    }
}

std::string MRU::buscar(const std::string& nombre) {

    if (frames.find(nombre) != frames.end()) {
        hits++;
        lista.moverAlFrente(frames[nombre]);
        return nombre + " existe actualmente en la mem cache";
    }

    misses++;
    return nombre + " no existe actualmente en la mem cache";
}

void MRU::mostrarContenido() {
    lista.mostrar();
}

void MRU::mostrarHitsMisses() {
    std::cout << "Hits: " << hits << ", Misses: " << misses << std::endl;
}
