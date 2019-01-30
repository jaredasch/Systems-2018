#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int n){
	int size = (int) (n * log(n) * 1.15);
	char *numberBool = calloc(1, size); // 0 if "prime", anything else if composite

	int i = 2;
	int primes = 0;

	while(primes != n){
		if(numberBool[i] == 0){
			primes++;
			for(int j = i; j < size; j += i){
				if(!numberBool[j])
					numberBool[j] = 1;
			}
		}
		i++;
	}
	return i-1;
}