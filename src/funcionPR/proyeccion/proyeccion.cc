#include "proyeccion.h"

/**
 * @brief Método para evaluar la función de proyección.
 * @param args Vector de argumentos.
 * @return Retorna el valor del argumento en la posición especificada por 'indice'.
 */
int Proyeccion::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (indice < 0 || indice >= args.size()) {
    throw out_of_range("Índice de proyección fuera de rango.");
  }
  return args[indice];
}