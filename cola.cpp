#include "cola.h"

Cola::Cola():header(new Node)
{
    if(header == nullptr){
        throw Error("Memoria no disponible,cola");
    }
    header->setPrev(header);
    header->setPrev(header);
}

Cola::Cola(const Cola &l)
{
    CopyAll(l);
}

Cola::~Cola()
{
    DeleteAll();
}


bool Cola::vacia() const
{
    return header->getNext() == header;
}

void Cola::enqueue(const char &formado)
{
    Node* aux;
    try {
        aux = new Node(formado);
    } catch (Error ex) {
        throw Error(ex.what());
    }
    if(aux == nullptr){
        throw Error("Memoria no disponoble,enqueue");
    }
    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
}

char Cola::dequeue() const
{
    if(vacia()){
        throw Error("Faltan datos,cola dequeue");
    }
    char result(header->getNext()->getData());
    Node* aux(header->getNext());
    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());
    delete aux;
    return result;

}

char Cola::front() const
{
    if(vacia()){
        throw Error("Insuficiencia de datos,cola front");
    }
    return header->getNext()->getData();
}

void Cola::DeleteAll()
{
    Node* aux;
    while(header->getNext() != header){
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
}

void Cola::CopyAll(const Cola&l)
{
    Node* aux(l.header->getNext());
    Node* New;
    while(aux != l.header){
        try{
            if((New = new Node(aux->getData())) == nullptr){
                throw Error("Memoria no disponible, cola copy");
            }
        }
        catch(Error ex){
            throw Error(ex.what());
        }
        New->setPrev(header->getPrev());
        New->setNext(header);

        header->getPrev()->setNext(New);
        header->setPrev(New);
    }
}
