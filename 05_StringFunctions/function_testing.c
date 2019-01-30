#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_functions.h"

int main() {
    char s1[20] = "hello";
    char s2[20] = "wassup";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    printf("\n---- Testing length() ----\n");
    printf("length(s1): %d \nstrlen(s1): %lu \n\n", length(s1), strlen(s1));
    printf("length(s2): %d \nstrlen(s2): %lu \n", length(s2), strlen(s2));

    printf("\n---- Testing copy() ----\n");
    printf("copy(s1, s2): %s\n", copy(s1, s2));
    copy(s1, "hello");  // Reset back to original value for tests
    printf("strcpy(s1, s2): %s\n", strcpy(s1, s2));
    copy(s1, "hello");  // Reset back to original value for tests

    printf("\n---- Testing cat() ----\n");
    printf("cat(s1, s2): %s\n", cat(s1, s2));
    copy(s1, "hello");  // Reset back to original value for tests
    printf("strcpy(s1, s2): %s\n", strcat(s1, s2));
    copy(s1, "hello");  // Reset back to original value for tests

    printf("\n---- Testing find_char() ----\n");
    printf("find_char(s1, 'l'): %p\nstrchr(s1, 'l'): %p\n\n", find_char(s1, 'l'), strchr(s1, 'l'));
    printf("find_char(s2 'x'): %p\nstrchr(s2, 'x'): %p\n", find_char(s2, 'x'), strchr(s2, 'x'));

    printf("\n---- Testing ncopy() ----\n");
    printf("ncopy(s1, s2, 3): %s\n", ncopy(s1, s2, 3));
    copy(s1, "hello");  // Reset back to original value for tests
    printf("strncpy(s1, s2, 3): %s\n\n", strncpy(s1, s2, 3));
    copy(s1, "hello");  // Reset back to original value for tests

    printf("ncopy(s1, s2, 10): %s\n", ncopy(s1, s2, 10));
    copy(s1, "hello");  // Reset back to original value for tests
    printf("strncpy(s1, s2, 10): %s\n", strncpy(s1, s2, 10));
    copy(s1, "hello");  // Reset back to original value for tests
    return 0;
}
