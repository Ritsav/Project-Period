
#include "stdio.h"
#include "Components/register.h"
#include "string.h"
#include "stdlib.h"
#include "Components/tracking.h"
#include "Components/navigation.h"
#include "Components/welcome-msg.h"

typedef struct{
    int id;
    char username[50];
    char password[50];
    char email[50];
} User;

int main(){
    // Variable Declaration
    User user, checkUser;
    int logAction, len = 0, len1 = 0;
    char ch;
    int year, month, day;

    // FILE OPEN
    FILE *file1 = fopen("User Data/Users.txt", "a+");

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

    // Welcome Message
    WelcomeMsg();

    // Choose Either Register OR Login
    printf("\nType the action you want to perform: \n");

    printf("1. Register\n");
    printf("2. Login\n\n");
    printf("Enter your choice: ");
    scanf("%d", &logAction);
    system("cls");

    // Register & Login
    if(logAction == 1){

        Register(file1, len, user.username, user.email, user.password);
        goto login;

    }else if(logAction == 2){

        login:

        // FILE '\n' length for LOOP
        do{
            ch = fgetc(file1);
            if(ch == '\n'){
                len++;
            }
        }while(ch != EOF);
        rewind(file1);

        printf("\nEnter Login Details: \n\n");

        printf("Username: ");
        scanf("%s", user.username);

        printf("Password: ");
        scanf("%s", user.password);

        int found = 0;
        for (int i = 0; i < len; i++) {
            fscanf(file1, "Id: %d Username: %s Email: %s Password: %s\n",
                   &checkUser.id, checkUser.username, checkUser.email, checkUser.password);

            if (strcmp(user.username, checkUser.username) == 0 && strcmp(user.password, checkUser.password) == 0) {
                found = 1;
                break;
            }
        }
        rewind(file1);

        if(found) {
            // Dynamically create the filename
            char filename[50];
            snprintf(filename, sizeof(filename), "User Data/User%d.txt", checkUser.id);

            FILE *file2 = fopen(filename, "a+");
            if (file2 == NULL) {
                printf("Error opening file.\n");
                return 1;
            }

            // Test for new user or not
            do{
                ch = fgetc(file2);
                if(ch == '\n'){
                    len1++;
                }
            }while(ch != EOF);

            rewind(file2);

            // Tracking
            if(len1 >= 1){

                system("cls");

                printf("\nWelcome, %s!\n\n", checkUser.username);
                fscanf(file2, "Date: %d/%d/%d", &day, &month, &year);
                printf("Last period occurrence at: %d/%d/%d\n", day, month, year);
                rewind(file2);

            }else{

                system("cls");

                printf("\nWelcome, %s!\n\n", checkUser.username);
                printf("Use this format to enter the date: DD/MM/YEAR\n");
                printf("Enter the date of your last period occurrence: ");

                scanf("%d/%d/%d", &day, &month, &year);
                fprintf(file2, "Date: %d/%d/%d\n", day, month, year);
                rewind(file2);
            }

            Tracking(file2);

            // New cycle update + Emotion Log Routing
            Navigation(file2, checkUser.id);

            fclose(file2);
        } else {
            printf("Login failed!\n");
        }

    }

    fclose(file1);
    return 0;
}