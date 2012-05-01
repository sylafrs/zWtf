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

void sort(const void ** array, unsigned int size, COMPARE cmpFct) {

}

char isSorted(const void ** array, unsigned int size, COMPARE cmpFct) {
    return 1;
}

const void * binarySearch(const void ** array, unsigned int size, const void * value, COMPARE cmpFct) {
    return 0;
}

const Acronym * getFirstAcronym(const Acronym * acronyms, unsigned int size, const char * wtf) {

    const void ** array = (const void **)acronyms;
    const void * value = (const void *)wtf;
    COMPARE cmpFct = acronymCmp;

    if(!isSorted(array, size, cmpFct)) {
        sort(array, size, cmpFct);
    }

    return (const Acronym *)binarySearch(array, size, value, cmpFct);
}

