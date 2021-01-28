#include <fcntl.h>
#include <stdio.h>


int main()
{
    char buff[11];
    int df =open(".s/test.data", O_RDONLY); // On ouvre le fichier test.data
    int p1= fork() ; // on sépare les processus
    lseek(df, 30, SEEK_SET); // On met la position au 30eme caractere
    int cpt= read( df, buff, 10); // on lit le fichier
    printf("PID: %d, fork: %d \n", getpid(), getppid(), p1) ;
    write(1, buff, 10);
}