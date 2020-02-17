#include <iostream>
#include "src/lib/solution.h"

int main()
{
    BST bst;
    for (int i = 0; i < 10; i++)
    {
        if(i != 5)
            bst.push(i);
    }
    bst.print_in_order();
    bst.push(5);
    bst.print_in_order();
    bst.erase(4);
    bst.print_in_order();
    return EXIT_SUCCESS;
}