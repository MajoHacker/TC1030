/*
 * Proyecto Agencia main
 * María José Gaytán Gil
 * A01706616
 * 16/06/2023
 * 
 * Este proyecto trata sobre una agencia de coches, 
 * en donde cada usuario, que es un trabajador de la
 * agencia, tiene la capacidad de agregar o quitar vehículos
 * del catálogo de la agencia.
 */

#include <iostream> // Para imprimir
#include <vector>
#include <string>
#include "Catalogo.h" // Bibliotecas con objetos de mi proyecto
#include "Vehiculo.h"

using namespace std;

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

    // Coches creados por default:
    Vehiculo* cochedefault(new Coche("Ford", "Focus", 2021, 200000.0, "normal"));
    Vehiculo* motodefault(new Moto("Ducati", "Panigale V4", 2022, 50000.0, 2));
    Vehiculo* camionetadefault(new Camioneta("Jeep", "Wrangler", 2020, 300000.0, "Deportiva"));
    catalogo.agregar_vehiculo(cochedefault);
    catalogo.agregar_vehiculo(motodefault);
    catalogo.agregar_vehiculo(camionetadefault);
    

    // Registro de usuario:
    do {
        cout << "Ingresa tu nombre de usuario: ";
        cin >> usuario;

        // Condición para validar usuario
        if (usuario == "benjamin" or usuario == "majo") {
            cout << "Acceso concedido" << endl;
            break;
        } 
        else {
            cout << "Usuario incorrecto. Intenta nuevamente." << endl;
        }
    } 
    while (true);

    // Ciclo do-while para preguntarle varias veces al usuario la opción que desea:
    do {
        // Opciones para el usuario:
        cout << "\nLas opciones disponibles son:\n";
        cout << "1-Ver catálogo\n";
        cout << "2-Agregar vehículo\n";
        cout << "3-Eliminar vehículo\n";
        cout << "4-Terminar programa\n";
        cout << "¿Qué deseas hacer? ";
        cin >> respuesta;

        // Ciclo while para validar respuestas:
        while (respuesta != 1 and respuesta != 2 and respuesta != 3 and respuesta != 4){
            cout << "Respuesta inválida. Por favor, ingresa 1, 2, 3 o 4." << endl;
            cin >> respuesta;
        }

        // Condiciones para realizar lo que el usuario quiera:
        if (respuesta == 1) {
            catalogo.mostrar_catalogo();
        } 
        else if (respuesta == 2) {
            cout << "\nIngrese la marca del vehículo: ";
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
                Vehiculo* vehiculo(new Moto(marca, modelo, anio, precio, num_llantas));
                catalogo.agregar_vehiculo(vehiculo);
                cout << "\nVehículo añadido correctamente." << endl;
            } 
            else if (opcion_vehiculo == 2) {
                cout << "Ingresa el tipo de coche: ";
                cin >> tipo_coche;
                Vehiculo* vehiculo(new Coche(marca, modelo, anio, precio, tipo_coche));
                catalogo.agregar_vehiculo(vehiculo);
                cout << "\nVehículo añadido correctamente." << endl;
            } 
            else if (opcion_vehiculo == 3) {
                cout << "Ingresa el tipo de camioneta: ";
                cin >> tipo_camioneta;
                Vehiculo* vehiculo(new Camioneta(marca, modelo, anio, precio, tipo_camioneta));
                catalogo.agregar_vehiculo(vehiculo);
                cout << "\nVehículo añadido correctamente." << endl;
            }
        } 
        else if (respuesta == 3) {
            catalogo.mostrar_catalogo();
            cout << "Ingrese el índice del vehículo que desea eliminar: ";
            cin >> indice;
            catalogo.eliminar_vehiculo(indice);
            cout << "Vehículo eliminado correctamente." << endl;
        }
    } 
    while (respuesta != 4);
        cout << "\nHasta luego, " << usuario << "!" << endl;
    return 0;
};
