#include <iostream>
#include <string.h>
#include "cola.h"
#include "pila.h"

using namespace std;

int main()
{
    string op;
    do{
        cout << "Menu:" << endl <<
                "1-Ingresar expresion infija" << endl <<
                "2-Salir" << endl;
        cin >> op;
        if(op == "1"){
            int i(0),x;
            char input[50];
            Pila operadores;
            Cola entrad,resultado;
            cout << "Ingrese la cadena con notacion infija" << endl;
            cin >> input;
            x = strlen(input);
            for(i=0;i<x;i++){
                entrad.enqueue(input[i]);
            }
            for(i=0;i<x;i++){
                switch (entrad.front()) {
                    case '+':
                        if(operadores.Vacia()){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()=='('){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()!=')'){
                            while(!operadores.Vacia() and operadores.Top()!=')'){
                                resultado.enqueue(operadores.Poop());
                            }
                            operadores.Push(entrad.dequeue());
                        }
                    break;

                    case '-':
                        if(operadores.Vacia()){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()=='('){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()!=')'){
                            while(!operadores.Vacia() and operadores.Top()!=')'){
                                resultado.enqueue(operadores.Poop());
                            }
                            operadores.Push(entrad.dequeue());
                        }
                    break;

                    case '*':
                        if(operadores.Vacia()){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()=='('){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()!='+' or operadores.Top()!='-'){
                            while(!operadores.Vacia() and operadores.Top()!='(' and (operadores.Top()!='+' and operadores.Top()!='-')){
                                resultado.enqueue(operadores.Poop());
                            }
                            operadores.Push(entrad.dequeue());
                        }
                        else operadores.Push(entrad.dequeue());
                    break;

                    case '/':
                        if(operadores.Vacia()){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()=='('){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()!='+' or operadores.Top()!='-'){
                            while(!operadores.Vacia() and operadores.Top()!='(' and (operadores.Top()!='+' and operadores.Top()!='-')){
                                resultado.enqueue(operadores.Poop());
                            }
                            operadores.Push(entrad.dequeue());
                        }
                        else operadores.Push(entrad.dequeue());
                    break;

                    case '^':
                        if(operadores.Vacia()){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top()=='('){
                            operadores.Push(entrad.dequeue());
                        }
                        else if(operadores.Top() == '^'){
                            while(!operadores.Vacia() and operadores.Top()!='('){
                                resultado.enqueue(operadores.Poop());
                            }
                            operadores.Push(entrad.dequeue());
                        }
                        else operadores.Push(entrad.dequeue());
                    break;

                    case '(':
                        operadores.Push(entrad.dequeue());
                    break;

                    case ')':
                        while(!operadores.Vacia() and operadores.Top()!='('){
                            resultado.enqueue(operadores.Poop());
                        }
                        operadores.Poop();
                        entrad.dequeue();
                    break;

                    default:
                        resultado.enqueue(entrad.dequeue());
                    break;
                }
            }
            while(!operadores.Vacia() and entrad.vacia()){
                resultado.enqueue(operadores.Poop());
            }
            cout << "La cade posfija es: " << endl;
            while(!resultado.vacia()){
                cout << resultado.dequeue();
            }
            cout << endl << endl;
            operadores.DeleteAll();
            resultado.DeleteAll();
            entrad.DeleteAll();
        }
        if(op == "2"){

            break;
        }
    }while(true);
}
