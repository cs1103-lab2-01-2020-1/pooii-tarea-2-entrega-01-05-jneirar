//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_CAMION_H
#define TAREA3_CAMION_H

#include "vehiculo.h"

class camion: public vehiculo {
public:
    camion(int _distancia);
    void calculo_tiempo_minimo() override;
};


#endif //TAREA3_CAMION_H
