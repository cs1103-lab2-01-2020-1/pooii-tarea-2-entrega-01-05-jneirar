//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_VEHICULO_H
#define TAREA3_VEHICULO_H

class vehiculo {
protected:
    int distancia;
    int tiempo_minimo_para_despacho;
public:
    vehiculo(int _distancia);
    int gettiempominimo();
    virtual void calculo_tiempo_minimo() = 0;
};


#endif //TAREA3_VEHICULO_H
