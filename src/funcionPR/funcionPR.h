#ifndef FUNCIONESPR_H
#define FUNCIONESPR_H

#include <iostream>
#include <vector>
#include <stdexcept> // Para manejo de excepciones

using namespace std;

static int llamadas = 0;

/**
 * @class Clase que representa una función primitiva recursiva.
 */

class FuncionPR {
  public:
    // Constructor y destructor
    FuncionPR() = default;
    ~FuncionPR() = default;

    // Métodos
    virtual int evaluar(const vector<int>& args) = 0;

    // Contador
    static int contadorLlamadas;
};

#endif // FUNCIONESPR_H