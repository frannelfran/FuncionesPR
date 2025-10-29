#include "uno.h"

/**
 * @brief Método para evaluar la función uno.
 * @param args Vector de argumentos (se espera un solo argumento, pero no se usa).
 * @return Retorna el valor constante 1.
 */
int Uno::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  return Sucesor().evaluar({0});
}