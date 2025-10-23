#include "tools.h"

/**
 * @brief Muestra el resultado de la evaluación de la función potencia.
 * @param base La base ingresada.
 * @param exponente El exponente ingresado.
 * @param resultado El resultado de la potencia.
 * @param llamadas El número de llamadas recursivas realizadas.
 * @return void
 */
void mostrarResultado(int base, int exponente, int resultado, int llamadas) {
  cout << "Base: " << base << endl;
  cout << "Exponente: " << exponente << endl;
  cout << " => Resultado: " << resultado << endl;
  cout << " => Llamadas recursivas: " << llamadas << endl;
  cout << "-------------------------" << endl;
}

/**
 * @brief Comprueba que las entradas sean válidas (enteros no negativos).
 * @param numero Referencia al número a comprobar.
 * @return void
 */
void comprobarEntrada(int& numero) {
  if (numero < 0) {
    throw invalid_argument("Por favor, ingrese un entero no negativo.");
  }
}