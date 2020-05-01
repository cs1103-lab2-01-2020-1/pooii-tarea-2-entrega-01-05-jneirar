//
// Created by jneira on 2020-04-30.
//

#include "bicicleta.h"

bicicleta::bicicleta(int _distancia):vehiculo(_distancia) {

}
void bicicleta::calculo_tiempo_minimo() {
    tiempo_minimo_para_despacho = distancia / 4;
}