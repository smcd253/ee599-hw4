#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>       // std::vector<int>
#include <limits>       // INT_MAX

// Only methods which are marked by "GT" should be tested
class MaxHeap 
{
    private:
        // std::vector<int> data_;
    public:
        MaxHeap() : data_() {} // default constructor

        // get index functions
        int GetParentIndex(int i); // *GT*
        int GetLeftIndex(int i); // *GT*
        int GetRightIndex(int i); // *GT*
        int GetLargestChildIndex(int i); // *GT*

        // get value functions
        int GetLeft(int i);
        int GetRight(int i);
        int GetParent(int i);

        // manipulate heap functions
        int top(); // GT
        void push(int v); // GT
        void pop(); // GT
        void TrickleUp(int i);
        void TrickleDown(int i);

        std::vector<int> data_;
};

#endif