//
// Created by jneira on 2020-04-30.
//

#ifndef TAREA3_LIFO_H
#define TAREA3_LIFO_H

#include "../lib.h"

class LIFO{
    int *data;
    int n;
    int tail;
public:
    LIFO(int _n);
    ~LIFO();
    void push(int val);
    int top();
    void pop();
    int getSize();
    void imprime();
};

#endif //TAREA3_LIFO_H