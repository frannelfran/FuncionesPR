# FuncionesPR
Este es un programa que calcula utilizando funciones primitivas recursivas la potencia de un número.

La función `potencia` se define como:

potencia: N × N → N  
(x, y) ↦ xʸ

- Esta función toma dos números naturales y devuelve el resultado de elevar el primero a la potencia del segundo.

# Estructura de directorios

```bash
.
├── README.md
├── makefile
└── src
    ├── funcionPR
    │   ├── cero
    │   │   ├── cero.cc
    │   │   └── cero.h
    │   ├── funcionPR.cc
    │   ├── funcionPR.h
    │   ├── potencia
    │   │   ├── potencia.cc
    │   │   └── potencia.h
    │   ├── producto
    │   │   ├── producto.cc
    │   │   └── producto.h
    │   ├── proyeccion
    │   │   ├── proyeccion.cc
    │   │   └── proyeccion.h
    │   ├── sucesor
    │   │   ├── sucesor.cc
    │   │   └── sucesor.h
    │   ├── suma
    │   │   ├── suma.cc
    │   │   └── suma.h
    │   └── uno
    │       ├── uno.cc
    │       └── uno.h
    ├── main.cc
    └── tools
        ├── tools.cc
        └── tools.h
```

# Estructura del programa
En el proyecto se implementan varias funciones primitivas recursivas modeladas por clases que heredan de `FuncionPR`. Todas ellas implementan el método:

## Funciones primitivas recursivas (PR)

```c++
class FuncionPR {
  public:
    FuncionPR() = default;
    ~FuncionPR() = default;
    virtual int evaluar(const vector<int>& args) = 0;
};
```

Además existe un contador global compartido entre las unidades de traducción:

- `extern int llamadas` (definido en `src/funcionPR/contador.cc`).

- Este contador se incrementa en cada llamada a `evaluar` de las funciones PR (cada función incrementa `llamadas++` al empezar su evaluación). En `main.cc` se reinicia `llamadas = 0;` antes de evaluar una función para medir las llamadas durante una única evaluación.

A continuación se describen las clases que representan las funciones PR del proyecto.

### Cero

```c++
class Cero : public FuncionPR {
  public:
    Cero() = default;
    ~Cero() = default;
    int evaluar(const vector<int>& args) override;
};

int Cero::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  return 0;
}
```
- **Comportamiento**: siempre devuelve 0.
- **Ejemplo**: `Cero().evaluar({}) == 0`.

### Sucesor

```c++
class Sucesor : public FuncionPR {
  public:
    Sucesor() = default;
    ~Sucesor() = default;
    int evaluar(const vector<int>& args) override;
};

int Sucesor::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (args.size() != 1) {
    throw invalid_argument("Se espera un solo argumento.");
  }
  return Proyeccion(0).evaluar(args) + Uno().evaluar({});
}
```
- **Comportamiento**: devuelve `args[0] + 1`.
- **Ejemplo**: `Sucesor().evaluar({3}) == 4`.

### Proyeccion

```c++
class Proyeccion : public FuncionPR {
  public:
    Proyeccion(int indice) : indice(indice) {}
    ~Proyeccion() = default;
    int evaluar(const vector<int>& args) override;
  private:
    int indice;
};

int Proyeccion::evaluar(const vector<int>& args) {
  if (indice < 0 || indice >= args.size()) {
    throw out_of_range("Índice de proyección fuera de rango.");
  }
  llamadas++;
  return args[indice];
}
```
- **Comportamiento**: lanza `out_of_range` si `indice` no está en rango.
- **Ejemplo**: `Proyeccion(1).evaluar({5,7}) == 7`.

### Suma

```c++
class Suma : public FuncionPR {
  public:
    Suma() = default;
    ~Suma() = default;
    int evaluar(const vector<int>& args) override;
};

int Suma::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (args.size() != 2) {
    throw invalid_argument("Se esperan exactamente dos argumentos.");
  }
  // Obtengo los argumentos
  int x = Proyeccion(0).evaluar(args);
  int y = Proyeccion(1).evaluar(args);

  if (y == 0) {
    return x;
  } else {
    return Sucesor().evaluar({this->evaluar({x, y - 1})});
  }
}
```

