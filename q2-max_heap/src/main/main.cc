#include <iostream>
#include "src/lib/solution.h"

int main()
{
    MaxHeap heap;
    // heap.data_ = {};
    // print out complete tree
    // breadth first traversal
    for (int i = 0; i < 7; i++)
    {
        heap.push(i);
    }
    printf("L0:         %d\n", heap.top());
    printf("L1:     %d      %d\n", heap.GetLeft(0), heap.GetRight(0));
    printf("L2: %d     %d %d      %d\n", heap.GetLeft(heap.GetLeftIndex(0)), heap.GetRight(heap.GetLeftIndex(0)),
                                heap.GetLeft(heap.GetRightIndex(0)), heap.GetRight(heap.GetRightIndex(0)));
    
    heap.pop();
    printf("L0:         %d\n", heap.top());
    printf("L1:     %d      %d\n", heap.GetLeft(0), heap.GetRight(0));
    printf("L2: %d     %d %d      %d\n", heap.GetLeft(heap.GetLeftIndex(0)), heap.GetRight(heap.GetLeftIndex(0)),
                                heap.GetLeft(heap.GetRightIndex(0)), heap.GetRight(heap.GetRightIndex(0)));
    
    return EXIT_SUCCESS;
}