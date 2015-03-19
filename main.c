#include "helperFunctions.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{

//shell initialization
char* pathv =(char*)calloc(MAX_PATHS,MAX_PATH_LEN); //array of paths obtained from the path environment variable

char* commandLine = (char*)malloc(LINE_LEN);//holds the comamnd line inputed by the user

struct command_t command ; //stores the tokenized command line


parsePath(&pathv);

//printPrompt();

//readCommand(commandLine);

//parseCommand(commandLine, &command);





/*
    parsePath(pathv); //get directory paths from path

    while(flag)
    {
        printPrompt();


        //Read the command line and parse it
        readCommand(commandLine);

        //parseCommand(commandLine, &command);

        //get the full pathname for the file
        //command.name = lookupPath(command.argv,pathv);

        if(command.name == NULL)
        {
            //report error
            continue ;
        }
        flag = FALSE ;

    }

//create child and execute the command


//wait for the child to terminate

//shell termination
*/

   exit(EXIT_SUCCESS) ;
}
