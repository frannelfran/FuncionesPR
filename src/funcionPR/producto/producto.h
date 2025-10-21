#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "../suma/suma.h"
#include "../cero/cero.h"

/**
 * @class Clase que representa la función producto en funciones primitivas recursivas.
 */
class Producto : public FuncionPR {
  public:
    // Constructor y destructor
    Producto() = default;
    ~Producto() = default;

    // Método para evaluar la función producto
    int evaluar(const vector<int>& args) override;
};

#endif // PRODUCTO_H