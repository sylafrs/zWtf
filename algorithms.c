#include "algorithms.h"
#include <stddef.h>
#include <string.h>

int acronymCmp(const void * a, const void * b) {
    const Acronym * acronym1 = (const Acronym *)a;
    const Acronym * acronym2 = (const Acronym *)b;

    int res = strcmp(acronym1->wtf, acronym2->wtf);
    if(res == 0) {
        res = strcmp(acronym1->def, acronym2->def);
    }

    return res;
}

const Acronym * getFirstAcronym(const Acronym * acronyms, unsigned int size, const char * wtf) {

    // Pour le moment

    // Suppose le tableau déjà trié; fait une recharche bidon

    const Acronym * acronym = NULL;
    unsigned int i = 0;    
    while(i < size && acronym == NULL) {
        if(strcmp(acronyms[i].wtf, wtf) == 0) {
            acronym = (acronyms+i);
        }
        i++;
    }

    return acronym;
}
