#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <climits>      // INT_MAX (linux)
#include <limits>       // INT_MAX (darwin)
#include <string>       // std::string
#include <iostream>     // CaptureStdout

/******************** BST::push() ********************/
TEST(BST_PUSH, STANDARD)
{
    BST bst;

    bst.push(1);
    bool expected = true;
    bool actual = bst.find(1);
    EXPECT_EQ(expected, actual);
}

TEST(BST_PUSH, DUPLICATE)
{
    BST bst;

    bst.push(1);
    testing::internal::CaptureStdout();
    bst.push(1);
    std::string expected = "BST already contains key 1.\n";
    std::string actual = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, actual);
}

/******************** BST::find() ********************/
TEST(BST_FIND, STANDARD)
{
    BST bst;

    for (int i = 0; i < 100; i++)
    {
        bst.push(i);
    }
    bool expected = true;
    bool actual = bst.find(87);
    EXPECT_EQ(expected, actual);
}

TEST(BST_FIND, ROOT)
{
    BST bst;

    bst.push(1);
    bool expected = true;
    bool actual = bst.find(1);
    EXPECT_EQ(expected, actual);
}

TEST(BST_FIND, EMPTY)
{
    BST bst;

    bool expected = false;
    bool actual = bst.find(1);
    EXPECT_EQ(expected, actual);
}

TEST(BST_FIND, LEAF)
{
    BST bst;
    for (int i = 0; i < 100; i++)
    {
        bst.push(i);
    }
    bool expected = true;
    bool actual = bst.find(99);
    EXPECT_EQ(expected, actual);
}

/******************** BST::erase() ********************/
// TEST(BST_ERASE, STANDARD)
// {
//     BST bst;

//     for (int i = 0; i < 10; i++)
//     {
//         bst.push(i);
//     }
//     testing::internal::CaptureStdout();
//     bst.erase(3);
//     bool expected = true;
//     bool actual = bst.erase(3);
//     EXPECT_EQ(expected, actual);

//     bst.print_in_order();
//     std::string expected_print = "0 1 2 3 4 5 6 7 8 9 ";
//     std::string actual_print = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(expected_print, actual_print);
// }
