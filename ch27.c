#include <stdlib.h>
#include <stdio.h>

void print_char_int(const char* p, const int x)
{
    printf("\"%s\" %i\n", p, x);
}

int main()
{
    printf("Hello World!\n");

    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);

    print_char_int("May", 6);
    print_char_int("Chris", 39);
    print_char_int("C", 89);
    return 0;
}