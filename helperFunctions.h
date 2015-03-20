#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int parsePath(char**);

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
    char cwd[1000];
    getcwd(cwd,sizeof(cwd));

    char hostname[MAX_HOSTNAME_LEN] ;

    //geting the user name
    struct passwd *p = getpwuid(getuid());

    //geting the hostname
    gethostname(hostname,MAX_HOSTNAME_LEN);

    //prints the cmd prompt
    printf("%s@%s: %s>> ",p->pw_name,hostname,cwd);//,cwd);


}

//reads a line of input
void readCommand(char *buffer)
{

    size_t bufferSize = LINE_LEN ;


    getline(&buffer,&bufferSize,stdin);

    if(bufferSize > LINE_LEN)
    {
        printf("Command line has exceed maximum number of characters\n");

    }


}

//parses the command by taking the line and tokenizing into
//array of character strings, returns one if successfull
int parseCommand(char *cLine,struct command_t *cmd)
{
    int argc = 0; //number of tokens in array, initialized to zero
    char** clPtr ;

    clPtr = &cLine ; //command line obtained from user

    cmd->argv[argc] = (char*)malloc(MAX_ARG_LEN);

    while((cmd->argv[argc] = strsep(clPtr,WHITESPACE)) != NULL)
    {
        cmd->argv[++argc] = (char*)malloc(MAX_ARG_LEN);
    }

    cmd->argc = argc -1 ;
    cmd->name = (char*)malloc(sizeof(cmd->argv[0]));
    strcpy(cmd->name,cmd->argv[0]);

    return 1 ;


}

//parses the PATH variable before it begins reading
//command lines.
int parsePath(char** dirs)
{
    int i = 0 ;
    char* pathEnvVar ;
    char* thePath ;

    for(i = 0 ; i < MAX_ARGS; i++)
    {
        dirs[i] = NULL ;
    }

    pathEnvVar = (char*)getenv("PATH");
    thePath = (char*)malloc(strlen(pathEnvVar)+1);
    strcpy(thePath,pathEnvVar);

    i = 0 ;

    dirs[i]= (char*)malloc(MAX_PATH_LEN);
    dirs[i]= strtok(thePath,":");


    while(dirs[i] != NULL)
    {
        dirs[++i] = (char*)malloc(MAX_PATH_LEN);
        dirs[i] = strtok(NULL,":");
    }

    return 0 ;
}

//Chech if command is an excecutable file
//in one of the directories specified by path
//returns the full path name to the file
char* lookupPath(char ** argv,char **dir)
{
    int i = 0 ;
    char* result ;
    char pName[MAX_PATH_LEN];


    if(*argv[0] == '/')
    {
        printf("do something");
    }

    while(dir[i] != NULL)
    {
        strcpy(pName,dir[i]);
        strcat(pName,"/");
        strcat(pName,argv[0]);

        if((access(pName,F_OK)) != -1)
        {
            result = (char*)malloc(strlen(pName));
            strcpy(result,pName);

            return result;
        }

        i++ ;
    }


    return NULL ;
}




