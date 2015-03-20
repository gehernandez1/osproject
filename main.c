#include "helperFunctions.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{

//shell initialization
    char** pathv =(char*)calloc(MAX_PATHS,MAX_PATH_LEN); //array of paths obtained from the path environment variable

    char* commandLine = (char*)malloc(LINE_LEN);//holds the comamnd line inputed by the user

    struct command_t command ; //stores the tokenized command line

    bool flag = TRUE ;

    int pid, status ;


    parsePath(pathv); //get directory paths from path

    while(strcmp(commandLine,"exit") != 0 )
    {
        strcpy(commandLine," ");

        printPrompt();


        //Read the command line and parse it
        readCommand(commandLine);

        parseCommand(commandLine, &command);

        //get the full pathname for the file
        command.name = lookupPath(command.argv,pathv);



        if(command.name == NULL && strcmp(commandLine,"exit") != 0)
        {
            //report error
            printf("Command does not exist\n");
            continue ;
        }
        if(command.argv[command.argc] != NULL)
            command.argv[command.argc] = NULL ;



        //create child and execute the command
        if(pid = fork() == 0)
        {
            execv(command.name,command.argv);

        }

        //wait for the child to terminate
        wait(&status);


    }
    //shell termination
    exit(EXIT_SUCCESS) ;
}
