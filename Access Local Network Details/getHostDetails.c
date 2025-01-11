#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char host[BUFSIZ];
    int r;

    // Check this machine
    r = gethostname(host, BUFSIZ);
    if (r == -1)
    {
        fprintf(stderr, "Unable to obtain the host name\n");
        exit(1);
    }

    printf("Host name: %s\n", host);
}