#include "solution.h"

/******************** get index functions ********************/
// Runtime = &theta;(5) --> O(1)
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

// Runtime = &theta;(5) --> O(1)
int MaxHeap::GetLeftIndex(int i)
{
    int result = -1;

    int index = (2 * i) + 1;
    if(index < (int)this->data_.size())
    {
        result = index;
    }
    
    return result;
}

// Runtime = &theta;(5) --> O(1)
int MaxHeap::GetRightIndex(int i)
{
    int result = -1;

    int index = (2 * i) + 2;
    if(index < (int)this->data_.size())
    {
        result = index;
    }
    
    return result;
}

// Runtime = &theta;(1 + 2*9 + 5) --> O(1)
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

    return result;    
}

/******************** get value functions ********************/
// Runtime = &theta;(1 + 5 + 3) --> O(1)
int MaxHeap::GetLeft(int i)
{
    int result = INT_MAX;
    int index = this->GetLeftIndex(i);

    if(index >= 0)
    {
        result = this->data_[index];
    }

    return result;
}

// Runtime = &theta;(1 + 5 + 3) --> O(1)
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

// Runtime = &theta;(1 + 5 + 3) --> O(1)
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
// Runtime = &theta;(4) --> O(1)
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

// Runtime = &theta;(4) --> O(1)
void MaxHeap::push(int v)
{
    // add to end
    this->data_.push_back(v);

    // trickle up
    int i = (int)data_.size() - 1;
    this->TrickleUp(i);
    
}

// Runtime = &theta;(1 + 3 + 30*log(n)) --> O(log(n))
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

// Runtime = &theta;((3 + 1)*log(n)) --> O(log(n))
void MaxHeap::TrickleUp(int i)
{
    while (i != 0 && GetParent(i) < this->data_[i])
    {
        swap(this->data_[i], data_[GetParentIndex(i)]);
        i = GetParentIndex(i);
    }
}

// Runtime = &theta;(30*log(n)) --> O(log(n))
void MaxHeap::TrickleDown(int i)
{
    if(this->data_.size() > 0)
    {
        while (i != (int)this->data_.size() - 1 && 
            this->data_[GetLargestChildIndex(i)] > this->data_[i])
        {   
            int lc_index = GetLargestChildIndex(i);
            swap(this->data_[i], data_[lc_index]);
            i = lc_index;
        }
    }
}