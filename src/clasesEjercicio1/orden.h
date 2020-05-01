//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_ORDEN_H
#define TAREA3_ORDEN_H

#include "../lib.h"
#include "camion.h"
#include "camion.cpp"
#include "bicicleta.h"
#include "bicicleta.cpp"

class orden {
private:
    string username;
    string estado;
    list<string> cosas;
    list<int> cantidades;
    list<int> costos;
    vehiculo *transporte = nullptr;
    string id;
public:
    orden(string _username, list<string> _cosas, list<int> _cantidades, list<int> _costos, string _id);
    ~orden();
    int costosTotales;
    int calcular_costo_total();
    string getUsername();
    string getEstado();
    void setEstado(string _estado);
    void setTransporte(string _transporte, int _distancia);
    int getDistanciaTransporte();
    string getId();
};


#endif //TAREA3_ORDEN_H
