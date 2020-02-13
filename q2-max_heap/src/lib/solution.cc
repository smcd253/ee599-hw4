#include "solution.h"

/******************** get index functions ********************/
int MaxHeap::GetParentIndex(int i)
{
    int result = -1;

    // input validation
    if (i > 0)
    {
        result = (i - 1) / 2;
    }

    return result;
} 

int MaxHeap::GetLeftIndex(int i)
{
    int result = -1;

    int index = (2 * i) + 1;
    if(index < (int)this->data_.size())
    {
        result = index;
    }
    
    printf("left index result = %d\n", result);
    return result;
}

int MaxHeap::GetRightIndex(int i)
{
    int result = -1;

    int index = (2 * i) + 2;
    if(index < (int)this->data_.size())
    {
        result = index;
    }
    
    printf("right index result = %d\n", result);
    return result;
}

int MaxHeap::GetLargestChildIndex(int i)
{
    int result = -1;

    int right = this->GetRight(i);
    int left = this->GetLeft(i);

    if (right != INT_MAX)
    {
        if(left != INT_MAX)
        {
            if(right >= left)
            {
                result = right;
            }
            else
            {
                result = left;
            }
        }
        else
        {
            result = right;
        }
    }
    else if (left != INT_MAX)
    {
        result = left;
    }

    printf("largest result = %d\n", result);
    return result;    
}

// get value functions
int MaxHeap::GetLeft(int i)
{
    int result = INT_MAX;
    int index = this->GetLeftIndex(i);

    if(index >= 0)
    {
        result = this->data_[index];
    }

    printf("left result = %d\n", result);
    return result;
}

int MaxHeap::GetRight(int i)
{
    int result = INT_MAX;
    int index = this->GetRightIndex(i);
    
    if(index >= 0)
    {
        result = this->data_[index];
    }

    printf("right result = %d\n", result);
    return result;
}

int MaxHeap::GetParent(int i)
{
    int result = INT_MAX;
    int index = this->GetParentIndex(i);

    if(index >= 0)
    {
        result = this->data_[index];
    }

    return result;
}

// manipulate heap functions
int MaxHeap::top()
{
    int result = 0;

    if(this->data_.size() == 0)
    {
        result = INT_MAX;
    }
    else
    {
        result = data_[0];
    }
    return result;
}

// void MaxHeap::push(int v); // GT
// void MaxHeap::pop(); // GT
// void MaxHeap::TrickleUp(int i);
// void MaxHeap::TrickleDown(int i);