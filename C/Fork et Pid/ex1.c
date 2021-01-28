#include <fcntl.h>
#include <stdio.h>

int main ()
{
    int p1=fork() ; // On sépare les id
    if (p1<0) // si le processus est inférieur à 0
    {
        printf("erreur processus non crée"); 
        return 1 ;}
        if(p1>0) { // si le processus est supérieur à 0
            int p2= fork() ; 
            if (p2<0)
            { printf("erreur processus non crée") ;
            return 2 ;}
        if(p2>0)
        {
        printf("je suis le processus père mon id est %d et mon père est %d , la valeur de primitive %d",getpid(), getppid(), p2) ;
        }
        else
        {
            printf("je suis le processus fils 2 mon id est %d et mon père est %d , la valeur de primitive %d",getpid(), getppid(), p2) ;
        }
    }
    else
    {
    printf("je suis le processus fils 1 mon id est %d et mon père est %d , la valeur de primitive %d",getpid(), getppid(), p1) ;
    }
}
