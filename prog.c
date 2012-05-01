#include "ressources.h"
#include "algorithms.h"
#include "acronym.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    unsigned int size;
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
    return 0;
}
