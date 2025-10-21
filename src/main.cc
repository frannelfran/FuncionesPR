#include "funcionPR/potencia/potencia.h"

void mostrarResultado(int base, int exponente, int resultado, int llamadas) {
  cout << "Base: " << base << endl;
  cout << "Exponente: " << exponente << endl;
  cout << " => Resultado: " << resultado << endl;
  cout << " => Llamadas recursivas: " << llamadas << endl;
  cout << "-------------------------" << endl;
}

int main() {
  cout << "Programa que evalua la función primitiva recursiva potencia: NxN -> N\n" << endl;
  try {
    while (true) {
      cout << "Ingrese la base (entero no negativo): ";
      int base;
      cin >> base;
      cout << "Ingrese el exponente (entero no negativo): ";
      int exponente;
      cin >> exponente;
      cout << endl;
      if (base < 0 || exponente < 0) {
        cout << "Por favor, ingrese enteros no negativos." << endl;
        continue;
      }
      
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