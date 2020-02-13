#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution;
    std::vector<int> input = {1, 2, 3, 4, 5, 6};
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

    printf("************* filter_odds(input)*************\n");
    std::vector<int> output = solution.filter_odds(input);
    printf("output = {");
    for (int i = 0; i < (int)output.size(); i++)
    {
        if(i < (int)output.size() - 1)
        {
            printf("%d, ", output[i]);
        }
        else
        {
            printf("%d}\n", output[i]);
        }
    }

    printf("************* map_square(input)*************\n");
    output = solution.map_square(input);
    printf("output = {");
    for (int i = 0; i < (int)output.size(); i++)
    {
        if(i < (int)output.size() - 1)
        {
            printf("%d, ", output[i]);
        }
        else
        {
            printf("%d}\n", output[i]);
        }
    }

    printf("************* reduce(input)*************\n");
    int result = solution.reduce(input);
    printf("result = %d\n", result);

    return EXIT_SUCCESS;
}