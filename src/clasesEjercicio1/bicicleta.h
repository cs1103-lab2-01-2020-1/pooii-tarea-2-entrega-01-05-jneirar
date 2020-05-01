//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_BICICLETA_H
#define TAREA3_BICICLETA_H

#include "vehiculo.h"

class bicicleta:public vehiculo {
public:
    bicicleta(int _distancia);
    void calculo_tiempo_minimo() override;
};


#endif //TAREA3_BICICLETA_H
