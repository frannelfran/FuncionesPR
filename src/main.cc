#include "src/funcionPR/potencia/potencia.h"

int main() {
  try {
    while (true) {
      cout << "Programa que evalua la función primitiva recursiva potencia: NxN -> N" << endl;
      cout << "Ingrese la base (entero no negativo): ";
      int base;
      cin >> base;
      cout << "Ingrese el exponente (entero no negativo): ";
      int exponente;
      if (base < 0 || exponente < 0) {
        cout << "Por favor, ingrese enteros no negativos." << endl;
        continue;
      }
      cin >> exponente;

      Potencia p;
      cout << "Resultado: " << p.evaluar({base, exponente}) << endl;
      cout << "Número de llamadas a funciones primitivas recursivas: " << llamadas << endl;


    }











  } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
}