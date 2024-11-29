#include "utilities.h"

void error(const char* msg){
    fprintf(stderr, "[  Error  ]: %s\n.", msg);
}

void info(const char* msg){
    fprintf(stderr, "[  Info.  ]: %s\n.", msg);
}

void warning(const char* msg){
    fprintf(stderr, "[ Warning ]: %s\n.", msg);
}