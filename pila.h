#ifndef PILA_H
#define PILA_H
#include "error.h"
#include "node.h"

class Pila
{

private:
    Node *ancla;

public:
    Pila();
    Pila(const Pila&);
    ~Pila();
    void CopyAll(const Pila&);
    bool Vacia() const;
    void Push(const char&);
    char Poop();
    char Top() const;
    void DeleteAll();
};

#endif // PILA_H
