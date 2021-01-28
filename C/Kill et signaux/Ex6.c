#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void servir_verre(int iNum)
{
    printf ("Je suis %d et je sers le verre %d\n", getpid(), iNum);
}
void demander_verre(int iNum)
{
    printf ("Je suis %d et je demande le verre %d\n", getpid(), iNum);
}

int main(int argc, char *argv[])
{
    int pid, statut;
    char *p;

    pid = fork(); // Création du fils
    switch(pid)
    {
        case -1:
        {
            perror("Fork");
            exit(-1);
        }

        case 0 :
            //Fils
            demander_verre(1);
            sleep(4);
            kill(getppid(),SIGCONT); // Envoi du signal SIGCONT au père
            kill(getpid(),SIGSTOP); 
            demander_verre(2);
            sleep(4);
            kill(getppid(),SIGCONT); // Envoi du signal SIGCONT au père
            break;

        default :
            //Père
            // Met en pause le barman
            kill(getpid(),SIGSTOP);
            servir_verre(1);
            sleep(4);
            kill(pid,SIGCONT);
            kill(getpid(),SIGSTOP);
            servir_verre(2);
            wait(&statut);
    }
}