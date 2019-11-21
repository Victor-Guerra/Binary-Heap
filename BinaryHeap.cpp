#include <iostream>
#include <list>
using namespace std;

template<typename T>
struct nodo
{
  T valor;
  int parent;
  int izq;
  int der;
};

template<typename T>
class BinHeap
{
  public:
    BinHeap()
    {
      h = new list<T>;
      current_size = 0;
    }

    void Insert(T valor)
    {
      if(current_size == 0)
      {
       this->h[0] = valor;
       ++current_size;
       return;
      }
      else
      {
        this->h.push_back(valor);
        ++current_size;
        if(h.)
      }
      
    }
    
    int leftCh(int index)
    {
      if(h[2*index + 1] != NULL)
      {
        return (2*index + 1);
      }
      else
      {
        return int();
      }
    }

    int rightCh(int index)
    {
      if(h[2*index + 2] != NULL)
      {
        return (2*index + 2);
      }
      else
      {
        return int();
      }
    }

    int parent(int index)
    {
      return (index - 1)/2 ;
    }

    void Find(T buscado)
    {

    }

    void Print()
    {

    }


    int size()
    {
      return current_size;
    }

    int LastNodo()
    {

    }

  private:
    void recPrint(nodo<T>* actual)
    {
      
    }
    
    nodo<T>* nextNodo(nodo<T>* actual)
    {
  
    }

    T *h;
    int current_size;

};

int main()
{

  //BinHeap<int> heap(100);
  
  //heap.Print();
}

