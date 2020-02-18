#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution;
    std::vector<int> input = {6, 2, 1, 4, 5, 3};
    printf("input = {");
    for (int i = 0; i < (int)input.size(); i++)
    {
        if(i < (int)input.size() - 1)
        {
            printf("%d, ", input[i]);
        }
        else
        {
            printf("%d}\n", input[i]);
        }
    }

    solution.heap_sort(input);

    printf("input sorted = {");
    for (int i = 0; i < (int)input.size(); i++)
    {
        if(i < (int)input.size() - 1)
        {
            printf("%d, ", input[i]);
        }
        else
        {
            printf("%d}\n", input[i]);
        }
    }
    return EXIT_SUCCESS;
}