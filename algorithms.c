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

const void ** mergeSort(const void ** array, size_t varSize, const unsigned int size, COMPARE cmpFct) {

    // if the array has only one element, it is sorted !
    if(size == 1) {
        return array;
    }

    // Split the array to two array
    const void ** left = array;
    unsigned int leftSize = size/2;
    const void ** right = array+(leftSize*varSize);
    unsigned int rightSize = size-leftSize;

    // Sort these array
    left = mergeSort(left, varSize, leftSize, cmpFct);
    right = mergeSort(right, varSize, rightSize, cmpFct);

    // Merge the result into tmp
    const void * tmp[size];
    unsigned int i = 0;
    while(i < size) {
        if(leftSize > 0 && rightSize > 0) {
            if(cmpFct(left, right) <= 0) {
                tmp[i] = left;
                left+=varSize;
                leftSize--;
            }
            else {
                tmp[i] = right;
                right+=varSize;
                rightSize--;
            }
        }
        else if(leftSize > 0) {
            tmp[i] = left;
            left+=varSize;
            leftSize--;
        }
        else {
            tmp[i] = right;
            right+=varSize;
            rightSize--;
        }

        i++;
    }

    // Array <- tmp
    for(i = 0; i < size; i++) {
        *(array + (i*varSize)) = *(tmp + (i*varSize));
    }

    return array;
}

char isSorted(const void ** array, size_t varSize, unsigned int size, COMPARE cmpFct) {

    char sorted = 1;
    unsigned char i = 1;
    while(i < size && sorted) {
        sorted = (cmpFct(array+(i-1)*varSize, array+i*varSize) <= 0);
        i++;
    }

    return sorted;
}

const void * binarySearch(const void ** array, size_t varSize, unsigned int size, const void * value, COMPARE cmpFct) {
    return 0;
}

const Acronym * getFirstAcronym(const Acronym * acronyms, unsigned int size, const char * wtf) {

    const void ** array = (const void **)acronyms;
    const void * value = (const void *)wtf;
    size_t varSize = sizeof(Acronym);
    COMPARE cmpFct = acronymCmp;

    if(!isSorted(array, varSize, size, cmpFct)) {
        mergeSort(array, varSize, size, cmpFct);
    }

    return (const Acronym *)binarySearch(array, varSize, size, value, cmpFct);
}

