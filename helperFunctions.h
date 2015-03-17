
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include "minishell.h"

//prints prompt to screen
void printPrompt();

//reads the command inputed into the prompt
void readCommand(char *buffer);

//parses the command by taking the line and tokenizing into
//array of character strings, returns one if successfull
int parseCommand(char *,struct command_t *);

//parses the PATH variable before it begins reading
//command lines.
int parsePath(char **);

//Chech if command is an excecutable file
//in one of the directories specified by path
//returns the full path name to the file
char* lookupPath(char **,char **);


/**************************************
    FUNCTION DEFINITION
**************************************/

//prints command prompt to screen
void printPrompt()
{
    char hostname[MAX_HOSTNAME] ;
    size_t len  ;
    //geting the user name
    struct passwd *p = getpwuid(getuid());

    //geting the hostname
    gethostname(hostname,len);

    //prints the cmd prompt
    printf("%s@%s>>\n",p->pw_name,hostname);




}

//reads a line of input
void readCommand(char *buffer)
{
    size_t len ;
    getline(&buffer,&len,stdin);

}
