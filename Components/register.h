#include "stdlib.h"
#include "stdio.h"

#ifndef C_PROGRAMMING_REGISTER_LOGIN_H
#define C_PROGRAMMING_REGISTER_LOGIN_H

void Register(FILE *file, int len, char *username, char *email, char *password){

    printf("Username: ");
    scanf("%s", username);

    printf("Email: ");
    scanf("%s", email);

    printf("Password: ");
    scanf("%s", password);

    fprintf(file, "Id: %d ", len + 1);
    fprintf(file, "Username: %s ", username);
    fprintf(file, "Email: %s ", email);
    fprintf(file, "Password: %s\n", password);

    system("cls");

    rewind(file);
}

#endif //C_PROGRAMMING_REGISTER_LOGIN_H