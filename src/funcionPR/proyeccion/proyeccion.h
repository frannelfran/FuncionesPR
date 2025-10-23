#ifndef PROYECCION_H
#define PROYECCION_H

#include "../funcionPR.h"

/**
 * @class Clase que representa la función de proyección en funciones primitivas recursivas.
 */
class Proyeccion : public FuncionPR {
  public:
    // Constructor y destructor
    Proyeccion(int indice) : indice(indice) {}
    ~Proyeccion() = default;

    // Método para evaluar la función de proyección
    int evaluar(const vector<int>& args) override;

  private:
    int indice; // Índice del argumento a proyectar
};

#endif // PROYECCION_H