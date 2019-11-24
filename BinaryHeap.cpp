#include <iostream>
#include <vector>
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
      //h = new list<T>;
      current_size = 0;
    }

    void Insert(T valor)
    {
      if(current_size == 0)
      {
       h.push_back(valor);
       ++current_size;
       return;
      }
      else
      {
        h.push_back(valor);
        ++current_size;
        if(h[current_size - 1] > h[parent(current_size - 1)])
        {
          recSwap(current_size -1);
        }
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

    int FindIndex(T buscado)
    {
      for(int i = 0; i < current_size; ++i)
      {
        if(h[i] == buscado)
          return i;
      }
    }

    void Print()
    {
      for(int i = 0; i < current_size; ++i)
      {
        cout << h.at(i) << endl;
      }
    }


    int size()
    {
      return current_size;
    }


  private:
    
    void parentSwap(int indexValueToSwap)
    {
      swap(h[indexValueToSwap],h[parent(indexValueToSwap)]); 
    }

    void recSwap(int indexValueToSwap)
    {
      if(h[indexValueToSwap] > h[parent(indexValueToSwap)])
      {
        parentSwap(indexValueToSwap);
        recSwap(indexValueToSwap);
        return;
      }
      else
      {
        return;
      }
    }

  vector<T> h;
  int current_size;

};

int main()
{

  BinHeap<int> heap;
  heap.Insert(10);
  heap.Print();
  heap.Insert(9);
  heap.Print();
  heap.Insert(8);
  heap.Print();
  // 10 -> 9
  // \> 8
  heap.Insert(11);
  heap.Insert(12);
  heap.Print();
  // 11 -> 10
  // \> 9 -> 8
  //BinHeap<int> heap(100);
  
  //heap.Print();
}

