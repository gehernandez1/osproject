#include <pwd.h>
#include <limits.h>
#include <unistd.h>

#define LINE_LEN    80
#define MAX_ARGS    64
#define MAX_ARG_LEN 16
#define MAX_PATHS   64
#define MAX_PATH_LEN    96
#define MAX_HOSTNAME_LEN   20
#define WHITESPACE  " .,\t\n"

typedef enum {FALSE, TRUE} bool ;


struct command_t
{
    char *name ;
    int argc ;
    char* argv[MAX_ARGS] ;

};
