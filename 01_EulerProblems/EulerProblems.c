#include <stdio.h>

// Problem 1 - Find the sum of all the multiples of 3 or 5 below 1000.

int problem1(){
    int sum = 0;
    for(int i = 0; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    return sum;
}


// Problem 6 - Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

int sum_of_squares(int n){
    return (2 * n + 1) * (n + 1) * n / 6;
}

int sum(int n){
    return n * (n + 1) / 2;
}

int problem6(){
    return sum(100) * sum(100) - sum_of_squares(100);
}

int main(){
    printf("Problem 1 Solution: %d\n", problem1());
    printf("Problem 6 Solution: %d\n", problem6());
    return 0;
}