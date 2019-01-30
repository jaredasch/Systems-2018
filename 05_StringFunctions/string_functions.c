#include "string_functions.h"

int length(char *str){
    int i = 0;
    while(*str++){
        i++;
    }
    return i;
}

char * copy(char *dest, char *source ){
    char * initial_dest = dest;
    while(*source){
        *dest++ = *source++;
    }
    *dest = 0;
    return initial_dest;
}

char * cat(char *dest, char *source ){
    char *destCpy = dest;
    while(*++dest);
    copy(dest, source);
    return destCpy;
}

char * find_char(char *s, char c ){
    while(*s){
        if(*s == c)  return s;
        s++;
    }
    return 0;
}

char * ncopy(char *dest, char *source, int n){
    char * initial_dest = dest;
    while(n--){
        *dest++ = *source++;
    }
    return initial_dest;
}
