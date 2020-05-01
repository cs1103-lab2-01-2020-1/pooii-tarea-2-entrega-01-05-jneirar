//
// Created by jneira on 2020-04-30.
//

#include "vehiculo.h"
vehiculo::vehiculo(int _distancia) {
    distancia = _distancia;
}

int vehiculo::gettiempominimo() {
    return tiempo_minimo_para_despacho;
}