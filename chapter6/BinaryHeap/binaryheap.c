#include "binaryheap.h"
#include "fatal.h"

#define MindSize 10
#define MinData -32767

struct HeapStruct
{
      int capacity;
      int size;
      elementType *elements;
};

PriorityQueue initialize(int maxElements)
{
      PriorityQueue H;
      if( maxElements < MindSize )
            Error("Priority queue size is too small ");
      H = (struct HeapStruct*)malloc(sizeof(struct HeapStruct));
      if(H == NULL)
            FatalError("Out of space");
      H->elements = (elementType*)malloc((maxElements + 1) * sizeof(elementType));
      if(H->elements == NULL)
            FatalError("Out of space");
      H->capacity = maxElements;
      H->size = 0;
      H->elements[0] = MinData;
      return H;
}

void destory(PriorityQueue H)
{
      free(H->elements);
      free(H);
}

void make_empty(PriorityQueue H)
{
      if(!empty(H))
            H->size = 0;
}

void insert(elementType x, PriorityQueue H)
{
     int i;
     if( full(H) )
     {
           FatalError("insert full Priority");
     }
     for(i = ++H->size; H->elements[i/2] > x; i /= 2)
            H->elements[i] = H->elements[i/2];
     H->elements[i] = x;
}

elementType deleteMin(PriorityQueue H)
{
      int i, child;
      elementType lastElement, minElement;

      if( empty(H) )
      {
            FatalError("deleteMin empty Priority");
            return 0;
      }
      minElement = H->elements[1];
      lastElement = H->elements[H->size];
      H->size--;
      for( i = 1; i * 2 <= H->size; i = child )
      {
            child = i * 2;
            if(child != H->size && H->elements[child] > H->elements[child + 1] )
                  child++;
            if(lastElement > H->elements[child])
                  H->elements[i] = H->elements[child];
            else
                  break;
      }
      H->elements[i] = lastElement;
      return minElement;
}


elementType find_min(PriorityQueue H)
{
      if( !empty(H) )
      {
            return H->elements[1];
      }
      Error("Priority queue is empty");
      return H->elements[0];
}

bool empty(PriorityQueue H)
{
      return H->size == 0;
}

bool full(PriorityQueue H)
{
      return H->size == H->capacity;
}


// 对大小为 n 的数组 a 的第 i+ 1 个元素进行一次下滤
void percolateDown(int a[], int i, int n)
{
      int tmp;
      int child;

      for( tmp = a[i]; i * 2 < n; i = child )
      {
            // 判断是否有右儿子并比较左、右儿子的大小取小的儿子
            if(child != n - 1 && a[child] > a[child + 1])
                  child++;
            if(a[child] < tmp)
                  a[i] = a[child];
            else
                  break;
      }
      a[i] = tmp;
}

// 在大小为 n 的数组 a 中建立一个最小堆
// i = n /2 表示在数组中最后一个拥有儿子的元素开始往回下滤
void buildHeap(int a[], int n)
{
      int i;

      for(i = n / 2; i >= 0; i--)
            percolateDown(a, i, n);
}