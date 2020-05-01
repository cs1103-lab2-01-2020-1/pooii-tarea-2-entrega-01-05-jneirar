//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_LIFO_T_H
#define TAREA3_LIFO_T_H

#include "../lib.h"

template <typename T>
class LIFO_T{
    T *data;
    int n;
    int tail;
public:
    LIFO_T(int _n);
    ~LIFO_T();
    void push(T val);
    T top();
    void pop();
    int getSize();
    void imprime();
};

#endif //TAREA3_LIFO_H