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

int main() {
    // Variables necesarias:
    string usuario;
    int respuesta;
    Catalogo catalogo;
    string marca;
    string modelo;
    int anio;
    double precio;
    int num_llantas;
    string tipo_coche;
    string tipo_camioneta;
    int opcion_vehiculo;
    int indice;

    // Coches creados por defecto:
    catalogo.agregar_vehiculo(new Coche("Ford", "Focus", 2021, 200000.0, "normal"));
    catalogo.agregar_vehiculo(new Moto("Ducati", "Panigale V4", 2022, 50000.0, 2));
    catalogo.agregar_vehiculo(new Camioneta("Jeep", "Wrangler", 2020, 300000.0, "Deportiva"));
    catalogo.agregar_vehiculo(new Moto("Yamaha", "YZF-R6", 2017, 57600.0, 3));

    // Registro de usuario:
    cout << "Ingresa tu usuario para comenzar: ";
    cin >> usuario;
    cout << "\nPerfecto, " << usuario << " comencemos:" << endl;

    // Ciclo do-while para preguntarle varias veces al usuario la opción que desea:
    do {
        // Opciones para el usuario:
        cout << "\nLas opciones disponibles son:\n1-Ver catálogo\n2-Agregar vehículo\n3-Eliminar vehículo\n4-Terminar programa" << endl;
        cout << "\n¿Qué deseas hacer?: ";
        cin >> respuesta;

        // Ciclo while para validar respuestas:
        while (respuesta != 1 and respuesta != 2 and respuesta != 3 and respuesta != 4) {
            cout << "Respuesta inválida. Por favor, ingresa 1, 2, 3 o 4." << endl;
            cin >> respuesta;
        }

        // Condiciones para realizar lo que el usuario quiera:
        if (respuesta == 1) {
            catalogo.mostrar_catalogo();
        }
        else if (respuesta == 2) {
            cout << "Ingrese la marca del vehículo: ";
            cin >> marca;
            cout << "Ingrese el modelo del vehículo: ";
            cin >> modelo;
            cout << "Ingrese el año del vehículo: ";
            cin >> anio;
            cout << "Ingrese el precio del vehículo: ";
            cin >> precio;
            cout << "Seleccione el tipo de vehículo:\n";
            cout << "1. Moto\n";
            cout << "2. Coche\n";
            cout << "3. Camioneta\n";
            cin >> opcion_vehiculo;

            // Ciclo para validar respuesta de opcion_vehiculo
            while (opcion_vehiculo != 1 and opcion_vehiculo != 2 and opcion_vehiculo != 3) {
                cout << "Respuesta inválida. Por favor, ingresa 1, 2 o 3." << endl;
                cin >> opcion_vehiculo;
            }

            // Condiciones dependiendo del tipo de vehículo elegido por el usuario:
            if (opcion_vehiculo == 1) {
                cout << "Ingresa el número de llantas de la moto: ";
                cin >> num_llantas;
                catalogo.agregar_vehiculo(new Moto(marca, modelo, anio, precio, num_llantas));
                cout << "Vehículo añadido correctamente." << endl;
            }
            else if (opcion_vehiculo == 2) {
                cout << "Ingresa el tipo de coche: ";
                cin >> tipo_coche;
                catalogo.agregar_vehiculo(new Coche(marca, modelo, anio, precio, tipo_coche));
                 cout << "Vehículo añadido correctamente." << endl;
            }
            else if (opcion_vehiculo == 3) {
                cout << "Ingresa el tipo de camioneta: ";
                cin >> tipo_camioneta;
                catalogo.agregar_vehiculo(new Camioneta(marca, modelo, anio, precio, tipo_camioneta));
                cout << "Vehículo añadido correctamente." << endl;
            }
        }
        else if (respuesta == 3) {
            cout << "NOTA: El indice empieza en 0" << endl;
            cout << "Ingrese el índice del vehículo que desea eliminar: ";
            cin >> indice;
            catalogo.eliminar_vehiculo(indice);
            cout << "Vehículo eliminado correctamente." << endl;
        }
    } 
    while (respuesta != 4);
        cout << "\nGracias por usar el programa. ¡Hasta luego!" << endl;
    return 0;
};
