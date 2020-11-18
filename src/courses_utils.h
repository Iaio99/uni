#include <stdio.h>
#include <stdbool.h>

#ifndef _COURSES_UTILS_H
#define _COURSES_UTILS_H

typedef struct course_t {
    char *code;
    char *course;
    bool (*function)();
}course_t;

bool Basi_di_Dati(int);
bool Ingegneria_degli_Algoritmi(int);
bool Ingegneria_del_Software_e_Progettazione_Web(int);
bool Ricerca_Operativa(int);
bool Sistemi_Operativi(int);

extern course_t courses[];

#endif