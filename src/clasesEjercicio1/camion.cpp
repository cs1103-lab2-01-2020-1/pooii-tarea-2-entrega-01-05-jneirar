//
// Created by jneira on 2020-04-30.
//

#include "camion.h"
//#include "vehiculo.h"
#include "vehiculo.cpp"

camion::camion(int _distancia):vehiculo(_distancia) {}

void camion::calculo_tiempo_minimo() {
    tiempo_minimo_para_despacho = distancia / 10;
}