#include "functions.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

typedef struct{
    char username[50];
    char password[50];
    char email[50];
} User;

int main(){
    // Variable Declaration
    User user, checkUser;
    int logAction, len = 0;
    char ch;

    // FILE OPEN
    FILE *fptr = fopen("Users.txt", "a+");

    // FILE length for LOOP
    do{
        ch = fgetc(fptr);
        if(ch == '\n'){
            len++;
        }
    }while(ch != EOF);

    rewind(fptr);

    // Choose Either Register OR Login
    printf("Type the action you want to perform: \n");

    printf("1. Register\n");
    printf("2. Login\n");
    scanf("%d", &logAction);

    // Register & Login
    if(logAction == 1){

        printf("Username: ");
        scanf("%s", user.username);
        fprintf(fptr, "Username: %s ", user.username);

        printf("Email: ");
        scanf("%s", user.email);
        fprintf(fptr, "Email: %s ", user.email);

        printf("Password: ");
        scanf("%s", user.password);
        fprintf(fptr, "Password: %s\n", user.password);

    }else if(logAction == 2){

        printf("Username: ");
        scanf("%s", user.username);

        printf("Password: ");
        scanf("%s", user.password);

        int found = 0;
        for (int i = 0; i < len; i++) {
            fscanf(fptr, "Username: %s Email: %s Password: %s\n", checkUser.username, checkUser.email, checkUser.password);
            if (strcmp(user.username, checkUser.username) == 0 && strcmp(user.password, checkUser.password) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Login successful!\n");
        } else {
            printf("Login failed!\n");
        }

    }

    return 0;
}
