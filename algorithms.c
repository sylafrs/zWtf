#include "algorithms.h"
#include <stdlib.h>
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

int wtfCmp(const void * a, const void * b) {
    const Acronym * acronym = (const Acronym *)a;
    const char * wtf = (const char *)b;

    return strcmp(acronym->wtf, wtf);
}

void * mergeSort2(void * array1, void* array2, size_t varSize, const unsigned int size, COMPARE cmpFct) {

    /* Divide by 2 ( + swap) */
    unsigned int leftSize = size/2;
    unsigned int rightSize = size-leftSize;

    void* left1 = array1;
    void* right1 = array1 + (leftSize * varSize);

    void* left2 = array2;
    void* right2 = array2 + (leftSize * varSize);

    if(leftSize > 1) {
        mergeSort2(left2, left1, varSize, leftSize, cmpFct);
    }
    if(rightSize > 1) {
        mergeSort2(right2, right1, varSize, rightSize, cmpFct);
    }

    /* Merge */
    void * array = array1;
    while(leftSize > 0 && rightSize > 0) {
        if(cmpFct(left2, right2) < 0) {
            memcpy(array, left2, varSize);
            left2 += varSize;    
            leftSize--;
        }
        else {
            memcpy(array, right2, varSize);
            right2 += varSize;
            rightSize--;
        }
        array += varSize;
    }   

    if(leftSize > 0) {
        memcpy(array, left2, leftSize);
        array += leftSize;
    }

    if(rightSize > 0) {
        memcpy(array, right2, rightSize);
    }

    return array1;
}

void * mergeSort(void * array, size_t varSize, const unsigned int size, COMPARE cmpFct) {

    void * tmp = malloc(size*varSize);
    if(tmp == NULL) {
        return NULL;
    }

    memcpy(tmp, array, size*varSize);
    mergeSort2(array, tmp, varSize, size, cmpFct);

    free(tmp);
    return array;
}

char isSorted(const void * array, size_t varSize, unsigned int size, COMPARE cmpFct) {

    char sorted = 1;
    unsigned char i = 1;
    while(i < size && sorted) {
        sorted = (cmpFct(array+(i-1)*varSize, array+i*varSize) <= 0);
        i++;
    }

    return sorted;
}

const void * binarySearch(const void * array, size_t varSize, unsigned int size, const void * value, COMPARE cmpFct) {

    unsigned int imin = 0;
    unsigned int imax = size-1;
    unsigned int imid;

    char found = 0;

    while(!found && imax >= imin) {
        imid = (imin+imax)/2;

        // Divide the searching area by 2
        if(cmpFct(array+(imid*varSize), value) < 0)
            imin = imid + 1;
        else if(cmpFct(array+(imid*varSize), value) > 0)
            imax = imid - 1;
        else
            found = 1;
    }

    const void * first = NULL;

    if(found) {
        first = array+(imid*varSize);
        while(first-varSize >= array && (cmpFct(first-varSize, value) == 0)) {
            first -= varSize;
        }
    }

    return first;
}

const Acronym * getFirstAcronym(const Acronym * acronyms, unsigned int size, const char * wtf) {

    void * array = (void *)acronyms;
    size_t varSize = sizeof(Acronym);

    if(!isSorted(array, varSize, size, acronymCmp)) {
        mergeSort(array, varSize, size, acronymCmp);
    }

    const void * value = (const void *)wtf;
    return (const Acronym *)binarySearch(array, varSize, size, value, wtfCmp);
}

