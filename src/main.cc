#include "funcionPR/potencia/potencia.h"
#include "tools/tools.h"

int main() {
  cout << "Programa que evalua la función primitiva recursiva potencia: NxN -> N\n" << endl;
  cout << "Pulsar Ctrl+C para salir.\n" << endl;
  try {
    while (true) {
      cout << "Ingrese la base (entero no negativo): ";
      int base;
      cin >> base;
      comprobarEntrada(base);
      cout << "Ingrese el exponente (entero no negativo): ";
      int exponente;
      cin >> exponente;
      comprobarEntrada(exponente);
      cout << endl;
      
      FuncionPR::contadorLlamadas = 0; // Reiniciar el contador
      Potencia p;
      int resultado = p.evaluar({base, exponente});
      int llamadas = FuncionPR::contadorLlamadas;

      mostrarResultado(base, exponente, resultado, llamadas);
    }
  } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
}