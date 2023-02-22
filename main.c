/*
   # *******************************************************
   # Nom ......... : main.c
   # Rôle ........ : Exercices sur les structures de données en C
   # Auteur ...... : Jeremy Fouquet
   # Version ..... : V1 2022
   # Licence ..... : Réalisé dans le cadre du cours de La Licence Informatique de L IED
   # Compilation :  gcc main.c
   # Execution : ./a.out
   # *******************************************************
*/

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define str char *

typedef struct {
    int numero[3];
    char voie[8];
    char nom_de_la_voie[30];
    char ville[10];
    int code_postal[5];
} adresse;

void exercice_A_1(const str, const str) ; // prototyp
void exercice_A_2(const str, const str) ; // prototyp
void exercice_A_3(const str, const str) ; // prototyp
void lectureF(const str, const int, const char format[2], const str) ; // prototyp
void lectureD(const str, const int, const char format[2], const str) ; // prototyp
void lectureL(const str, const int, const char format[2], const str) ; // prototyp
void lectureI(const str, const int, const char format[2], const str) ; // prototyp
void lectureC(const str, const int, const char format[2], const str) ; // prototyp
void lectureStructure(const str) ; // prototyp
void lectureStructureTaille(const str, const int) ; // prototyp
void usage(const str, const str) ; // prototyp



int main(int k, const str ldc[], const str envp[]) {
    printf("%s\n", "A. Exercices sur les structures de données");
    puts("");
    exercice_A_1("A.1 Vecteurs", "A1.txt");
    exercice_A_2("A.2 Agrégats", "A2.txt");
    exercice_A_3("A.3 Vecteurs d'agrégats", "A3.txt");
    return 0 ;
}

void exercice_A_1(const str titre, const str nomFichier) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrivez un programme qui lit une suite de nombres dans un fichier et les met dans un vecteur (une table). Affichez chaque nombre avec son indice dans la table. On suppose connue à l’avance la taille de la suite. Exemple : le fichier contient « 21<CR> 23<CR> 275.4<CR>... ». <CR> symbolise un retour-charriot). Le programme affiche :");
    puts("");
    printf("%s\n", "Testez le même fichier avec différentes sortes de formats d’entrée (float et décimal) et avec différents types de tables (tables de char, de float, d’int, de long int, etc).");
    puts("");
    int tailleSuite = 6;
    lectureF(nomFichier, tailleSuite, "%f", "float") ;
    lectureD(nomFichier, tailleSuite, "%lf", "double") ;
    lectureL(nomFichier, tailleSuite, "%d", "integer") ;
    lectureI(nomFichier, tailleSuite, "%ld", "long int") ;
    lectureC(nomFichier, tailleSuite, "%ld", "char") ;
}

void exercice_A_2(const str titre, const str nomFichier) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrivez un programme qui lit une suite d’adresses dans un fichier et les met dans une structure. Affichez les parties de la structure.Exemple : le fichier contient « 5 <CR> rue <CR> Guy de la Brosse <CR> Paris <CR> 75005<CR> ... ». Le programme affiche :");
    puts("");
    lectureStructure("A2.txt");
}

void exercice_A_3(const str titre, const str nomFichier) {
    printf("%s\n", titre);
    puts("");
    printf("%s\n", "Écrivez un programme qui lit une suite d’adresses dans un fichier et les met dans une table de structures. Combinez le résultat des deux programmes précédents.");
    puts("");
    printf("%s\n", "Testez le même fichier avec différentes sortes de formats d’entrée (float et décimal) et avec différents types de tables (tables de char, de float, d’int, de long int, etc).");
    puts("");
    int tailleSuite = 6;
    lectureStructureTaille("A3.txt", tailleSuite);
}

