#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

    #include "acronym.h"
    #include <stddef.h>

    /**
      * Signature de la fonction de comparaison utilisée dans
      * mes fonctions de gestion de tableaux.
      * Doit retourner une sorte d'écart
      * (du moment que si a > b, la valeur est positive,
      *            que si a = b, la valeur est nulle,
      *         et que si a < b, la valeur est négative)
      */
    typedef int (*COMPARE)(const void * a, const void * b);

    /**
      * Fonction triant le tableau array de taille size en utilisant
      * la fonction pointée par "cmpFct" pour les comparaisons.
      */
    void * mergeSort(void * array, size_t varSize, const unsigned int size, COMPARE cmpFuct);

    /**
      * Regarde si le tableau array de taille size est trié selon la fonction
      * de comparaison cmpFct
      */
    char isSorted(const void * array, size_t varSize, unsigned int size, COMPARE cmpFct);

    /**
      * Fonction cherchant le premier element value dans le tableau array
      * de taille size en utilisant la fonction pointée par "cmpFct"
      * pour les comparaisons.
      */
    const void * binarySearch(const void * array, size_t varSize, unsigned int size,
                              const void * value, COMPARE cmpFct);

    /**
      * Utilise strcmp, compare deux acronymes.
      * La comparaison se fait d'abord sur le WTF puis sur la définition
      */
    int acronymCmp(const void * a, const void * b);

    /**
      * Utilise strcmp, compare le WTF d'un acronyme à une chaine
      */
    int wtfCmp(const void * a, const void * b);

    /**
      * Utilise binarySearch avec acronymCmp
      */
    const Acronym * getFirstAcronym(const Acronym * acronyms, unsigned int size, const char * wtf);

#endif//ALGORITHMS_H_
