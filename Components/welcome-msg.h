#include <stdio.h>
#include <string.h>

#ifndef C_PROGRAMMING_WELCOME_MSG_H
#define C_PROGRAMMING_WELCOME_MSG_H

void printBorder(int length) {
    for (int i = 0; i < length; i++) {
        printf("*");
    }
    printf("\n");
}

void printMessageWithBorder(char message[]) {
    int length = strlen(message) + 6; // Length of the message plus some padding and border
    printBorder(length);
    printf("** %s ***\n", message);
    printBorder(length);
}

void WelcomeMsg() {
    char message[] = "WELCOME TO PROJECT PERIOD";
    printMessageWithBorder(message);
}

#endif //C_PROGRAMMING_WELCOME_MSG_H