#ifndef FUNCIONESPR_H
#define FUNCIONESPR_H

#include <iostream>
#include <vector>

using namespace std;

static int llamadas = 0;

class FuncionPR {
  public:
    // Constructor y destructor
    FuncionPR() = default;
    ~FuncionPR() = default;

    // Métodos
    virtual int evaluar(const vector<int>& args) = 0;
};

#endif // FUNCIONESPR_H