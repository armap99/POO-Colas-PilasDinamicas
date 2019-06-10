#include "pila.h"

Pila::Pila():ancla(nullptr){}

Pila::Pila(const Pila &l):ancla(nullptr)
{
    CopyAll(l);
}

Pila::~Pila()
{
    DeleteAll();
}

void Pila::CopyAll(const Pila &l)
{
    Node* aux(l.ancla);
    Node* ultimo(nullptr);
    Node* Nuevo;
    while (aux != nullptr) {
        Nuevo = new Node(aux->getData());
        if(Nuevo == nullptr){
            throw Error("Memoria no disponible,CopyAll");
        }
        if(ultimo == nullptr){
            ancla = Nuevo;
        }
        else {
            ultimo->setNext(Nuevo);
        }
        ultimo = Nuevo;
        aux = aux->getNext();
        }
}
//inicializacion de pila

bool Pila::Vacia() const//si esta vacia
{
    return ancla == nullptr;
}

void Pila::Push(const char &elemento)//ponen un elemento en la pila
{
    Node* aux(new Node(elemento));
    if(aux == nullptr){
        throw Error("Memoria no disponible, push pila");
    }
    aux->setNext(ancla);
    ancla = aux;
}

char Pila::Poop()//eliminar un elemento de la pila y regresa el eliminado
{
    if(Vacia()){
        throw Error("Insuficiencia de datos, poop pila");
    }
    char result(ancla->getData());
    Node* aux(ancla);
    ancla = ancla->getNext();
    delete aux;
    return result;
}

char Pila::Top() const//regrea el elemento en el tope
{
    if(Vacia()){
        throw Error("Insuficiencia de datos,top pila");
    }
    return ancla->getData();
}

void Pila::DeleteAll()
{
    Node* aux;
    while(ancla != nullptr){
        aux = ancla;
        ancla = ancla->getNext();
        delete aux;
    }
}


