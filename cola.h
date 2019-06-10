#ifndef COLA_H
#define COLA_H
#include "error.h"
#include "node.h"

class Cola
{
private:
    Node* header;
public:
    Cola();
    Cola(const Cola&);
    ~Cola();
    bool vacia() const;
    void enqueue(const char&);
    char dequeue() const;
    char front() const;
    void DeleteAll();
    void CopyAll(const Cola &);
};

#endif // COLA_H
