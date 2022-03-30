//
//  main.c
//  ExoREV1Rigides
//
//  Created by jeremy fouquet on 30/03/2022.
//

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define str char *

void exercice_A_1(void) ; // prototyp
void lectureF(const str, const int, const char format[2], const str type) ; // prototyp
void lectureD(const str, const int, const char format[2], const str) ; // prototyp
void lectureI(const str, const int, const char format[2], const str) ; // prototyp
void lectureL(const str, const int, const char format[2], const str) ; // prototyp
int compte_mots(const str) ; // prototyp
void usage(const str, const str) ; // prototyp



int main(int k, const str ldc[], const str envp[]) {
    printf("%s\n", "A. Exercices sur les structures de données");
    puts("");
    exercice_A_1();
    return 0 ;
}

void exercice_A_1(void) {
    printf("%s\n", "A.1 Vecteurs");
    puts("");
    printf("%s\n", "Écrivez un programme qui lit une suite de nombres dans un fichier et les met dans un vecteur (une table). Affichez chaque nombre avec son indice dans la table. On suppose connue à l’avance la taille de la suite. Exemple : le fichier contient « 21<CR> 23<CR> 275.4<CR>... ». <CR> symbolise un retour-charriot). Le programme affiche :");
    puts("");
    int tailleSuite = 6;
    str fichier = "fichier.txt";
    lectureF(fichier, tailleSuite, "%f", "Float") ;
    lectureD(fichier, tailleSuite, "%lf", "Double") ;
    lectureI(fichier, tailleSuite, "%d", "Integer") ;
    lectureL(fichier, tailleSuite, "%ld", "Long") ;
}

void lectureF(const str filename, const int taille, const char format[2], const str type) {
    float monVecteur[taille] ;
    printf ("Type : %s\n", type) ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
    float valeur, lu = 0;
    str cr;
    str formarSrt = "%s";
    for (int max = 0 ; max < taille && EOF != lu ; ++max) {
        lu = fscanf(R, format, & valeur) ;
        if (! lu) usage(filename, "Le fichier ne contient pas uniquement une suite de nombres.") ;
        fscanf(R, formarSrt, & cr) ;
        monVecteur[max] = valeur;
    }
    char indice[8] = "%d. ";
    strcat(indice, format);
    for (int i = 0 ; i < taille ; i++) {
        printf (indice, i+1, monVecteur[i]) ;
        puts("");
    }
    fclose(R); // ferme le canal
    puts("");
}
void lectureD(const str filename, const int taille, const char format[2], const str type) {
    double monVecteur[taille] ;
    printf ("Type : %s\n", type) ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
    double valeur, lu = 0;
    str cr;
    str formarSrt = "%s";
    for (int max = 0 ; max < taille && EOF != lu ; ++max) {
        lu = fscanf(R, format, & valeur) ;
        if (! lu) usage(filename, "Le fichier ne contient pas uniquement une suite de nombres.") ;
        fscanf(R, formarSrt, & cr) ;
        monVecteur[max] = valeur;
    }
    char indice[8] = "%d. ";
    strcat(indice, format);
    for (int i = 0 ; i < taille ; i++) {
        printf (indice, i+1, monVecteur[i]) ;
        puts("");
    }
    fclose(R); // ferme le canal
    puts("");
}

void lectureI(const str filename, const int taille, const char format[2], const str type) {
    int monVecteur[taille] ;
    printf ("Type : %s\n", type) ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
    int valeur, lu = 0;
    str cr;
    str formarSrt = "%s";
    for (int max = 0 ; max < taille && EOF != lu ; ++max) {
        lu = fscanf(R, format, & valeur) ;
        if (! lu) usage(filename, "Le fichier ne contient pas uniquement une suite de nombres.") ;
        fscanf(R, formarSrt, & cr) ;
        monVecteur[max] = valeur;
    }
    char indice[8] = "%d. ";
    strcat(indice, format);
    for (int i = 0 ; i < taille ; i++) {
        printf (indice, i+1, monVecteur[i]) ;
        puts("");
    }
    fclose(R); // ferme le canal
    puts("");
}

void lectureL(const str filename, const int taille, const char format[2], const str type) {
    long monVecteur[taille] ;
    printf ("Type : %s\n", type) ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
    long valeur, lu = 0;
    str cr;
    str formarSrt = "%s";
    for (int max = 0 ; max < taille && EOF != lu ; ++max) {
        lu = fscanf(R, format, & valeur) ;
        if (! lu) usage(filename, "Le fichier ne contient pas uniquement une suite de nombres.") ;
        fscanf(R, formarSrt, & cr) ;
        monVecteur[max] = valeur;
    }
    char indice[8] = "%d. ";
    strcat(indice, format);
    for (int i = 0 ; i < taille ; i++) {
        printf (indice, i+1, monVecteur[i]) ;
        puts("");
    }
    fclose(R); // ferme le canal
    puts("");
}
void usage(const str P, const str D) {
    printf("Provenance de l'ERREUR : %s\n", P);
    printf("Détails de l'ERREUR: %s\n", D);
    exit(1) ;
}

