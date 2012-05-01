#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include <stdio.h>
#include "acronym.h"

void loadAcronyms(const char * wtfPath, const char * defPath, Acronym ** acronyms, size_t * size);
char loadAcronym(FILE * wtfFile, FILE * defFile, Acronym * acronym);
char myGetLine(FILE * file, char ** string);
void freeAcronym(Acronym * acronym);
void freeAcronyms(Acronym * acronyms, unsigned int size);

#endif//RESSOURCES_H_
