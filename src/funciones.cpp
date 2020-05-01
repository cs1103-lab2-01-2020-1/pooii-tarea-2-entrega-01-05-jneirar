//
// Created by jneira on 2020-04-30.
//

#include "funciones.h"

void print_lifo(LIFO lifo){
    cout << "\tImprimir LIFO\n\t\t";
    cout << lifo.getSize() << endl;
    while(lifo.getSize() != 0){
        cout << lifo.top() << " ";
        lifo.pop();
    }
    cout << "\n";
}

void print_lista(list<int> l){
    for(auto i : l)
        cout << i << " ";
    cout << "\n";
}