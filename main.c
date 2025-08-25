#include <signal.h>
#include <stdio.h>
 
volatile sig_atomic_t gSignalStatus = 0;
 
void signal_handler(int status)
{
    gSignalStatus = status;
}
 
int main(void)
{
    /* Install a signal handler. */
    signal(SIGINT, signal_handler);

    while (1) {
        printf("SignalValue:    %d\n", gSignalStatus);
        printf("Sending signal: %d\n", SIGINT);
        raise(SIGINT);
        printf("SignalValue:    %d\n", gSignalStatus);
    }
}