void lectureF(const str filename, const int taille, const char format[2], const str type) {
    printf ("Type : %s\n", type) ;
    float monVecteur[taille], lu = 0, valeur = 0 ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
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
    printf ("Type : %s\n", type) ;
    double monVecteur[taille], lu = 0, valeur = 0 ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
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
    printf ("Type : %s\n", type) ;
    long int monVecteur[taille], lu = 0, valeur = 0 ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
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
    printf ("Type : %s\n", type) ;
    int monVecteur[taille], lu = 0, valeur = 0 ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
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
void lectureC(const str filename, const int taille, const char format[2], const str type) {
    printf ("Type : %s\n", type) ;
    char monVecteur[taille], lu = 0, valeur = 0 ;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
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

void lectureStructure(const str filename) {
    adresse monAdresse = {1};
    char cr[5] = { "<CR>" }, separateur; // Definition du séparateur
    char lu = 0;
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
    for (int max = 0 ; max < 5 && EOF != lu; ++max) {
        if(max == 0) {
            lu = fscanf(R, "%d", monAdresse.numero) ;
            separateur = fscanf(R, "%s", cr) ;
        }
        else if(max == 1) {
            int index = 0;
            int nb_mots = 0 ;
            str mots[10] ;
            char stop[32] = {1} ;
            while(lu != EOF && strcmp(stop,cr) != 0) {
                lu = fscanf(R, "%s", stop);
                if (! lu) usage(filename, "Le fichier contier des caractères non autorisés") ;
                if(strcmp(stop,cr) != 0) {
                    mots[nb_mots] = strdup(stop) ;
                    mots[++nb_mots] = " " ;
                    nb_mots++ ;
                }
            }
            for (int iMot = 0; iMot < nb_mots; iMot++) {
                for (int iLettre = 0; iLettre < strlen(mots[iMot]); iLettre++) {
                    monAdresse.voie[index++] = mots[iMot][iLettre];
                }
            }
        }
        else if(max == 2) {
            int index = 0;
            int nb_mots = 0 ;
            str mots[10] ;
            char stop[32] = {1} ;
            while(lu != EOF && strcmp(stop,cr) != 0) {
                lu = fscanf(R, "%s", stop);
                if (! lu) usage(filename, "Le fichier contier des caractères non autorisés") ;
                if(strcmp(stop,cr) != 0) {
                    mots[nb_mots] = strdup(stop) ;
                    mots[++nb_mots] = " " ;
                    nb_mots++ ;
                }
            }
            for (int iMot = 0; iMot < nb_mots; iMot++) {
                for (int iLettre = 0; iLettre < strlen(mots[iMot]); iLettre++) {
                    monAdresse.nom_de_la_voie[index++] = mots[iMot][iLettre];
                }
            }
        }
        else if(max == 3) {
            int index = 0;
            int nb_mots = 0 ;
            str mots[10] ;
            char stop[32] = {1} ;
            while(lu != EOF && strcmp(stop,cr) != 0) {
                lu = fscanf(R, "%s", stop);
                if (! lu) usage(filename, "Le fichier contier des caractères non autorisés") ;
                if(strcmp(stop,cr) != 0) {
                    mots[nb_mots] = strdup(stop) ;
                    mots[++nb_mots] = " " ;
                    nb_mots++ ;
                }
            }
            for (int iMot = 0; iMot < nb_mots; iMot++) {
                for (int iLettre = 0; iLettre < strlen(mots[iMot]); iLettre++) {
                    monAdresse.ville[index++] = mots[iMot][iLettre];
                }
            }
        }
        else {
            lu = fscanf(R, "%d", monAdresse.code_postal) ;
            separateur = fscanf(R, "%s", cr) ;
        }
        if (! lu) usage(filename, "Le format du fichier n'est pas correcte. ex : numero(3) <CR> voie(8) <CR> nom de la voie(30) <CR> ville(10) <CR> code postal(5) <CR>") ;
    }
    printf( "Numéro : %d\n", * monAdresse.numero);
    printf( "Voie : %s\n", monAdresse.voie);
    printf( "Nom de la voie : %s\n", monAdresse.nom_de_la_voie);
    printf( "Ville : %s\n", monAdresse.ville);
    printf( "Code postal: %d\n", * monAdresse.code_postal);
    puts("");
}

void lectureStructureTaille(const str filename, const int taille) {
    adresse monVecteur[taille];
    FILE * R = fopen(filename, "r") ; // ouvre le canal R en mode "r" pour le fichier avec le nom filename
    if (! R) usage(filename, "Fichier non lisible") ; // si pas de fichier appel usage(const str, const str)
    char cr[5] = {"<CR>"}, separateur, lu = 0;
    for (int maxTaille = 0 ; maxTaille < taille && EOF != lu ; maxTaille++) {
        for (int max = 0 ; max < 5 && EOF != lu; ++max) {
            if(max == 0) {
                lu = fscanf(R, "%d", monVecteur[maxTaille].numero) ;
                separateur = fscanf(R, "%s", cr) ;
            }
            else if(max == 1) {
                int index = 0;
                char stop[32] = {1} ;
                while(lu != EOF && strcmp(stop,cr) != 0) {
                    lu = fscanf(R, "%s", stop);
                    if (! lu) usage(filename, "Le fichier contier des caractères non autorisés") ;
                    if(strcmp(stop,cr) != 0) {
                        const str mot = strdup(stop) ;
                        if(index>0) {monVecteur[maxTaille].voie[index] = * " ";  index++; };
                        for (int iLettre = 0; iLettre < strlen(mot); iLettre++) {
                            monVecteur[maxTaille].voie[index] = mot[iLettre] ;
                            index++;
                        }
                    }
                }
            }
            else if(max == 2) {
                int index = 0;
                char stop[32] = {1} ;
                while(lu != EOF && strcmp(stop,cr) != 0) {
                    lu = fscanf(R, "%s", stop);
                    if (! lu) usage(filename, "Le fichier contier des caractères non autorisés") ;
                    if(strcmp(stop,cr) != 0) {
                        const str mot = strdup(stop) ;
                        if(index>0) {monVecteur[maxTaille].nom_de_la_voie[index] = *" ";  index++; };
                        for (int iLettre = 0; iLettre < strlen(mot); iLettre++) {
                            monVecteur[maxTaille].nom_de_la_voie[index] = mot[iLettre] ;
                            index++;
                        }
                    }
                }
            }
            else if(max == 3) {
                int index = 0;
                char stop[32] = {1} ;
                while(lu != EOF && strcmp(stop,cr) != 0) {
                    lu = fscanf(R, "%s", stop);
                    if (! lu) usage(filename, "Le fichier contier des caractères non autorisés") ;
                    if(strcmp(stop,cr) != 0) {
                        const str mot = strdup(stop) ;
                        if(index>0) {monVecteur[maxTaille].ville[index] = *" ";  index++; };
                        for (int iLettre = 0; iLettre < strlen(mot); iLettre++) {
                            monVecteur[maxTaille].ville[index] = mot[iLettre] ;
                            index++;
                        }
                    }
                }
                
            }
            else {
                lu = fscanf(R, "%d", monVecteur[maxTaille].code_postal) ;
                separateur = fscanf(R, "%s", cr) ;
            }
            if (! lu) usage(filename, "Le format du fichier n'est pas correcte. ex : numero(3) <CR> voie(8) <CR> nom de la voie(30) <CR> ville(10) <CR> code postal(5) <CR>") ;
        }
    }
    for (int i = 0; i < taille; i++) {
        printf( "Numéro : %d\n", * monVecteur[i].numero);
        printf( "Voie : %s\n", monVecteur[i].voie);
        printf( "Nom de la voie : %s\n", monVecteur[i].nom_de_la_voie);
        printf( "Ville : %s\n", monVecteur[i].ville);
        printf( "Code postal: %d\n", * monVecteur[i].code_postal);
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

