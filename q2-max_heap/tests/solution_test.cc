#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <climits>      // INT_MAX (linux)
#include <limits>       // INT_MAX (darwin)
#include <string>       // std::string
#include <iostream>     // CaptureStdout

/******************** MaxHeap::GetParentIndex() ********************/
TEST(MAXHEAP_GET_PARENT_INDEX, STANDARD)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = 0;
    int actual = max_heap.GetParentIndex(2);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_PARENT_INDEX, ROOT)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    int expected = -1;
    int actual = max_heap.GetParentIndex(0);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_PARENT_INDEX, EMPTY)
{
    MaxHeap max_heap;
    
    int expected = -1;
    int actual = max_heap.GetParentIndex(1);
    EXPECT_EQ(expected, actual);
}

/******************** MaxHeap::GetLeftIndex() ********************/
TEST(MAXHEAP_GET_LEFT_INDEX, STANDARD)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = 1;
    int actual = max_heap.GetLeftIndex(0);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_LEFT_INDEX, LEAF)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = -1;
    int actual = max_heap.GetLeftIndex(2);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_LEFT_INDEX, EMPTY)
{
    MaxHeap max_heap;

    int expected = -1;
    int actual = max_heap.GetLeftIndex(0);
    EXPECT_EQ(expected, actual);
}

/******************** MaxHeap::GetRightIndex() ********************/
TEST(MAXHEAP_GET_RIGHT_INDEX, STANDARD)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = 2;
    int actual = max_heap.GetRightIndex(0);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_RIGHT_INDEX, LEAF)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = -1;
    int actual = max_heap.GetRightIndex(2);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_RIGHT_INDEX, EMPTY)
{
    MaxHeap max_heap;

    int expected = -1;
    int actual = max_heap.GetRightIndex(0);
    EXPECT_EQ(expected, actual);
}

/******************** MaxHeap::GetLargestChildIndex() ********************/
TEST(MAXHEAP_GET_LARGEST_CHILD_INDEX, STANDARD_RIGHT)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = 2;
    int actual = max_heap.GetLargestChildIndex(0);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_LARGEST_CHILD_INDEX, STANDARD_LEFT)
{
    MaxHeap max_heap;
    
    max_heap.push(2);
    max_heap.push(3);
    max_heap.push(1);
    int expected = 1;
    int actual = max_heap.GetLargestChildIndex(0);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_LARGEST_CHILD_INDEX, ONE_CHILD)
{
    MaxHeap max_heap;
    max_heap.push(1);
    max_heap.push(2);
    int expected = 1;
    int actual = max_heap.GetLargestChildIndex(0);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_LARGEST_CHILD_INDEX, LEAF)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = -1;
    int actual = max_heap.GetLargestChildIndex(2);
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_GET_LARGEST_CHILD_INDEX, EMPTY)
{
    MaxHeap max_heap;

    int expected = -1;
    int actual = max_heap.GetLargestChildIndex(0);
    EXPECT_EQ(expected, actual);
}

/******************** MaxHeap::top() ********************/
TEST(MAXHEAP_TOP, STANDARD)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = 3;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_TOP, SINGULAR)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    int expected = 1;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_TOP, EMPTY)
{
    MaxHeap max_heap;

    int expected = INT_MAX;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

/******************** MaxHeap::push() ********************/
TEST(MAXHEAP_PUSH, STANDARD)
{
    MaxHeap max_heap;

    max_heap.push(1);
    max_heap.push(2);
    int expected = 2;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);

    max_heap.push(3);
    expected = 3;
    actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_PUSH, SINGULAR)
{
    MaxHeap max_heap;

    max_heap.push(1);
    int expected = 1;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_PUSH, NEGATIVE)
{
    MaxHeap max_heap;

    max_heap.push(1);
    max_heap.push(2);
    int expected = 2;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);

    max_heap.push(-3);
    expected = 2;
    actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

/******************** MaxHeap::pop() ********************/
TEST(MAXHEAP_POP, STANDARD)
{
    MaxHeap max_heap;

    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    int expected = 3;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);

    max_heap.pop();
    expected = 2;
    actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_POP, SINGULAR)
{
    MaxHeap max_heap;
    
    max_heap.push(1);
    int expected = 1;
    int actual = max_heap.top();
    EXPECT_EQ(expected, actual);
    
    max_heap.pop();
    expected = INT_MAX;
    actual = max_heap.top();
    EXPECT_EQ(expected, actual);
}

TEST(MAXHEAP_POP, EMPTY)
{
    MaxHeap max_heap;
    testing::internal::CaptureStdout();
    max_heap.pop();
    std::string expected = "Error: Heap empty. Nothing to pop.\n";
    std::string actual = testing::internal::GetCapturedStdout();
    EXPECT_EQ(expected, actual);
}