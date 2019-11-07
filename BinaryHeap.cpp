#include <iostream>
using namespace std;

template<typename T>
struct nodo
{
  T valor;
  nodo<T>* izq = nullptr;
  nodo<T>* der = nullptr;
};
