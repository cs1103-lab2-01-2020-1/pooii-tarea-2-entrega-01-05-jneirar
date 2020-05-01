//
// Created by jneira on 2020-04-30.
//

#ifndef _SISTEMA_LOGISTICO_H
#define _SISTEMA_LOGISTICO_H

#include "../lib.h"
#include "orden.h"

class sistema_logistico {
private:
    unordered_map<string, string> listaUsuarios;
    list<orden> listaOrdenes;
public:
    sistema_logistico();
    void add_user(string _username, string _password);
    void agregar_orden(string _username, list<string> _cosas, list<int> _cantidades, list<int> _costos, string _id);
    void consulta(string _username);
    void pagar_orden(string _username);
    void set_transporte(string _username);
    void confirma(string _username);
};


#endif //_SISTEMA_LOGISTICO_H
