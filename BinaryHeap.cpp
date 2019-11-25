#include <iostream>
#include <array>
using namespace std;


template<typename T>
class BinHeap
{
  private:

  public:
    BinHeap(int cap)
    {
      //h = new list<T>;
      maxCapacity = cap; 
      h = new T[maxCapacity];
      current_size = 0;
    }


    void HeapifyFromList(T arr[])
    {
      if(arr.size() > 0)
      {
        for(int i = 0; i < arr.size(); ++i)
        {
          Insert(arr[i]);
        }
      }
    }

    void Insert(T valor)
    {
      if(current_size == maxCapacity)
      {
        cout << "Heap is at max capacity" << endl;
        return;
      }
      else
      {
        ++current_size;
        int insertIndex = current_size;
        h[insertIndex] = valor;
        
        Bubble(insertIndex);
      }
      
    }
    

    T TakeMax()
    {
      T max = h[0];
      h[0] = h[current_size];
      h[current_size] = 0;
      Sink(0);
      --current_size;
      return max;
    }


    void Print()
    {
      for(int i = 0; i <= current_size; ++i)
      {
        cout << h[i] << " ";
      }
      cout << endl;
    }


    int size()
    {
      return current_size;
    }

    bool isEmpty()
    {
      return current_size == 0;
    }


  private:
    
    int maxCapacity;
    T *h;
    int current_size;


    void swap(int index1, int index2)
    {
      int temp = h[index1];
      h[index1] = h[index2];
      h[index2] = temp;
    }
    
    int ParentIndex(int pos)
    {
      return pos/2;
    }

    int LeftChild(int pos)
    {
      return 2*pos;
    }

    int RightChild(int pos)
    {
      return 2*pos + 1;
    }

    void Bubble(int pos)
    {
      int parent = ParentIndex(pos);
      int current = pos; 
      while(current > 0 && h[parent] < h[current])
      {
        swap(current, parent);
        current = parent;
        parent = ParentIndex(parent);
      }
    }

    void Sink(int n)
    {
      int max = n;
      int Left = LeftChild(n);
      int Right = RightChild(n);
      if(Left < current_size && h[max] < h[Left])
      {
        max = Left;
      }
      if(Right < current_size && h[max] < h[Right])
      {
        max = Right;
      }
      if(max != n)
      {
        swap(max, n);
        Sink(max);
      }
      
    }

};

template<typename T>
int size(T* arr)
{
  int count = 0;
  for(T &element : arr)
  {
    ++count;
  }
  return count;
}

int main()
{

  // By Victor E. Guerra A. A01568075
  //  & Gerardo Granados A. A01568072
  //
  //
  BinHeap<int> heap(9);
  heap.Insert(10);
  heap.Insert(15);
  heap.Insert(8);
  heap.Insert(11);
  heap.Insert(12);
  heap.Insert(17);
  // It will always include a 0
  heap.Print();
 
  // Extracting the highest number (or lowest in a Min-Heap) has a constant 
  // time O(1), since we always know where it is
  // with the TakeMax() fuction.
  

  // We can make a sort by simply "Max-Heaping" and recording the output:

  while(!heap.isEmpty())
  {
    cout << heap.TakeMax() << " ";
  }

  // This is the so-called Heap-sort.




}

