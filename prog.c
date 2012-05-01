#include "ressources.h"
#include "algorithms.h"
#include "acronym.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7

int cmpint(const void * a, const void * b) {
    int * v1 = (int*)a;
    int * v2 = (int*)b;
    return *v1-*v2;
}

void printest(const int * t) {
    int i;
    for(i=0;i<M;i++){
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main(void) {

    /*unsigned int size;
    Acronym * acronyms;

    printf("** zWTF (niveau 2) **\n\n");

    loadAcronyms("wtf", "define", &acronyms, &size);
    if(acronyms == NULL) {
        goto errLoad;
    }

    printf("Acronyme : ");
    fflush(stdout);

    char * wtf;
    if(!myGetLine(stdin, &wtf)) {
        goto errStr;
    }

    const Acronym * acronym = getFirstAcronym(acronyms, size, wtf);
    if(acronym != NULL) {
        printf("Définitions :\n");
        while(strcmp(acronym->wtf, wtf) == 0) {
            printf("\t- %s\n", acronym->def);
            acronym++;
        }
    }
    else {
        printf("Aucune définition trouvée\n");
    }

    free(wtf);
errStr:
    freeAcronyms(acronyms, size);
errLoad:
    return 0;*/

    int test[] = {5, 1, 7, 2, 4, 3, 6};

    printest(test);
    const void ** array = (const void **)test;
    mergeSort(array, sizeof(int), M, cmpint);
    printest(test);

    return 0;
}
