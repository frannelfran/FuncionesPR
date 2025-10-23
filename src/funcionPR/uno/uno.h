#ifndef UNO_H
#define UNO_H

#include "../funcionPR.h"

/**
 * @class Clase que representa la función constante uno en funciones primitivas recursivas.
 */
class Uno : public FuncionPR {
  public:
    // Constructor y destructor
    Uno() = default;
    ~Uno() = default;
    // Método para evaluar la función uno
    int evaluar(const vector<int>& args) override;
};

#endif // UNO_H
