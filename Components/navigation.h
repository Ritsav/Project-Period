#include "stdio.h"
#include "stdlib.h"
#include "emotion-log.h"

#ifndef C_PROGRAMMING_NAVIGATION_H
#define C_PROGRAMMING_NAVIGATION_H


void Navigation(FILE *file){
    int day, month, year;

    newPeriod:
    printf("Did a new period cycle occur?\n"); //Subject to change
    printf("1. Yes\n");
    printf("2. No\n");
    printf("--> ");
    int choice;
    scanf("%d", &choice);

    if(choice == 1){
        system("cls");
        printf("\nEnter the date of your last period occurrence: ");
        scanf("%d/%d/%d", &day, &month, &year);

        fprintf(file, "Date: %d/%d/%d\n", day, month, year);
        rewind(file);

        emotionLog1:
        printf("\nDo you want to log your emotions?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("--> ");
        scanf("%d", &choice);

        if(choice == 1){
            EmotionLog();
        }else if(choice == 2){
            printf("\nHave a great day!");
        }else{
            printf("\nEnter a valid choice.\n");
            goto emotionLog1;
        }

    }else if(choice == 2){

        emotionLog2:
        system("cls");
        printf("\nDo you want to log your emotions?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("--> ");
        scanf("%d", &choice);

        if(choice == 1){
            EmotionLog();
        }else if(choice == 2){
            printf("\nHave a great day!");
        }else{
            printf("\nEnter a valid choice.\n");
            goto emotionLog2;
        }

    }else{
        printf("\nEnter a valid choice.\n\n");
        goto newPeriod;
    }
}

#endif //C_PROGRAMMING_NAVIGATION_H