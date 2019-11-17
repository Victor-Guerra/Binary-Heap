#include <iostream>
using namespace std;

template<typename T>
struct nodo
{
  T valor;
  nodo<T>* izq;
  nodo<T>* der;
};

template<typename T>
class BinHeap
{
  public:
    void Insert(T valor)
    {
      if(isEmpty())
      {
        root = new nodo<T>;
        root->valor = valor;
        return;
      }
      else if(valor < root->valor)
      {
        auto next = LastNodo();
        next->valor = valor;
      }

       
    }
    
    T Take(nodo<T>* taken)
    {

    }

    void Find(T buscado)
    {

    }

    bool isEmpty()
    {
      return !root;
    }

    nodo<T>* LastNodo()
    {
      return nextNodo(root);
    }
  private:
    nodo<T>* nextNodo(nodo<T>* actual)
    {
      if(!actual->izq)
      {
        return actual;
      }
      actual = nextNodo(actual->izq);
      actual = nextNodo(actual->der);

      return actual;
    }

    nodo<T>* root = nullptr;

};

int main()
{

  BinHeap<int> heap;
  heap.Insert(10);

}