- **Definición (recursiva)**:
  - Si `y == 0` devuelve `x`.
  - En otro caso, devuelve `Sucesor(evaluar(x, y-1))`.
- **Ejemplo**: `Suma().evaluar({3,2}) == 5`.

### Producto

```c++
class Producto : public FuncionPR {
  public:
    Producto() = default;
    ~Producto() = default;
    int evaluar(const vector<int>& args) override;
};

int Producto::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (args.size() != 2) {
    throw invalid_argument("Se esperan exactamente dos argumentos.");
  }
  // Obtengo los argumentos
  int x = Proyeccion(0).evaluar(args);
  int y = Proyeccion(1).evaluar(args);

  if (y == 0) {
    return Cero().evaluar({});
  } else {
    return Suma().evaluar({x, this->evaluar({x, y - 1})});
  }
}
```

- **Definición (recursiva)**:
  - Si `y == 0` devuelve `Cero()` (0).
  - En otro caso, devuelve `Suma(x, Producto(x, y-1))`.
- **Ejemplo**: `Producto().evaluar({3,4}) == 12`.

### Potencia

```c++
class Potencia : public FuncionPR {
  public:
    Potencia() = default;
    ~Potencia() = default;
    int evaluar(const vector<int>& args) override;
};

int Potencia::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  if (args.size() != 2) {
    throw invalid_argument("Se esperan exactamente dos argumentos.");
  }
  // Obtengo los argumentos
  int base = Proyeccion(0).evaluar(args);
  int exponente = Proyeccion(1).evaluar(args);

  if (exponente == 0) {
    return Uno().evaluar({});
  } else {
    return Producto().evaluar({base, this->evaluar({base, exponente - 1})});
  }
}
```

- **Definición (recursiva)**:
  - Si `exponente == 0` devuelve `Sucesor(Cero())` (1).
  - En otro caso, devuelve `Producto(base, Potencia(base, exponente-1))`.
- **Ejemplo**: `Potencia().evaluar({2,3}) == 8`.

### Uno

```c++
class Uno : public FuncionPR {
  public:
    Uno() = default;
    ~Uno() = default;
    int evaluar(const vector<int>& args) override;
};

int Uno::evaluar(const vector<int>& args) {
  FuncionPR::contadorLlamadas++;
  return 1;
}
```

- **Comportamiento**: siempre devuelve 1.
- **Ejemplo**: `Cero().evaluar({}) == 1`.

## Notas 🗒️

- Todas las funciones primitivas recursivas usan `Proyeccion` para obtener argumentos cuando corresponde.
- Cada función incrementa el contador global `llamadas` en el inicio de su `evaluar` para poder medir cuántas llamadas recursivas (y auxiliares) se realizan durante una evaluación.

## Compilación del programa
Para compilar este programa he creado un archivo `makefile` para automatizar el trabajo, solo basta con ejecutar lo siguiente:
```bash
make
```
Para borrar el ejecutable generado basta con ejecutar lo siguiente:
```bash
make clean
```

## Ejecución del programa
```bash
./funcionesPR
```

## Cosas a tener en cuenta‼️
1. La `base` y el `exponente` se solicitarán por terminal.
2. Si la base o el exponente no son enteros positivos, el programa `terminará` inmediatamente.
3. Si se quiere terminar la ejecución del programa basta con pulsar en cualquier momento `Ctrl+C`.

## Ejemplo de ejecución
En este ejemplo vamos a calcular cuantas llamadas se realizan para `potencia(2, 9)`.

### Ejecución
```bash
./funcionesPR
```
### Visualización
Cuando se ejecute, se solicitara primero al usuario que introduzca la `base` y luego el `exponente`:

```txt
Ingrese la base (entero no negativo): 2
Ingrese el exponente (entero no negativo): 9
```

### Resultado
El resultado sera la evaluación de la funcion para la base y exponente especificados con aterioridad junto con el número de llamadas recursivas que se realizan para llegar a la solución.

```txt
Base: 2
Exponente: 9
 => Resultado: 512
 => Llamadas recursivas: 261661
-------------------------
```