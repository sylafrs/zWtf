#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

    #include "acronym.h"

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
      * la fonction pointée par "cmpFunction" pour les comparaisons.
      */
    //void sort(const void ** array, unsigned int size, COMPARE cmpFunction);

    /**
      * Regarde si le tableau array de taille size est trié selon la fonction
      * de comparaison cmpFunction
      */
    //char isSorted(const void ** array, unsigned int size, COMPARE cmpFunction);

    /**
      * Fonction cherchant le premier element value dans le tableau array
      * de taille size en utilisant la fonction pointée par "cmpFunction"
      * pour les comparaisons.
      */
    //const void * binarySearch(const void ** array, unsigned int size, 
    //                        const void * value, COMPARE cmpFunction);

    /**
      * Utilise strcmp
      */
    int acronymCmp(const void * a, const void * b);
    
    /**
      * Utilise binarySearch avec myStrCOMPARE
      */
    const Acronym * getFirstAcronym(const Acronym * acronyms, unsigned int size, const char * wtf);

#endif//ALGORITHMS_H_
