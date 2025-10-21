#ifndef POTENCIA_H
#define POTENCIA_H

#include "../funcionPR.h"
#include "../producto/producto.h"

/**
 * @class Clase que representa la función potencia en funciones primitivas recursivas.
 */
class Potencia : public FuncionPR {
  public:
    // Constructor y destructor
    Potencia() = default;
    ~Potencia() = default;

    // Método para evaluar la función potencia
    int evaluar(const vector<int>& args) override;
};

#endif // POTENCIA_H