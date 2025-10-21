#include "potencia.h"

/**
 * @brief Método para evaluar la función potencia.
 * @param args Vector de argumentos (se esperan dos argumentos).
 * @return Retorna el resultado de elevar el primer argumento a la potencia del segundo argumento.
 */
int Potencia::evaluar(const vector<int>& args) {
  if (args.size() != 2) {
    throw invalid_argument("Se esperan exactamente dos argumentos.");
  }
  // Obtengo los argumentos usando la función de proyección
  int base = Proyeccion(0).evaluar(args);
  int exponente = Proyeccion(1).evaluar(args);
  llamadas++;

  if (exponente == 0) {
    return Sucesor().evaluar({Cero().evaluar({})}); // base^0 = 1
  } else {
    return Producto().evaluar({base, this->evaluar({base, exponente - 1})});
  }
}