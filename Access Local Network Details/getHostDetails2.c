#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
    char host[BUFSIZ];
    int r;
    struct hostent *hostdata;
    char **addresses;

    // Check this machine
    r = gethostname(host, BUFSIZ);
    if (r == -1)
    {
        fprintf(stderr, "Unable to obtain the host name\n");
        exit(1);
    }

    // get the host name
    printf("Host name: %s\n", host);

    // get info about the host
    hostdata = gethostbyname(host);
    if (hostdata == NULL)
    {
        fprintf(stderr, "Unable to obtain the host data\n");
        exit(1);
    }

    // get the IP addresses
    printf("Addresses:\n");
    addresses = hostdata->h_addr_list;
    while (*addresses)
    {
        printf("  %s\n", inet_ntoa(*(struct in_addr *)*addresses));
        addresses++;
    }
    return 0;
}