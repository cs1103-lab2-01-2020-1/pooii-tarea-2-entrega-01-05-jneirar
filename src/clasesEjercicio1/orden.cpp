//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_ORDEN_CPP
#define TAREA3_ORDEN_CPP

#include "orden.h"

orden::orden(string _username, list<string> _cosas, list<int> _cantidades, list<int> _costos, string _id){
    int n = _cosas.size();
    username = _username;
    cosas.resize(n);
    cantidades.resize(n);
    costos.resize(n);
    copy(_cosas.begin(), _cosas.end(), cosas.begin());
    copy(_cantidades.begin(), _cantidades.end(), cantidades.begin());
    copy(_costos.begin(), _costos.end(), costos.begin());
    costosTotales = calcular_costo_total();
    id = _id;
}

orden::~orden() {
    transporte = nullptr;
}
int orden::calcular_costo_total(){
    int acc = 0;
    auto it2 = costos.begin();
    for(auto it = cantidades.begin(); it != cantidades.end(); it++){
        acc += *(it) * *(it2);
        it2++;
    }
    return acc;
}

string orden::getUsername(){
    return username;
}
string orden::getEstado(){
    return estado;
}
void orden::setEstado(string _estado){
    estado = _estado;
}

void orden::setTransporte(string _transporte, int _distancia){
    if(_transporte == "CAMION"){
        transporte = new camion(_distancia);
    }else if(_transporte == "BICICLETA"){
        transporte = new bicicleta(_distancia);
    }
    transporte->calculo_tiempo_minimo();
}

int orden::getDistanciaTransporte(){
    return transporte->gettiempominimo();
}

string orden::getId() {
    return id;
}

#endif //TAREA3_ORDEN_CPP