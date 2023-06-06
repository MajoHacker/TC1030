/*
 *
 * Proyecto Agencia clase Catalogo
 * María José Gaytán Gil
 * A01706616
 * 16/06/2023
 * Esta clase tiene las funciones necesarias para 
 * agregar o eliminar vehiculos al cátalogo y 
 * mostrar el catalogo
 * 
 */

#ifndef CATALOGO_H
#define CATALOGO_H

# include "Vehiculo.h" //Biblioteca con mis objetos a usar

# include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Catalogo {

    //Declaro las variables de instancia privadas
    private:
        //Un vector con apuntadores de vehiculo para usar polimorfismo
        vector<Vehiculo*> vehiculos;

    //Declaro metodos públicos
    public:
        void agregar_vehiculo(Vehiculo* vehiculo);
        void eliminar_vehiculo(int indice);
        void mostrar_catalogo();

};

/*
* agregar_vehiculo agrega un vehiculo al catalogo al agregar este 
* al vector utilizando push_back que se utuliza para agregar 
* elementos al final de un vector
*
* recibe un apuntador a un vehiculo 
*/
    void Catalogo::agregar_vehiculo(Vehiculo* vehiculo) {
         vehiculos.push_back(vehiculo);
    }

/*
* eliminar_vehiculo elimina un vehiculo del catalogo, eliminando este
* del vector
* 
* primero verifica que el indice este dentro del rango del vector
* con size
* 
* delete se utiliza para liberar la memoria asignada dinámicamente 
* para un objeto.
* 
* erase se utiliza para eliminar un elemento de un vector
* 
* begin devuelve un iterador que apunta al primer elemento del vector,
* y al sumarle el indice, se obtiene un iterador que apunta al elemento
* que se desea eliminar
* 
* recibe el indice del vehiculo que se desea eliminar
*/
    void Catalogo::eliminar_vehiculo(int indice) {
        if (indice >= 0 and indice < vehiculos.size()) {
            delete vehiculos[indice];
            vehiculos.erase(vehiculos.begin() + indice);
         }
    }

/*
* mostrar_vehiculo muestra el catalogo de vehiculos 
*
* llamando a la funcion mostrar_vehiculo
* 
* size se utiliza para determinar cuántos vehículos hay en el
* catalogo y garantizar que se recorran todos los elementos 
*/
    void Catalogo::mostrar_catalogo() {
    cout << "----- Catálogo de Vehículos -----" << endl;
        for (size_t indice = 0; indice < vehiculos.size(); indice++) {
            cout << "Índice: " << indice << endl;
            cout << vehiculos[indice]->mostrar_vehiculo() << endl;
        }
    cout << "---------------------------------" << endl;
    }

#endif //CATALOGO_H
