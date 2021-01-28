#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    char x[11];
    int n = read(0, x, 10); // Lis le terminal
    x[n]='\n';
    int fd=open("/tmp/entier.txt", O_WRONLY | O_CREAT, 0644); // Ouvre le fichier entier.txt
    write (fd, x, n+1); // écris depuis le terminal
    kill (16912, SIGUSR2); // envoie un signal SIGUSR2 
}

