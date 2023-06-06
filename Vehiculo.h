/*
 *
 * Proyecto Agencia clase Vehiculo
 * María José Gaytán Gil
 * A01706616
 * 16/06/2023
 * Esta clase define objeto de tipo Vehiculo que contiene las clases heredadas
 * Moto, Coche, Camioneta.
 * 
 */

#ifndef VEHICULO_H
#define VEHICULO_H

# include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Declaracion de clase Vehiculo que es abstracta
class Vehiculo{

    // Declaro las variables de instancia protegidas
    protected:
        string marca;
        string modelo;
        int anio;
        double precio;

    //Declaro los métodos que va a tener el objeto
    public:

        Vehiculo(string _marca, string _modelo, int _anio, double _precio)
            : marca(_marca), modelo(_modelo), anio(_anio), precio(_precio) {
            } 

        //Método abstracto será sobreescrito
        virtual string mostrar_vehiculo() = 0;

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

        // Destructor virtual
        virtual ~Vehiculo() {
        }
};

//Declaro objeto Moto que hereda de Vehiculo
class Moto : public Vehiculo{

    //Declaro las variables de instancia privadas
    private:
    int num_llantas;

    //Declaro metodos públicos del objeto
    public:

        Moto(string _marca, string _modelo, int _anio, double _precio, int _numero_llantas)
        : Vehiculo(_marca, _modelo, _anio, _precio), num_llantas(_numero_llantas) {
        }

        string mostrar_vehiculo();

        //Getter
        int get_num_llantas(){
            return num_llantas;
        }
};

/*
* mostrar_vehiculo convierte a atributos a string.
*
* concatena todos los valores de los atributos en un string para ser impreso
*
* @param
* @return string con los valores y texto concatenado.
*/

string Moto::mostrar_vehiculo() {
    stringstream aux;
    aux << "Moto: ";
    aux << "Marca: " << marca << ", Modelo: " << modelo << ", Año: " << anio << ", Precio: " << precio << endl;
    aux << "Número de llantas: " << num_llantas << endl;
    return aux.str();
}


//Declaro objeto Coche que hereda de Vehiculo
class Coche : public Vehiculo{

    //Declaro las variables de instancia privadas
    private:
    string tipo_coche;

    //Declaro metodos públicos del objeto
    public:
        
        Coche(string _marca, string _modelo, int _anio, double _precio, string _tipo_coche)
        : Vehiculo(_marca, _modelo, _anio, _precio), tipo_coche(_tipo_coche) {
        }

        string mostrar_vehiculo(); 

        //Getter
        string get_tipo_coche(){
            return tipo_coche;
        }
};

/*
* mostrar_vehiculo convierte a atributos a string.
*
* concatena todos los valores de los atributos en un string para ser impreso
*
* @param
* @return string con los valores y texto concatenado.
*/

string Coche::mostrar_vehiculo() {
    stringstream aux;
    aux << "Coche: ";
    aux << "Marca: " << marca << ", Modelo: " << modelo << ", Año: " << anio << ", Precio: " << precio << endl;
    aux << "Tipo de coche: " << tipo_coche << endl;
    return aux.str();
}


//Declaro objeto Camioneta que hereda de Vehiculo
class Camioneta : public Vehiculo{

    //Declaro las variables de instancia privadas
    private:
    string tipo_camioneta;

    //Declaro metodos públicos del objeto
    public:

        Camioneta(string _marca, string _modelo, int _anio, double _precio, string _tipo_camioneta)
        : Vehiculo(_marca, _modelo, _anio, _precio), tipo_camioneta(_tipo_camioneta) {
        }

        string mostrar_vehiculo();

        //Getter
        string get_tipo_camioneta(){
            return tipo_camioneta;
        }
};

/*
* mostrar_vehiculo convierte a atributos a string.
*
* concatena todos los valores de los atributos en un string para ser impreso
*
* @param
* @return string con los valores y texto concatenado.
*/

string Camioneta::mostrar_vehiculo() {
    stringstream aux;
    aux << "Camioneta: ";
    aux << "Marca: " << marca << ", Modelo: " << modelo << ", Año: " << anio << ", Precio: " << precio << endl;
    aux << "Tipo de camioneta: " << tipo_camioneta << endl;
    return aux.str();
}

#endif // VEHICULO_H
