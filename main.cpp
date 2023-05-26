/*
 *
 * Proyecto Agencia main
 * María José Gaytán Gil
 * A01706616
 * 26/05/2023
 * 
 */

# include "Catalogo.h"
# include <iostream>
using namespace std;
#include <vector>

int main(){
    Catalogo catalogo;

    catalogo.agregar_vehiculo(new Coche("Ford", "Focus", 2021, 200000.0, "normal"));
    catalogo.agregar_vehiculo(new Moto("Ducati", "Panigale V4", 2022, 50000.0, 2));
    catalogo.agregar_vehiculo(new Camioneta("Jeep", "Wrangler", 2020, 300000.0, "Deportiva"));
    catalogo.agregar_vehiculo(new Moto("Yamaha", "YZF-R6", 2017, 57600.0, 3));

    catalogo.mostrar_catalogo();
    catalogo.eliminar_vehiculo(1);
    catalogo.mostrar_catalogo();
    catalogo.eliminar_vehiculo(1);
    catalogo.mostrar_catalogo();
    
    return 0;
};
