#include "producto.h"

/**
 * @brief Método para evaluar la función producto.
 * @param args Vector de argumentos (se esperan dos argumentos).
 * @return Retorna el producto de los dos argumentos dados.
 */
int Producto::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (args.size() != 2) {
    throw invalid_argument("Se esperan exactamente dos argumentos.");
  }
  // Obtengo los argumentos
  int x = args[0];
  int y = args[1];

  if (y == 0) {
    return 0;
  } else {
    return Suma().evaluar({x, this->evaluar({x, y - 1})});
  }
}