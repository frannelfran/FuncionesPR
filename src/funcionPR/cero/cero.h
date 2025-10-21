#ifndef CERO_H
#define CERO_H

#include "../funcionPR.h"

/**
 * @class Clase que representa la función cero en funciones primitivas recursivas.
 */

class Cero : public FuncionPR {
  public:
    // Constructor y destructor
    Cero() = default;
    ~Cero() = default;

    // Método para evaluar la función cero
    int evaluar(const vector<int>& args) override;
};

#endif // CERO_H
