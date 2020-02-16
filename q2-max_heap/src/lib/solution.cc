#include "solution.h"

/******************** get index functions ********************/
int MaxHeap::GetParentIndex(int i)
{
    int result = -1;

    // input validation
    if (i > 0 && (int)this->data_.size() > 0)
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
    
    // printf("left index result = %d\n", result);
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
    
    // printf("right index result = %d\n", result);
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
                result = this->GetRightIndex(i);
            }
            else
            {
                result = this->GetLeftIndex(i);
            }
        }
        else
        {
            result = this->GetRightIndex(i);
        }
    }
    else if (left != INT_MAX)
    {
        result = this->GetLeftIndex(i);
    }

    // printf("largest result = %d\n", result);
    return result;    
}

/******************** get value functions ********************/
int MaxHeap::GetLeft(int i)
{
    int result = INT_MAX;
    int index = this->GetLeftIndex(i);

    if(index >= 0)
    {
        result = this->data_[index];
    }

    // printf("left result = %d\n", result);
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

    // printf("right result = %d\n", result);
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

/******************** manipulate heap functions ********************/
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

// helper function
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void MaxHeap::push(int v)
{
    // add to end
    this->data_.push_back(v);

    // trickle up
    int i = (int)data_.size() - 1;
    this->TrickleUp(i);
    
}

void MaxHeap::pop()
{
    if(this->data_.size() > 0)
    {
        // swap root for last value in data_
        swap(this->data_[0], this->data_[this->data_.size() - 1]);
        this->data_.pop_back();
        this->TrickleDown(0);
    }
    else
    {
        printf("Error: Heap empty. Nothing to pop.\n");
    }
    
}

void MaxHeap::TrickleUp(int i)
{
    while (i != 0 && GetParent(i) < this->data_[i])
    {
        swap(this->data_[i], data_[GetParentIndex(i)]);
        i = GetParentIndex(i);
    }
}
void MaxHeap::TrickleDown(int i)
{
    while (i != (int)this->data_.size() - 1 && 
         this->data_[GetLargestChildIndex(i)] > this->data_[i])
    {   
        int lc_index = GetLargestChildIndex(i);
        swap(this->data_[i], data_[lc_index]);
        i = lc_index;
    }
}