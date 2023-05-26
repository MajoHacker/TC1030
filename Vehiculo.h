/*
 *
 * Proyecto Agencia clase Vehiculo
 * María José Gaytán Gil
 * A01706616
 * 26/05/2023
 * Esta clase define objeto de tipo Vehiculo que contiene las clases heredadas
 * Moto, Coche, Camioneta.
 * 
 */

#ifndef VEHICULO_H
#define VEHICULO_H

# include <iostream>
using namespace std;
#include <vector>


//Declaracion de clase Vehiculo que es abstracta
class Vehiculo{
    // Declaro las variables de instancia protegidas
    protected:
        string marca;
        string modelo;
        int anio;
        double precio;

    public:
    //Declaro métodos públicos
        Vehiculo(string _marca, string _modelo, int _anio, double _precio)
            : marca(_marca), modelo(_modelo), anio(_anio), precio(_precio) {}

        virtual void mostrar_vehiculo() {
            cout << "Marca: " << marca << ", Modelo: " << modelo << ", Año: " << anio << ", Precio: " << precio << endl;
    }
    //Getters
    string get_marca(){
        return marca;
    }
    string get_modelo(){
        return modelo;
    }
    int get_anio(){
        return anio;
    }
    double get_precio(){
        return precio;
    }
};

//Declaro objeto Moto que hereda de Vehiculo
class Moto : public Vehiculo{

    //Declaro las variables de instancia privadas
    private:
    int num_llantas;

    //Declaro metodos públicos
    public:
    Moto(string _marca, string _modelo, int _anio, double _precio, int _numero_llantas)
        : Vehiculo(_marca, _modelo, _anio, _precio), num_llantas(_numero_llantas) {
        }

    void mostrar_vehiculo() {
        cout << "Moto: ";
        Vehiculo::mostrar_vehiculo();
        cout << "Número de llantas: " << num_llantas << endl;
    }
};

//Declaro objeto Coche que hereda de Vehiculo
class Coche : public Vehiculo{

    //Declaro las variables de instancia privadas
    private:
    string tipo_coche;

    //Declaro metodos públicos
    public:
    Coche(string _marca, string _modelo, int _anio, double _precio, string _tipo_coche)
        : Vehiculo(_marca, _modelo, _anio, _precio), tipo_coche(_tipo_coche) {
        }

    void mostrar_vehiculo() {
        cout << "Coche: ";
        Vehiculo::mostrar_vehiculo();
        cout << "Tipo de coche: " << tipo_coche << endl;
    }
};

//Declaro objeto Camioneta que hereda de Vehiculo
class Camioneta : public Vehiculo{

    //Declaro las variables de instancia privadas
    private:
    string tipo_camioneta;

    //Declaro metodos públicos
    public:
    Camioneta(string _marca, string _modelo, int _anio, double _precio, string _tipo_camioneta)
        : Vehiculo(_marca, _modelo, _anio, _precio), tipo_camioneta(_tipo_camioneta) {
        }

    void mostrar_vehiculo() {
        cout << "Camioneta: ";
        Vehiculo::mostrar_vehiculo();
        cout << "Tipo de camioneta: " << tipo_camioneta << endl;
    }
};

#endif