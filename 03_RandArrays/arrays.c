#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    // Fill an array with random ints

    int nums[10];
    for(int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++){
        nums[i] = rand();
    }
    nums[9] = 0;

    // Print the array

    printf("Random array: \n");
    for(int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Populate array in reverse with pointers

    int pointy_nums[10];
    int * end_point = nums + 9;    // Set pointer to end of nums array

    for(int i = 0; i < 10; i++){
        *(pointy_nums+i) = *(end_point-i);
    }

    // Print the array

    printf("Reversed random array: \n");
    for(int i = 0; i < sizeof(pointy_nums) / sizeof(pointy_nums[0]); i++){
        printf("%d ", pointy_nums[i]);
    }
    printf("\n");

    return 0;
}
