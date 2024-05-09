
#include "stdio.h"
#include "conio.h"
#include "string.h"

typedef struct{
    int id;
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
    FILE *file1 = fopen("Users.txt", "a+");

    // FILE status check
    if (file1 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // FILE '\n' length for LOOP
    do{
        ch = fgetc(file1);
        if(ch == '\n'){
            len++;
        }
    }while(ch != EOF);

    rewind(file1);

    // Choose Either Register OR Login
    printf("Type the action you want to perform: \n");

    printf("1. Register\n");
    printf("2. Login\n");
    scanf("%d", &logAction);

    // Register & Login
    if(logAction == 1){

        fprintf(file1, "Id: %d ", len + 1);

        printf("Username: ");
        scanf("%s", user.username);
        fprintf(file1, "Username: %s ", user.username);

        printf("Email: ");
        scanf("%s", user.email);
        fprintf(file1, "Email: %s ", user.email);

        printf("Password: ");
        scanf("%s", user.password);
        fprintf(file1, "Password: %s\n", user.password);

    }else if(logAction == 2){

        printf("Username: ");
        scanf("%s", user.username);

        printf("Password: ");
        scanf("%s", user.password);

        int found = 0;
        for (int i = 0; i < len; i++) {
            fscanf(file1, "Id: %d Username: %s Email: %s Password: %s\n", &checkUser.id, checkUser.username, checkUser.email, checkUser.password);

            if (strcmp(user.username, checkUser.username) == 0 && strcmp(user.password, checkUser.password) == 0) {
                found = 1;
                break;
            }
        }

        if(found) {
            // Dynamically create the filename
            char filename[50];
            snprintf(filename, sizeof(filename), "User%d.txt", checkUser.id);

            FILE *file2 = fopen(filename, "a+");
            if (file2 == NULL) {
                printf("Error opening file.\n");
                return 1;
            }

            fclose(file2);
        } else {
            printf("Login failed!\n");
        }

    }

    fclose(file1);
    return 0;
}