#include <iostream>
#include "src/lib/solution.h"

int main()
{
    MaxHeap heap;
    heap.data_ = {1, 3, 4, 5, 6, 13, 10};
    // print out complete tree
    // breadth first traversal
    // printf("L0:         %d\n", heap.top());
    // printf("L1:     %d      %d\n", heap.GetLeft(0), heap.GetRight(0));
    // printf("L2: %d     %d %d      %d\n", heap.GetLeft(heap.GetLeftIndex(0)), heap.GetRight(heap.GetLeftIndex(0)),
    //                             heap.GetLeft(heap.GetRightIndex(0)), heap.GetRight(heap.GetRightIndex(0)));

    // printf("Parent of %d = %d\n", heap.data_[6], heap.GetParent(6));
    // printf("Parent of %d = %d\n", heap.data_[1], heap.GetParent(1));
    // printf("Parent of %d = %d\n", heap.data_[0], heap.GetParent(0));
    printf("Largest Child of %d = %d\n", heap.data_[1], heap.data_[heap.GetLargestChildIndex(1)]);
    return EXIT_SUCCESS;
}