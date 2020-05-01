//
// Created by jneira on 2020-04-30.
//

#ifndef _SISTEMA_LOGISTICO_CPP
#define _SISTEMA_LOGISTICO_CPP

#include "sistema_logistico.h"
#include "orden.h"
#include "orden.cpp"

sistema_logistico::sistema_logistico(){
    cout << "Sistema de logística iniciado.\n";
}

void sistema_logistico::add_user(string _username, string _password){
    if(listaUsuarios.size() != 0){
        auto it = listaUsuarios.find(_username);
        if(it != listaUsuarios.end()){
            cout << "\t\tYa existe el usuario " << _username << ".\n";
        }else{
            listaUsuarios[_username] = _password;
            cout << "\t\tUsuario \"" << _username << "\" creado con éxito.\n";
        }
    }else{
        listaUsuarios[_username] = _password;
        cout << "\t\tUsuario \"" << _username << "\" creado con éxito.\n";
    }

}

void sistema_logistico::agregar_orden(string _username, list<string> _cosas, list<int> _cantidades, list<int> _costos, string _id){
    if(_cosas.size() > 0){
        orden nueva_orden(_username, _cosas, _cantidades, _costos, _id);
        nueva_orden.setEstado("POR PAGAR");
        listaOrdenes.push_back(nueva_orden);
        cout << "\t\tSe agregó la orden " << _id << " al sistema.\n";
    } else
        cout << "No se puede crear una orden vacía\n";
}

void sistema_logistico::consulta(string _username){
    if(listaUsuarios.find(_username) != listaUsuarios.end()){
        int contPorPagar = 0;
        int contCancelado = 0;
        int contProcesando = 0;
        int contEnviado = 0;

        for(auto i:listaOrdenes){
            if(i.getUsername() == _username){
                if(i.getEstado() == "POR PAGAR")    contPorPagar++;
                if(i.getEstado() == "CANCELADO")    contCancelado++;
                if(i.getEstado() == "PROCESANDO")    contProcesando++;
                if(i.getEstado() == "ENVIADO")    contEnviado++;
            }
        }
        cout << "\t\tEl usuario " << _username << " tiene:\n";
        cout << "\t\t\t" << contPorPagar << " órden(es) por pagar.\n";
        cout << "\t\t\t" << contCancelado << " órden(es) cancelada(s).\n";
        cout << "\t\t\t" << contProcesando << " órden(es) procesada(s).\n";
        cout << "\t\t\t" << contEnviado << " órden(es) enviada(s).\n";
    }else{
        cout << "\t\tUsuario no existe\n";
    }
}

void sistema_logistico::pagar_orden(string _username){
    if(listaUsuarios.find(_username) != listaUsuarios.end()){
        int pago=0;
        for(auto it=listaOrdenes.begin(); it!=listaOrdenes.end(); it++){
            if(it->getUsername() == _username && it->getEstado() == "POR PAGAR"){
                it->setEstado("CANCELADO");
                pago += it->costosTotales;
            }
        }
        cout << "\t\tSe pagó " << pago << " soles por las órdenes de " << _username << ".\n";
    }else{
        cout << "\t\tUsuario no existe\n";
    }
}

void sistema_logistico::set_transporte(string _username){
    cout << "\t\tDistancia a la casa de " << _username << " 20 Km\n";
    if(listaUsuarios.find(_username) != listaUsuarios.end()){
        int a = 0;
        string transporte;
        for(auto it=listaOrdenes.begin(); it!=listaOrdenes.end(); it++){
            if(it->getUsername() == _username && it->getEstado() == "CANCELADO"){
                if(a%2){
                    transporte = "CAMION";
                }else{
                    transporte = "BICICLETA";
                }
                it->setTransporte(transporte, 20);
                cout << "\t\tOrden " << it->getId() << " enviada por " << transporte << " demorará " << it->getDistanciaTransporte() << " días\n";
                a++;
                it->setEstado("PROCESANDO");
            }
        }
    }else{
        cout << "\t\tUsuario no existe\n";
    }
}

void sistema_logistico::confirma(string _username){
    if(listaUsuarios.find(_username) != listaUsuarios.end()){
        for(auto it=listaOrdenes.begin(); it!=listaOrdenes.end(); it++){
            if(it->getUsername() == _username && it->getEstado() == "PROCESANDO")
                it->setEstado("ENVIADO");
        }
    }else {
        cout << "\t\tUsuario no existe\n";
    }
}

#endif //_SISTEMA_LOGISTICO_CPP