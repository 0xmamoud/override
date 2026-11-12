/*
 * level06 keygen
 * Replays the serial computation of auth() for a chosen login.
 * Build : gcc -o keygen keygen.c
 * Usage : ./keygen <login>        (login must be at least 6 characters)
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *login;
    unsigned int check;
    int len;
    int i;

    if (argc != 2)
    {
        printf("usage: %s <login>\n", argv[0]);
        return 1;
    }
    login = argv[1];
    len = strlen(login);

    check = ((signed char)login[3] ^ 4919) + 6221293;
    for (i = 0; i < len; i++)
        check += ((signed char)login[i] ^ check) % 1337;

    printf("login : %s\nserial: %u\n", login, check);
    return 0;
}
