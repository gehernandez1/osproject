#include <stdio.h>
#include <stdlib.h>
#include "helperFunctions.h"


int main()
{

//shell initialization

char* commandLine = (char*)malloc(LINE_LEN);//holds the comamnd line inputed by the user

struct command_t command ; //stores the tokenized command line


printPrompt();

readCommand(commandLine);

parseCommand(commandLine, &command);
int i = 0 ;
for(i; i < command.argc ; i++)
{
    printf("%s\n",command.argv[i]);

}




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

        /*if(command.name == NULL)
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

    return EXIT_SUCCESS ;
}
