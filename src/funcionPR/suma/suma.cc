#include "suma.h"

/**
 * @brief Método para evaluar la función suma.
 * @param args Vector de argumentos (se esperan dos argumentos).
 * @return Retorna la suma de los dos argumentos dados.
 */
int Suma::evaluar(const vector<int>& args) {
  if (args.size() != 2) {
    throw invalid_argument("Se esperan exactamente dos argumentos.");
  }
  // Obtengo los argumentos usando la función de proyección
  int x = Proyeccion(0).evaluar(args);
  int y = Proyeccion(1).evaluar(args);
  llamadas++;

  if (y == 0) {
    return x;
  } else {
    return Sucesor().evaluar({this->evaluar({x, y - 1})});
  }
}
