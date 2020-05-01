//
// Created by jneira on 2020-04-30.
//

#include "ejercicios.h"
#include "funciones.h"
#include "clasesEjercicio1/sistema_logistico.h"
#include "clasesEjercicio1/sistema_logistico.cpp"
#include "Ejercicio2/LIFO.h"
#include "Ejercicio2/LIFO.cpp"
#include "Ejercicio3/LIFO_T.h"
#include "Ejercicio3/LIFO_T.cpp"

void ejercicio1(){
    sistema_logistico SL;

    cout << "\n\tCreando usuarios.\n";
    SL.add_user("Jorge", "1234");
    SL.add_user("Jorge", "136");

    cout << "\n\tCreando lista de cosas, con sus cantidades y precios.\n";
    list<string> cosas;
    list<int> cantidades;
    list<int> costos;
    cosas.push_back("Fideos"); cantidades.push_back(4); costos.push_back(3);
    cosas.push_back("Arroz"); cantidades.push_back(10); costos.push_back(4);
    cosas.push_back("Azucar"); cantidades.push_back(5); costos.push_back(7);

    cout << "\tAgregar lista a una orden para el usuario Jorge.\n";
    SL.agregar_orden("Jorge",cosas, cantidades, costos, "0001");

    cout << "\tCreando otra lista de cosas, con sus cantidades y precios.\n";
    cosas.clear();
    cantidades.clear();
    costos.clear();
    cosas.push_back("Atún"); cantidades.push_back(6); costos.push_back(7);
    cosas.push_back("Galletas"); cantidades.push_back(25); costos.push_back(1);

    cout << "\tAgregar otra orden para el usuario Jorge.\n";
    SL.agregar_orden("Jorge",cosas, cantidades, costos, "0002");

    cout << "\n\tConsultar estado de órdenes de Jorge\n";
    SL.consulta("Jorge");

    cout << "\n\tPagar órdenes de Jorge\n";
    SL.pagar_orden("Jorge");

    cout << "\n\tConsultar estado de órdenes de Jorge\n";
    SL.consulta("Jorge");

    cout << "\n\tConfigurar el vehículo de transporte luego de pagar las órdenes de Jorge\n";
    cout << "\tConsiderar que cada vehículo tiene una forma distinta para calcular el tiempo de envío de acuerdo a la distancia\n";
    cout << "\tPara esta parte se usó herencia desde la clase abstracta vehículo y polimorfismo para los cálculos de tiempo.\n";
    SL.set_transporte("Jorge");

    cout << "\n\tConsultar estado de órdenes de Jorge\n";
    SL.consulta("Jorge");

    cout << "\n\tConfirmar recepción de órdenes de Jorge\n";
    SL.confirma("Jorge");

    cout << "\tConsultar estado de órdenes de Jorge\n";
    SL.consulta("Jorge");
}

void ejercicio2(){
    cout << "\tCreando lifo de tamaño 5\n";
    LIFO lifo(5);
    cout << "\tLIFO.push(2)\n\t\t";
    lifo.push(2);
    lifo.imprime();

    cout << "\tLIFO.push 6 y 8\n\t\t";
    lifo.push(6);
    lifo.imprime();

    cout << "\t\t";
    lifo.push(8);
    lifo.imprime();
    cout << "\tTamaño: " << lifo.getSize() << "\n";
    cout << "\tLIFO.top: ";
    cout << lifo.top() << "\n";

    cout << "\tLIFO.pop()\n";
    lifo.pop();
    cout << "\tLIFO.top: ";
    cout << lifo.top() << "\n\t\t";
    lifo.imprime();
    cout << "\tTamaño: " << lifo.getSize() << "\n";
}


void ejercicio3(){
    int arr1[] = {10, 20, 50, 60, 30};
    int arr2[] = {70, 40, 80, 20, 10, 40};
    int n1 = 5, n2 = 6;

    list<int> l1(arr1, arr1 + n1);
    list<int> l2(arr2, arr2 + n2);

    cout << "\tList l1:\n\t\t";
    print_lista(l1);
    cout << "\tList l2:\n\t\t";
    print_lista(l2);

    cout << "\tMerge L2 in L1\n\t\t";
    l1.merge(l2);
    print_lista(l1);

    cout << "\tSort L1\n\t\t";
    l1.sort();
    print_lista(l1);

    int n = 20;
    if (binary_search(l1.begin(), l1.end(), n))
        cout << "\tSe encontró el valor " << n << "\n";
    else
        cout << "\tNo se encontró el valor " << n << "\n";

    n = 45;
    if (binary_search(l1.begin(), l1.end(), n))
        cout << "\tSe encontró el valor " << n << "\n";
    else
        cout << "\tNo se encontró el valor " << n << "\n";
    auto it = lower_bound(l1.begin(), l1.end(), n);

    cout << "\tEl lower_bound de: " << n << " es " << *it << "\n";
    int Max = *max_element(l1.begin(), l1.end());
    it = lower_bound(l1.begin(), l1.end(), Max);
    cout << "\tEl máximo elemento del array es: " << Max << " y su lowe_bound es: " << *it << "\n";
}

void ejercicio4(){
    cout << "\tCreando lifo_t de strings tamaño 5\n";
    LIFO_T<string> lifo(5);
    cout << "\tLIFO.push(2)\n\t\t";
    lifo.push("Jorge");
    lifo.imprime();

    cout << "\tLIFO.push Andrea y Kelly\n\t\t";
    lifo.push("Andrea");
    lifo.imprime();

    cout << "\t\t";
    lifo.push("Kelly");
    lifo.imprime();
    cout << "\tTamaño: " << lifo.getSize() << "\n";
    cout << "\tLIFO.top: ";
    cout << lifo.top() << "\n";

    cout << "\tLIFO.pop()\n";
    lifo.pop();
    cout << "\tLIFO.top: ";
    cout << lifo.top() << "\n\t\t";
    lifo.imprime();
    cout << "\tTamaño: " << lifo.getSize() << "\n";
}