#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include <stdio.h>
#include "acronym.h"

/**
  * Charge la liste d'acronymes contenus dans des fichiers
  * @param wtfPath
  *     Chemin du fichier des acronymes
  * @param defPath
  *     Chemin du fichier des définitions
  * @param acronyms
  *     Pointeur sur un pointeur qui contiendra l'adresse du tableau d'Acronymes
  * @param size
  *     Pointeur sur un entier qui contiendra la taille du tableau
  */
void loadAcronyms(const char * wtfPath, const char * defPath, Acronym ** acronyms, size_t * size);

/**
  * Charge un acronyme contenu dans des fichiers (alloue ses chaines)
  * @param wtfFile
  *     Fichier contenant l'acronyme (curseur au début de la ligne)
  * @param defFile
  *     Fichier contenant le définition (curseur au début de la ligne)
  * @param acronym
  *     Pointeur sur l'acronyme à charger
  * @return 1 en cas de succès, 0 en cas d'erreur
  */
char loadAcronym(FILE * wtfFile, FILE * defFile, Acronym * acronym);

/**
  * Recupère une ligne dans un fichier
  * @param file
  *     Le fichier
  * @param string
  *     Pointeur sur une chaine de caractères allouée dynamiquement.
  *     En cas d'erreur ou si aucun caractère n'est lu,
  *     la chaine est libérée et pointera sur NULL.
  *     En cas de réussite, la chaine contiendra exactement le nombre de
  *     caractères lus.
  * @return 1 en cas de succes, 0 sinon
  */
char myGetLine(FILE * file, char ** string);

/**
  * Libère un acronyme (ses chaines)
  * @param acronym
  *     L'acronyme à liberer
  */
void freeAcronym(Acronym * acronym);

/**
  * Libère une série d'acronymes
  * @param acronyms
  *     Pointeur sur la série d'acronymes
  * @param size
  *     La taille de la série
  */
void freeAcronyms(Acronym * acronyms, unsigned int size);

#endif//RESSOURCES_H_
