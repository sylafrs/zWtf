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

void * mergeSort(void * array, size_t varSize, const unsigned int size, COMPARE cmpFct) {

    // if the array has only one element, it is sorted !
    if(size == 1) {
        return array;
    }

    // Split the array to two array
    unsigned int leftSize = size/2;
    void * left = malloc(leftSize*varSize);
    memcpy(left, array, leftSize*varSize);

    unsigned int rightSize = size-leftSize;
    void * right = malloc(rightSize*varSize);
    memcpy(right, array+(leftSize*varSize), rightSize*varSize);

    // Sort these array
    mergeSort(left, varSize, leftSize, cmpFct);
    mergeSort(right, varSize, rightSize, cmpFct);

    // Merge the result into tmp
    unsigned int i = 0;
    void * ptrLeft = left;
    void * ptrRight = right;
    while(i < size) {
        if(leftSize > 0 && rightSize > 0) {
            if(cmpFct(ptrLeft, ptrRight) <= 0) {
                memcpy(array+i*varSize, ptrLeft, varSize);
                ptrLeft+=varSize;
                leftSize--;
            }
            else {
                memcpy(array+i*varSize, ptrRight, varSize);
                ptrRight+=varSize;
                rightSize--;
            }
            
            i++;
        }
        else if(leftSize > 0) {
            memcpy(array+i*varSize, ptrLeft, varSize*leftSize);            
            i+=leftSize;
            leftSize = 0;
        }
        else {
            memcpy(array+i*varSize, ptrRight, varSize*rightSize);
            i+=rightSize;
            rightSize = 0;
        }        
    }

    free(left);
    free(right);

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

