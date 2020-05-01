//
// Created by jneira on 2020-05-01.
//

#include "LIFO_T.h"

template <typename T>
LIFO_T<T>::LIFO_T(int _n) {
    n = _n;
    tail = -1;
    data = new T[n];
}

template <typename T>
LIFO_T<T>::~LIFO_T() {
    delete [] data;
}

template <typename T>
void LIFO_T<T>::push(T val) {
    if(tail != n-1) {
        tail++;
        data[tail] = val;
    }
}

template <typename T>
T LIFO_T<T>::top() {
    if(tail != -1)
        return data[tail];
}

template <typename T>
void LIFO_T<T>::pop() {
    if(tail != -1)
        tail--;
}

template <typename T>
int LIFO_T<T>::getSize() {
    return tail + 1;
}

template <typename T>
void LIFO_T<T>::imprime(){
    for(int i=0; i<=tail; i++)
        cout << data[i] << " ";
    cout << "\n";
}