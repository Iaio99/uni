#include <ctype.h>
#include <getopt.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#include <utils.h>
#include <options.h>
#include <courses_utils.h>

enum {
    PM_OP_MAIN = 1,
    PM_OP_OPEN,
    PM_OP_ADD
};

extern course_t courses[];

static void usage(int func, char *myname) {
    if (func == PM_OP_MAIN) {
        printf("%s <option> <course>\n", myname);
        printf("\t-A, --add-course: Add course folder in Uni folder\n");
        printf("\t-O, --open-course: Open course folder in Uni fulder\n");
    }

    else {
        if (func == PM_OP_OPEN) {
            printf("Usage {-O --open_course} [option] [code]\n");
            printf("\t-a, --notes: Write notes\n");
            printf("\t-e, --exercise: Exercises\n");
            printf("\t-p, --project: Open project folder\n");
            printf("\t-t, --tutoring: Open tutoring folder\n");
            printf("\t-v, --video: Play a video lesson\n");
            printf("\t-x, --examples: Open examples folder\n");
        }

        else if (func == PM_OP_ADD) {
            printf("Usage {-A --add_course} [option] [course] [code]");
            printf("\t-e --exercise: Create exercises folder\n");
            printf("\t-t --tutoring: Create tutoring folder\n");
            printf("\t-p --project: Create project folder\n");
            printf("\t-v --video: Create a video lesson\n");
            printf("\t-x, --examples: Open examples folder\n");
        }
    }
}


static bool parse_open(int argc, char *argv[], int opt, char *code) {
    if (argc < 3) {
        usage(PM_OP_OPEN, argv[0]);
        return false;
    }

    chdir(getenv("HOME"));
    chdir("Documenti/Uni");
    
    int i = 0;

    for (i=0; i<strlen(code); i++) {
        code[i] = tolower(code[i]);
    }

    while (courses[i].code != 0) {
        if (!strcmp(code,courses[i].code)) {
            chdir(courses[i].course);
            bool x = courses[i].function(opt);
            break;
        }
        i++;
    }
    return true;
}

static bool parse_add(int argc, char *argv[], int opt, char *course, char *code) {
    if (argc < 4) {
        usage(PM_OP_ADD, argv[0]);
        return 0;
    }

    chdir(getenv("HOME"));
    chdir("Documenti/Uni");

    mkdir(course, 0755);
    chdir(course);

    char *notes = (char*)malloc(sizeof(char)*(strlen(code)+13));
    strcpy(notes, "Appunti_");
    strcpy(&notes[8], code);
    strcpy(&notes[8+strlen(code)], ".tex\0");
    
    int fd = creat(notes, 0644);
    close(fd);

    
    switch(opt) {
        case 'e':
            mkdir("Esempi", 0755);
	    break;
        
        case 'p':
            mkdir("Progetto", 0755);
	    break;

        case 't':
            mkdir("Tutoraggio", 0755);
            break;

        case 'v':
            mkdir("Videolezioni", 0755);
	    break;

        case 'x':
            mkdir("Esercizi", 0755);
            break;

        case '0':
        case '?':
        default:
            return false;
    }
    
    return true;
}


static bool parse_commands(int argc, char *argv[]) {
    int opt, option_index, func;
    static bool result;
    const char *optstring = "OAvextpad";

    while((opt = getopt_long(argc, argv, optstring, long_options, &option_index))) {
        func = PM_OP_MAIN;
        
        if (opt == 'A') {
            func = PM_OP_ADD;
            break;
	    }
            
        else if (opt == 'O') {
            func = PM_OP_OPEN;
            break;
	    }
        
        else {
            usage(func, argv[0]);
            return false;
	    }
    }

    int i, k = 0;
    char *course, *code, *cose[] = {NULL, NULL};
    

    for (i = 1; i<argc; i++) {
        if (argv[i][0] != '-') {
	        if (k > 2) break;
	    
	        cose[k] = argv[i];
	        k++;
        }
    }

    course = cose[0];
    code = cose[1];
    
    if (code == NULL && course != NULL) {
        code = course;
    }

    if (func == PM_OP_ADD) {
        for (i = 0; i<strlen(code); i++) {
            code[i] = toupper(code[i]);
        }
    }

    while ((opt = getopt_long(argc, argv, optstring, long_options, &option_index))) {
        if (opt < 0) {
            break;
        }

        switch (func) {
            case PM_OP_ADD:
                result = parse_add(argc, argv, opt, course, code);
            
                break;
                
            case PM_OP_OPEN:
                result = parse_open(argc, argv, opt, code);
                        
                break;
                
            case 0:
            case '?':
            default:
                result = 0;        
            }

        if (result) {
            continue;
        }
    }

    if (!result) {
        usage(func, argv[0]);
        exit(EXIT_FAILURE);
    }

    return true;
}


int main(int argc, char *argv[]) {
    if (!parse_commands(argc, argv)) {
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
