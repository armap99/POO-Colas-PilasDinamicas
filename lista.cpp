#include "lista.h"

Lista::Lista():mylist(nullptr){}

Lista::Lista(const Lista &l):mylist(nullptr){
    CopyAll(l);
}

Lista::~Lista()
{
    Anula();
}

void Lista::CopyAll(const Lista&l)
{
    Node* aux(l.mylist);
    Node* ultimo(nullptr);
    Node* Nuevo;
    while (aux != nullptr) {
        Nuevo = new Node(aux->getData());
        if(Nuevo == nullptr){
            throw Error("Memoria no disponible,CopyAll");
        }
        if(ultimo == nullptr){
            mylist = Nuevo;
        }
        else {
            ultimo->setNext(Nuevo);
        }
        ultimo = Nuevo;
        aux = aux->getNext();
    }
}

bool Lista::isValidPos(const Lista::Node *p) const
{
    Node* aux(mylist);
    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

bool Lista::Vacia() const
{
    return mylist == nullptr;
}


void Lista::Inserta(Lista::Node *p, const char &e)
{
    if(p != nullptr and !isValidPos(p)){
        throw Error("Posicion in valida,insertar");
    }
    Node *aux(new Node(e));
    if(aux == nullptr){
        throw Error("Memoria no disponible,insertar");
    }
    if(p == nullptr){//insertar al inicio
        aux->setNext(mylist);
        mylist = aux;
    }
    else{//insertar en cualquier otra posicion
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

void Lista::Borrar(Lista::Node *pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion no valida,Borrar");
    }
    if(pos == mylist){//Eliminar primero
        mylist = mylist->getNext();
    }
    else{
        getAnterior(pos)->setNext(pos->getNext());
    }
    delete pos;
}

char Lista::Recupera(Lista::Node *pos)
{
    if(!isValidPos(pos)){
            throw Error("Posicion invalida,recupera");
    }
    return pos->getData();
}

Lista::Node* Lista::getPrimero() const
{
    return mylist;
}

Lista::Node* Lista::getUltimo() const
{
    if(Vacia()){
        return nullptr;
    }
    Node* aux(mylist);
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    return aux;
}

Lista::Node* Lista::getSeguiente(Lista::Node *p) const
{
    if(!isValidPos(p)){
        return nullptr;
    }
    return p->getNext();
}

Lista::Node* Lista::getAnterior(Lista::Node *p) const
{
    if(Vacia() or p == mylist){
        return nullptr;
    }
    Node* aux(mylist);
    while(aux != nullptr and aux->getNext() != p){
        aux = aux->getNext();
    }
    return aux;
}

void Lista::Anula()
{
    Node* aux;
    while(mylist != nullptr){
        aux = mylist;
        mylist = mylist->getNext();
        delete aux;
    }
}

void Lista::Mostrar()
{
    //pendiente
}

Lista::Node *Lista::busquedaLineal(const char&c)
{
    Node* aux(mylist);
    while(aux != nullptr and aux->getData() != c){
        aux = aux->getNext();
    }
    return aux;
}

Lista::Node::Node():next(nullptr){}

Lista::Node::Node(const char &e):data(e), next(nullptr){}

char Lista::Node::getData() const
{
    return data;
}

Lista::Node* Lista::Node::getNext() const
{
    return next;
}

void Lista::Node::setData(const char &e)
{
    data = e;
}

void Lista::Node::setNext(Lista::Node *p)
{
    next = p;
}
