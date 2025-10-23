#ifndef SUCESOR_H
#define SUCESOR_H

#include "../funcionPR.h"
#include "../proyeccion/proyeccion.h"

/**
 * @class Clase que representa la función sucesor en funciones primitivas recursivas.
 */

class Sucesor : public FuncionPR {
  public:
    // Constructor y destructor
    Sucesor() = default;
    ~Sucesor() = default;

    // Método para evaluar la función sucesor
    int evaluar(const vector<int>& args) override;
};

#endif // SUCESOR_H
