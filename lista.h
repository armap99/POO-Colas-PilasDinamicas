#ifndef LISTA_H
#define LISTA_H

#include "error.h"

class Lista
{
public://nodo
    class Node
    {
    private:
        char data;
        Node* next;
    public:
        Node();
        Node(const char&);

        char getData()const;
        Node *getNext() const;
        void setData(const char&);
        void setNext(Node*);
    };
private://lista
    Node *mylist;//ancla
    bool isValidPos(const Node*)const;

public:
    Lista();
    Lista(const Lista&);
    ~Lista();
    void CopyAll(const Lista&);
    bool Vacia() const;
    void Inserta(Node *, const char&);
    void Borrar(Node *);
    char Recupera(Node*);
    Node* getPrimero()const;
    Node* getUltimo()const;
    Node* getSeguiente(Node*)const;
    Node* getAnterior(Node*)const;
    void Anula();
    void Mostrar();
    Node* busquedaLineal(const char&);

};

#endif // LISTA_H
