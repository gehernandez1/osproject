#include <stdio.h>
#include <stdlib.h>
#include "helperFunctions.h"


int main()
{

//shell initialization
int flag = TRUE ;
char* commandLine ;

    //parsePath(pathv); //get directory paths from path

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
        }*/
        flag = FALSE ;

    }

//create child and execute the command


//wait for the child to terminate

//shell termination


    return 0 ;
}
