#include <stdio.h>
#include <stdlib.h>

struct figure {
    int type;
    char typename[10];
    int params[8];
};

int gettype(struct figure *p);

void main()
{
    FILE* fin;
    fin = fopen("./input.txt", "r");

    struct figure* p;
    struct figure data[10];
	int count = 0;
    
    while (fscanf(fin, "%s", data[count].typename) != EOF) {
        p = &data[count];
        p->type = gettype(p);
        if (p->type == 0) {
            printf("unnown shape '%s'\n", p->typename);
        } else {
            printf("%s\n", data[count].typename);
        }

	fclose(fin);
return;
}

int gettype(struct figure *p)
{
    char crcl[] = {"circle"};
    char trngle[] = {"triangle"};
    int type_flag = 0;


    if (strlen(p->typename) == strlen(crcl)) {
        for (int j = 0; j < strlen(crcl); j++) {
            if (p->typename[j] == crcl[j]) {
                type_flag = 1;
                continue;
            } else {
                type_flag = 0;
                break;
            }
        }

    } else if (strlen(p->typename) == strlen(trngle)) {
        for (int j = 0; j < strlen(trngle); j++) {
            if (p->typename[j] == trngle[j]) {
                type_flag = 2;
                continue;
            } else {
                type_flag = 0;
                break;
            }
        }
    }
    return type_flag;
}

