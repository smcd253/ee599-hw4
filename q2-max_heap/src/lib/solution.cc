#include "solution.h"

/******************** get index functions ********************/
int MaxHeap::GetParentIndex(int i);
{
    int result = 0;

    // input validation
    if (i <= 0)
    {
        result = -1;
    }
    else
    {
        result = (i - 1) / 2;
    }

    return result;
} 

int MaxHeap::GetLeftIndex(int i)
{
    int result = 0;

    // input validation
    if((2 * i) + 1 >= (int)this->data_.size())
    {
        result = -1;
    }
    else
    {
        result = (2 * i) + 2;
    }
    return result;
}
int MaxHeap::GetRightIndex(int i); // *GT*
int MaxHeap::GetSmallestChildIndex(int i); // *GT*

// get value functions
int MaxHeap::GetLeft(int i);
int MaxHeap::GetRight(int i);
int MaxHeap::GetParent(int i);

// manipulate heap functions
int MaxHeap::top(); // GT
void MaxHeap::push(int v); // GT
void MaxHeap::pop(); // GT
void MaxHeap::TrickleUp(int i);
void MaxHeap::TrickleDown(int i);