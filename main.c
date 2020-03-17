#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct figure {
    int type;
    char typename[10];
    int params[8];
};

int gettype(struct figure *p);

int main()
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

    	switch (p->type) {
    		case 1: {
				int e = fscanf(fin, " (%d, %d, %d)", &p->params[0], &p->params[1], &p->params[2]);
				if(e == 3) {
		        	    printf("parameters \t%s\t x=%d\t y=%d\t r=%d\n", p->typename, p->params[0], p->params[1], p->params[2]);
	        	} else {
	        	    printf("vrong parameters \n");
	        	}
	            count++;
	        	break;
	        }
	        case 2: {
	        	int e = fscanf(fin, " (%d, %d, %d, %d, %d, %d, %d, %d)", &p->params[0], &p->params[1], &p->params[2], &p->params[3], &p->params[4], &p->params[5], &p->params[6], &p->params[7]);
				if(e == 8) {
		        	printf("parameters \t%s\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", p->typename, p->params[0], p->params[1], p->params[2], p->params[3], p->params[4], p->params[5], p->params[6], p->params[7]);
	        	} else {
	        	    printf("vrong parameters \n");
	        	}
	           	count++;     	
	        	break;
	        } 
		}
	}


	fclose(fin);
return 0;
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

