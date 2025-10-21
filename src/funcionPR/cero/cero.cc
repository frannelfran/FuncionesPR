#include "cero.h"

/**
 * @brief Método para evaluar la función cero.
 * @param args Vector de argumentos (no se utiliza en esta función).
 * @return Siempre retorna 0.
 */
int Cero::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  return 0;
}