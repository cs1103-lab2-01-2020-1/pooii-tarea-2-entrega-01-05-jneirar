//
// Created by jneira on 2020-05-01.
//

#include "LIFO.h"
LIFO::LIFO(int _n) {
    n = _n;
    tail = -1;
    data = new int [n];
}

LIFO::~LIFO(){
    delete [] data;
}

void LIFO::push(int val) {
    if(tail != n-1) {
        tail++;
        data[tail] = val;
    }
}

int LIFO::top() {
    if(tail != -1)
        return data[tail];
}

void LIFO::pop() {
    if(tail != -1)
        tail--;
}

int LIFO::getSize() {
    return tail + 1;
}

void LIFO::imprime(){
    for(int i=0; i<=tail; i++)
        cout << data[i] << " ";
    cout << "\n";
}