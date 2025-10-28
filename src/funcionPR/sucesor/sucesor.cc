#include "sucesor.h"

/**
 * @brief Método para evaluar la función sucesor.
 * @param args Vector de argumentos (se espera un solo argumento).
 * @return Retorna el sucesor del argumento dado (arg + 1).
 */
int Sucesor::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (args.size() != 1) {
    throw invalid_argument("Se espera un solo argumento.");
  }
  return Suma().evaluar({Proyeccion(0).evaluar(args), Uno().evaluar({})});
}
