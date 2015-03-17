#include <pwd.h>
#include <limits.h>

#define LINE_LEN    80
#define MAX_ARGS    64
#define MAX_ARG_LEN 16
#define MAX_PATHS   64
#define MAX_PATH_LEN    96
#define MAX_HOSTNAME    20
//#define TRUE 1
//#define FALSE 0
#define WHITESPACE  " .,\t\n"

typedef enum {FALSE, TRUE} bool ;


struct command_t
{
    char *name ;
    int argc ;
    char* argv[MAX_ARGS] ;

};
