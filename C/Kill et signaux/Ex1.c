#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void hdl_sig_kill_int (int n) {
	sleep (10); 
}

int main(int argc, char *argv[]) {

	int x1 = fork(); // Créé un fils

	if (x1 < 0) return 1; // Si le pid est inférieur à -1 (erreur)

	if (x1 != 0) {
	// Ici, c’est le père. 
		printf("je suis le père, mon ID est : %d, l’ID de mon pere est : %d", getpid(), getppid()); 
		sleep (5);
		kill (x1, SIGINT); // envoie le signal SIGINT au fils
		sleep (20);
		kill (x1, SIGUSR1); // envoie le signal SIGUSR1 au fils
	}
	else {
		//ici, c’est le fils. 
		printf("je suis le fils, mon ID est : %d, l’ID de mon pere est : %d", getpid(), getppid());
		signal (SIGINT, hdl_sig_kill_int); // Déroute le signal SIGINT
		signal (SIGUSR1, hdl_sig_kill_int); // Déroute le signal SIGUSR1
		int n=0;
		if(n<=10) {
			n++;
			printf ("je suis vivant"); 
			sleep (5); // s'endort
		}
	}
}
