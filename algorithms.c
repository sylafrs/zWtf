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
        }
        else if(leftSize > 0) {
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
        first = array+imid*varSize;
        while((cmpFct(first-varSize, value) == 0) && first >= array) {
            first -= varSize;
        }
    }

    return first;
}

/*int binary_search(int A[], int key, int imin, int imax)
{
  // continue searching while [imin,imax] is not empty
  while (imax >= imin)
    {
      // calculate the midpoint for roughly equal partition
      int imid = (imin + imax) / 2;

      // determine which subarray to search
      if      (A[imid] <  key)
        // change min index to search upper subarray
        imin = imid + 1;
      else if (A[imid] > key )
        // change max index to search lower subarray
        imax = imid - 1;
      else
        // key found at index imid
        return imid;
  }
  // key not found
  return KEY_NOT_FOUND;
}*/

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

