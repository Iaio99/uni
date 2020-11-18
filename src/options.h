#pragma once
#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <getopt.h>

static struct option long_options[] = {
    {"addcourse",   no_argument,    0,  'A'},
    {"opencourse",  no_argument,    0,  'O'},
    {"notes",       no_argument,    0,  'a'},
    {"exercise",    no_argument,    0,  'e'},
    {"project",     no_argument,    0,  'p'},
    {"tutoring",    no_argument,    0,  't'},
    {"video",       no_argument,    0,  'v'},
    {"examples",    no_argument,    0,  'x'},
    {0,             0,              0,  0}
};

#endif