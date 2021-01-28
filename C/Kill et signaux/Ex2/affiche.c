#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void hdl_sig_usr1 (int n) {

    char y[11];
    int fd=open("/tmp/entier.txt", O_RDONLY); // ouvre le fichier
    n=read (fd, y, 11); // lis son contenu
    write (1, y, n); // l'affiche sur le terminal
}

int main(int argc, char *argv[]) {
    printf("mon ID est : %d \n", getpid());
    signal (SIGUSR2, hdl_sig_usr1); // récupère le signal SIGUSR2
    sleep (1200); 
}
