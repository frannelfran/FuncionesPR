#ifndef SUMA_H
#define SUMA_H

#include "../proyeccion/proyeccion.h"
#include "../sucesor/sucesor.h"

/**
 * @class Clase que representa la función suma en funciones primitivas recursivas.
 */
class Suma : public FuncionPR {
  public:
    // Constructor y destructor
    Suma() = default;
    ~Suma() = default;

    // Método para evaluar la función suma
    int evaluar(const vector<int>& args) override;
};

#endif // SUMA_H