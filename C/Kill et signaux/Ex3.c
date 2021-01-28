#include <stdio.h>
#include <signal.h>

void hdl_sig_int_quit (int signum) {
    static int n=0;
    if (signum == SIGINT) { // Si il reçoit le signal SIGQINT
        n++;
        printf(" SIGINT reçu \n");
        signal (SIGINT, hdl_sig_int_quit); // Re appelle la fonction
    }
    if (signum == SIGQUIT) { // Si il reçoit le signal SIGQUIT
        printf(" j'ai reçu %d SIGINT à ce stade \n", n);
        signal (SIGQUIT, hdl_sig_int_quit); // Re appelle la fonction
    }
}

int main() {
    signal(SIGINT, &hdl_sig_int_quit); // un SIGINT est déclenché suite à un CTRL C au clavier
    signal(SIGQUIT, &hdl_sig_int_quit); // un SIGQUIT est déclenché suite à un CTRL \ au clavier
    while(1);

    return 0;
}
