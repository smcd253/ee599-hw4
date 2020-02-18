# EE599 HW4 - Passing functions as a parameter and Trees (BST, Min Heap, Max Heap)

Created - Spencer McDonough : 02/03/2020
Last Modified - Spencer McDonough : 02/11/2020
University of Southern California

## Q1
**Runtime Analysis**

```c++
std::vector<int> Solution::filter_odds(std::vector<int> in)
```
Runtime = &theta;(2 + n + n + 1) --> O(n)

```c++
std::vector<int> Solution::map_square(std::vector<int> in
```
Runtime = &theta;(2 + n + n + 1) --> O(n)

```c++
int Solution::reduce(std::vector<int> in)
```
Runtime = &theta;(2 + n + 1) --> O(n)

## Q2
**Runtime Analysis**

```c++
int MaxHeap::GetParentIndex(int i)
```
Runtime = &theta;(5) --> O(1)

```c++
int MaxHeap::GetLeftIndex(int i)
```
Runtime = &theta;(5) --> O(1)

```c++
int MaxHeap::GetRightIndex(int i)
```
Runtime = &theta;(5) --> O(1)

```c++
int MaxHeap::GetLargestChildIndex(int i)
```
Runtime = &theta;(1 + 2*9 + 5) --> O(1)

```c++
int MaxHeap::GetLeft(int i)
```
Runtime = &theta;(1 + 5 + 3) --> O(1)

```c++
int MaxHeap::GetRight(int i)
```
Runtime = &theta;(1 + 5 + 3) --> O(1)

```c++
int MaxHeap::GetParent(int i)
```
Runtime = &theta;(1 + 5 + 3) --> O(1)

```c++
int MaxHeap::top()
```
Runtime = &theta;(4) --> O(1)

```c++
void MaxHeap::push(int v)
```
Runtime = &theta;(4) --> O(1)

```c++
void MaxHeap::pop()
```
Runtime = &theta;(1 + 3 + 30*log(n)) --> O(log(n))

```c++
void MaxHeap::TrickleUp(int i)
```
Runtime = &theta;((3 + 1)*log(n)) --> O(log(n))

```c++
void MaxHeap::TrickleDown(int i)
```
Runtime = &theta;(30*log(n)) --> O(log(n))

## Q3
**Runtime Analysis**

```c++
BST(std::vector<int> initial_values)
```
Runtime = &theta;(n*H), where H &isin;[log(n), n] --> O(n^2)

```c++
void BST::push(int key)
```
Runtime = &theta;(2*H), where H &isin;[log(n), n] --> O(n)

```c++
bool BST::find(int key)
```
Runtime = &theta;(H), where H &isin;[log(n), n] --> O(n)

```c++
bool BST::erase(int key)
```
Runtime = &theta;(2*H), where H &isin;[log(n), n] --> O(n)

## Q4
**Runtime Analysis**

```c++
void print_by_level()
```
Runtime = &theta;(1 + 2*H + 4 + 2*HH + n), where H &isin;[log(n), n] --> O(n*log(n))

## Q5
**Runtime Analysis**

```c++
void Solution::heap_sort(std::vector<int>& input)
```
Runtime = &theta;(2 + n*log(n) + n + 2*n) --> O(nlog(n))

## Q6
**Runtime Analysis**

```c++
int Solution::kth_largest(std::vector<int>& input, int k)
```
Runtime = &theta;(n*k), where k &isin; [1, n] --> O(n^2)