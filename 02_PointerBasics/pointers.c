#include <stdio.h>

int print_bytes(unsigned int n){
    char * p = &n;
    for(int i = 0; i < sizeof(n); i++){
        printf("%02hhx ", *(p++));
    }
    printf("\n");
    return 0;
}

int main(){
    unsigned int a = 4123003214;

    print_bytes(a);

    char * p = &a;
    for(int i = 0; i < sizeof(a); i++){
        *p++ = (*p)+1;
    }

    print_bytes(a);

    p = &a;
    for(int i = 0; i < sizeof(a); i++){
        *p++ = (*p)+16;
    }

    print_bytes(a);

    return 0;
}
