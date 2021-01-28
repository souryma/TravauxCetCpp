#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pipe_fils1[2];
    int pipe_fils2[2];
    char buf[11]="1";

    pipe (pipe_fils1);
    pipe (pipe_fils2);

    int x1 = fork();

    if (x1 < 0) return 1; // erreur de création du 1er fils

    if (x1 != 0) {
        // Ici, c’est le père.
        int x2 = fork();

        if (x2 < 0) return 2; // erreur de création du 2ème fils

        if (x2 != 0) {
            //ici, c’est toujours le père.
		int cpt;
            while (strcmp(buf, "0")==0) {
                cpt = read(0, buf, 10);
                buf[cpt]='\0';
                if ((buf[cpt-1])-48 % 2 == 0) write (pipe_fils1[1], buf, cpt); // nombre lu pair
                else write (pipe_fils2[1], buf, cpt); // nombre lu impair
            }
            sleep(1);
            write (pipe_fils2[1], buf, cpt); // nombre lu est 0
            write (pipe_fils1[1], buf, cpt); // nombre lu est 0

            close(pipe_fils1[0]);
            close(pipe_fils2[0]);
            close(pipe_fils1[1]);
            close(pipe_fils2[1]);
            int status1, status2;
            int pid1=wait(&status1);
            int pid2=wait(&status2);
            printf("je suis le processus père mon id est %d et mon père est %d, mes fils %d et %d sont morts dans cet ordre et ils m'ont dit %d, %d ... je meurs à mon tour",getpid(), getppid(), pid1, pid2, WEXITSTATUS(status1), WEXITSTATUS(status2));
        }
        else {
            //ici, c’est toujours le fils 2.
            while (strcmp(buf, "0")==0) {
                int cpt = read(pipe_fils2, buf, 10);
                buf[cpt]='\0';
                printf ("j’ai lu le nombre %s\n", buf);
            }
            printf("je suis le fils 2, mon ID est : %d, l’ID de mon pere est : %d, je meurs", getpid(), getppid());
            return(0);
        }
    }
    else {
        //ici, c’est le fils 1.
        while (strcmp(buf, "0")==0) {
            int cpt = read(pipe_fils2, buf, 10);
            buf[cpt]='\0';
            printf ("j’ai lu le nombre %s\n", buf);
        }
        printf("je suis le fils 1, mon ID est : %d, l’ID de mon pere est : %d, je meurs", getpid(), getppid());
        return(0);
    }
}
