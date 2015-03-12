
#include <stdio.h>
#include <stdlib.h>

//Chech if command is an excecutable file
//in one of the directories specified by path
//returns the full path name to the file
char* lookupPath(char **,char **);

//parses the command by taking the line and tokenizing into
//array of character strings, returns one if successfull
int parseCommand(char *,struct command_t *);

//parses the PATH variable before it begins reading
//command lines.
int parsePath(char **);

//prints prompt to screen
void printPrompt();

//reads the command inputed into the prompt
void readCommand(char *);
