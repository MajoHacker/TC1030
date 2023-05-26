/*
 *
 * Proyecto Agencia clase Catalogo
 * María José Gaytán Gil
 * A01706616
 * 26/05/2023
 * Esta clase tiene las funciones necesarias para 
 * agregar o eliminar vehiculos al cátalogo, 
 * mostrar el catalogo, y una función para liberar
 * espacio de la memoria
 * 
 */

#ifndef CATALOGO_H
#define CATALOGO_H

# include "Vehiculo.h"
# include <iostream>
using namespace std;
#include <vector>


class Catalogo {
    //Declaro las variables de instancia privadas
    private:
        vector<Vehiculo*> vehiculos;

    //Declaro metodos públicos
    public:
        void agregar_vehiculo(Vehiculo* vehiculo) {
            vehiculos.push_back(vehiculo);
        }

    void eliminar_vehiculo(int indice) {
        if (indice >= 0 && indice < vehiculos.size()) {
            delete vehiculos[indice];
            vehiculos.erase(vehiculos.begin() + indice);
        }
    }

    void mostrar_catalogo() {
        for (size_t i = 0; i < vehiculos.size(); i++) {
            vehiculos[i]->mostrar_vehiculo();
            cout << endl;
        }
    }

    ~Catalogo() {
        for (size_t i = 0; i < vehiculos.size(); i++) {
            delete vehiculos[i];
        }
    }
    
};

#endif
