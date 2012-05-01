#include "ressources.h"
#include "acronym.h"
#include <stdio.h>
#include <stdlib.h>

void loadAcronyms(const char * wtfPath, const char * defPath, Acronym ** acronyms, size_t * size) {
    FILE * wtfFile;
    FILE * defFile;

    *acronyms = NULL;
    *size = 0;
   
    if(!(wtfFile = fopen(wtfPath, "r"))) {
        perror(wtfPath);
        goto errWtf;
    }
    if(!(defFile = fopen(defPath, "r"))) {
        perror(defPath);
        goto errDef;
    }

    Acronym tmpAcronym;
    Acronym * tmpPtr;

    while(loadAcronym(wtfFile, defFile, &tmpAcronym)) {
        (*size)++;

        tmpPtr = (Acronym*)realloc(*acronyms, *size*sizeof(Acronym));
        if(tmpPtr == NULL) {
            perror("realloc Acronym");

            freeAcronyms(*acronyms, *size-1);
            *size = 0;
            *acronyms = NULL;

            goto errAcros;
        }
        *acronyms = tmpPtr;
        (*acronyms)[(*size)-1] = tmpAcronym;
    }    

errAcros:
    fclose(defFile);
errDef:
    fclose(wtfFile);
errWtf:
    ;
}

char loadAcronym(FILE * wtfFile, FILE * defFile, Acronym * acronym) {
 
    if(!myGetLine(wtfFile, &(acronym->wtf))) {
        return 0;
    }

    if(!myGetLine(defFile, &(acronym->def))) {   
        free(acronym->wtf);
        return 0;
    }

    return 1;
}

char myGetLine(FILE * file, char ** string) {
    char * tmpPtr;
    char tmpChar;
    size_t size = 0;

    *string = NULL;
    
    tmpChar = fgetc(file);
    while(tmpChar != '\0' && tmpChar != '\n' && tmpChar != EOF) {
        size++;
        tmpPtr = (char*)realloc(*string, size*sizeof(char));
        if(tmpPtr == NULL) {
            perror("realloc char");

            free(string);
            *string = NULL;
            size = 0;

            return 0;
        }
        *string = tmpPtr;
        (*string)[size-1] = tmpChar;        
        tmpChar = fgetc(file);
    }

    if(!size) {
        return 0;
    }

    size++;
    tmpPtr = (char*)realloc(*string, size*sizeof(char));
    if(tmpPtr == NULL) {
        perror("realloc char");
        free(*string);

        *string = NULL;
        size = 0;

        return 0;
    }
    *string = tmpPtr;
    (*string)[size-1] = '\0';

    return size;
}

void freeAcronym(Acronym * acronym) {
    if(acronym != NULL) {
        free(acronym->def);
        free(acronym->wtf);
    }
}

void freeAcronyms(Acronym * acronyms, unsigned int size) {
    if(acronyms != NULL) {
        unsigned int i = 0;
        while(i < size) {            
            freeAcronym(acronyms+i);
            i++;
        }
        free(acronyms);
    }
}
