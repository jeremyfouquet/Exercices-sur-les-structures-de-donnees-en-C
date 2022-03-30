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
void lecture_float(const str, const float[]) ; // prototyp
int compte_mots(const str) ; // prototyp
void usage(const str, const str) ; // prototyp



int main(int k, const str ldc[], const str envp[]) {
    printf("%s\n", "A. Exercices sur les structures de données");
    exercice_A_1();
    return 0 ;
}

void exercice_A_1(void) {
    printf("%s\n", "A.1 Vecteurs");
    printf("%s\n", "Écrivez un programme qui lit une suite de nombres dans un fichier et les met dans un vecteur (une table). Affichez chaque nombre avec son indice dans la table. On suppose connue à l’avance la taille de la suite. Exemple : le fichier contient « 21<CR> 23<CR> 275.4<CR>... ». <CR> symbolise un retour-charriot). Le programme affiche :");
    int tailleSuite = 6;
    str fichier = "fichier.txt";
    float monVecteur[tailleSuite] ;
    lecture_float(fichier, monVecteur) ;
}

void lecture_float(const str filename, const float monVecteur[]) {
    int nb_mots = compte_mots(filename) ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour ldc [1]
    if (! R) usage(filename, "Fichier inconnu") ; // si pas de fichier message erreur exit
    str mots[nb_mots] ;
    int lu, max ;
    for (max = 0 ; max < nb_mots ; max++) {
        char sas[32] ;
        lu = fscanf(R, "%s", sas) ;
        mots[max] = strdup(sas) ;
    }
    max = 0 ;
    while(mots[max] && max < nb_mots) {
        printf("%s\n", mots[max++]) ;
    }
    fclose(R) ; // ferme le canal
}

int compte_mots(const str filename) {
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier inconnu") ; // si pas de fichier appel usage(const str, const str)
    char stop[32] ;
    int scan, nb_mots = 0 ;
    while((scan = fscanf(R, "%s", stop)) != EOF) {
        if (scan) nb_mots++ ;
        else usage(filename, "Le fichier contier des caractères non autorisés") ;
    }
    fclose(R) ; // ferme le canal
    return nb_mots ;
}

void usage(const str P, const str D) {
    printf("Provenance de l'ERREUR : %s\n", P);
    printf("Détails de l'ERREUR: %s\n", D);
    exit(1) ;
}

