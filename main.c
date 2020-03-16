#include <stdio.h>
#include <stdlib.h>

struct figure {
    int type;
    char typename[10];
    int params[8];
};

void main()
{
    FILE* fin;
    fin = fopen("./input.txt", "r");

	fclose(fin);
return;
}
