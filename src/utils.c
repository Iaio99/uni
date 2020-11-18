#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"
#include <courses_utils.h>

int len_courses(course_t array[]) {
    return sizeof(*array)/24;
}

void list_dir() {
    DIR *d;
    struct dirent *dir;
    int i = 1;

    char *cwd;

    d = opendir(".");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(cwd, "Dispense")) {
                printf("%d. ", i);
                i++;
            }

            printf("%s\n", dir->d_name);
        }
            
    closedir(d);
    }
}


void open_file(int fd) {
    DIR *d;
    struct dirent *dir;
    int i = 0;

    d = opendir(".");

    if (d) {
        for (; i<fd; i++) {
            dir = readdir(d);
        }

        execlp("xdg-open", "xdg-open", dir->d_name, NULL);
            
    closedir(d);
    }
}
