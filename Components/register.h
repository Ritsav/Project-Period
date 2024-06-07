#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

#ifndef C_PROGRAMMING_REGISTER_LOGIN_H
#define C_PROGRAMMING_REGISTER_LOGIN_H

void getPassword(char *password, int maxLength) {
    int i = 0;
    char ch;

    while ((ch = _getch()) != '\r' && i < maxLength - 1) {  // '\r' is the Enter key
        if (ch == '\b') {  // Handle backspace
            if (i > 0) {
                i--;
                printf("\b \b");  // Move cursor back, print space to erase the *, and move cursor back again
            }
        } else {
            password[i++] = ch;
            printf("*");  // Print * for each character typed
        }
    }
    password[i] = '\0';  // Null-terminate the password string
    printf("\n");
}

void Register(FILE *file, int len, char *username, char *email, char *password) {

    printf("Username: ");
    scanf("%s", username);

    printf("Email: ");
    scanf("%s", email);

    printf("Password: ");
    getPassword(password, 100);  // Assuming the maximum password length is 100

    fprintf(file, "Id: %d ", len + 1);
    fprintf(file, "Username: %s ", username);
    fprintf(file, "Email: %s ", email);
    fprintf(file, "Password: %s\n", password);

    system("cls");

    rewind(file);
}

#endif //C_PROGRAMMING_REGISTER_LOGIN_H
