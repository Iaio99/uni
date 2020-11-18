#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <utils.h>
#include "courses_utils.h"

course_t courses[] = {
    {"bd",      "Basi di Dati",                                 (*Basi_di_Dati)},
    {"ia",      "Ingegneria degli Algoritimi",                  (*Ingegneria_degli_Algoritmi)},
    {"ispw",    "Ingegneria del Software e Progettazione Web",  (*Ingegneria_del_Software_e_Progettazione_Web)},
    {"ro",      "Ricerca Operativa",                            (*Ricerca_Operativa)},
    {"so",      "Sistemi Operativi",                            (*Sistemi_Operativi)},
    {0,         0,                                              0}
};

bool Sistemi_Operativi(int opt) {
    int err, fd;

    switch(opt) {
        case 'a':
            system("xdg-open Appunti_SO.tex");
            break;

        case 'd':
            chdir("Dispense");

            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'e':
            chdir("Esercizi");

            char *file;
            printf("Inserisci nome del file: ");
            scanf("%ms", &file);
            file = (char *)(realloc(file, strlen(file+2)));
            strcpy(&file[strlen(file)],".c");
            execlp("code-oss", "code-oss", file, NULL);

            break;

        case 't':
            chdir("Tutoraggio");

            list_dir();
            int fd;
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'v':
            chdir("Videolezioni");
            
            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'x':
            chdir("Esempi");

            list_dir();
            scanf("%d", &fd);
            open_file(fd);

            break;

        case '0':
        case '?':
        default:
            printf("Feature not implemented\n");
            return false;
    }

    return true;
}

bool Basi_di_Dati(int opt) {
    int err, fd;

    switch(opt) {
        case 'a':
            system("xdg-open Appunti_BD.tex");
            break;

        case 'd':
            chdir("Dispense");

            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'p':
            chdir("Progetto");
            system("dolphin .");
            
            break;

        case 't':
            chdir("Tutoraggio");
            
            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case '0':
        case '?':
        default:
            printf("Feature not implemented\n");
            return false;
    }

    return true;
}

bool Ricerca_Operativa(int opt) {
    int err, fd;

    switch(opt) {
        case 'a':
            system("xdg-open Appunti_RO.tex");
            break;

        case 'd':
            chdir("Dispense");

            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 't':

            list_dir();
            int fd;
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'v':
            chdir("Videolezioni");
            
            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case '0':
        case '?':
        default:
            printf("Feature not implemented\n");
            return false;
    }

    return true;
}

bool Ingegneria_degli_Algoritmi(int opt) {
    int err, fd;

    switch(opt) {
        case 'a':
            system("xdg-open Appunti_IA.tex");
            break;

        case 'e':
            chdir("Esercizi");

            char *file;
            scanf("%ms", &file);
            file = (char *)(realloc(file, strlen(file+2)));
            strcpy(&file[strlen(file)],".py");
            execlp("code-oss", "code-oss", file, NULL);

            break;

        case 'v':
            chdir("Videolezioni");
            
            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'x':
            chdir("Esempi");

            list_dir();
            scanf("%d", &fd);
            open_file(fd);

            break;

        case '0':
        case '?':
        default:
            printf("Feature not implemented\n");
            return false;
    }
    return true;
}

bool Ingegneria_del_Software_e_Progettazione_Web(int opt) {
    int err, fd;

    switch(opt) {
        case 'a':
            system("xdg-open Appunti_ISPW.tex");
            break;

        case 'd':
            chdir("Dispense");

            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case 'p':
            chdir("Progetto");
            
            system("dolphin .");

            break;

        case 'v':
            chdir("Videolezioni");
            
            list_dir();
            printf("Inserisci il numero del file che vuoi aprire: ");
            scanf("%d", &fd);
            open_file(fd);

            break;

        case '0':
        case '?':
        default:
            printf("Feature not implemented\n");
            return false;
    }
    return true;
}