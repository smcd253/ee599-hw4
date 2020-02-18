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
    int k = 1;
    int k_l = solution.kth_largest(input, k);
    printf("kth_largest(k = %d) = %d\n", k, k_l);
    
    k = 3;
    k_l = solution.kth_largest(input, k);
    printf("kth_largest(k = %d) = %d\n", k, k_l);

    return EXIT_SUCCESS;
}