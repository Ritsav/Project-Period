#include <stdio.h>

#ifndef C_PROGRAMMING_EMOTION_LOG_H
#define C_PROGRAMMING_EMOTION_LOG_H


void EmotionLog()
{
    int a[50];
    char b[100];


    printf("\nOn the scale from 1-5, how bad were your mood swings throughout the day?\n");
    printf("\nSelect your answer: ");
    scanf("%d",&a[0]);

    printf("\nDescribe the mood you experienced the most by selecting the given options,\n");
    printf("1.Happy\n2.Sad\n3.Energetic\n4.Tired\n");
    printf("\nSelect your answer: ");
    scanf("%d",&a[1]);

    printf("\nHow many hours did you sleep last night?\n");
    printf("1.Less than 4 hours\n2.4-5 hrs\n3.6-7 hrs\n4.8-9 hrs\n5.More than 10 hours\n");
    printf("\nSelect your answer: ");
    scanf("%d",&a[2]);

    printf("\nHow would you rate the quality of your sleep?\n");
    printf("1.Poor\n2.Fair\n3.Good\n4.Excellent\n");
    printf("\nSelect your answer: ");
    scanf(" %c",&a[3]);

    printf("\nDid you experience any physical symptoms today that may have affected your emotions?\n");
    printf("1.Yes\n2.No\n");
    printf("\nSelect your answer: ");
    scanf(" %d",&a[4]);

    switch(a[4])
    {
        case 1:
            printf("\nIf yes, select the symptoms you experienced:\n");
            printf("1.Cramps\n2.Headache\n3.Fatigue\n4.Nausea\n5.Backache\n");
            printf("\nSelect your answer: ");
            scanf("%d",&a[5]);
            break;

        default:
            break;
    }

//    journal:
//    printf("\nDo you want to journal right now?\n");
//    printf("1.Yes\n2.No\n");
//    printf("\nSelect your answer: ");
//    scanf("%d",&a[6]);
//
//    switch(a[6])
//    {
//        case 1:
//            printf("\nDo you want guided or unguided journaling?\n");
//            printf("1.Guided\n2.Unguided\n");
//            printf("\nSelect your answer: ");
//            scanf("%d",&a[7]);
//
//            if(a[7]==1)
//            {
//            }
//            break;
//
//        case 2:
//            break;
//
//        default:
//            printf("Invalid case.\n");
//            goto journal;
//    }
}

#endif //C_PROGRAMMING_EMOTION_LOG_H