#include <stdio.h>

int main()
{
    int s,c,p,r,a,b;
    char h,q;


    printf("On the scale from 1-5, how bad were your mood swings throughout the day?\n");
    printf("1\n2\n3\n4\n5\n");
    printf("Select your answer:");
    scanf("%d",&s);

    printf("\nDescribe the mood you experienced the most by selecting the given options,\n");
    printf("1.Happy\n2.Sad\n3.Energetic\n4.Tired\n");
    printf("Select your answer:");
    scanf("%d",&c);

    printf("\nHow many hours did you sleep last night?\n");
    printf("a.Less than 4 hours\nb.4-5 hrs\nc.6-7 hrs\nd.8-9 hrs\ne.More than 10 hours\n");
    printf("Select your answer:");
    scanf(" %c",&h);

    printf("\nHow would you rate the quality of your sleep?\n");
    printf("a.Poor\nb.Fair\nc.Good\nd.Excellent\n");
    printf("Select you answer:");
    scanf(" %c",&q);

    printf("\nDid you experience any physical symptoms today that may have affected your emotions?\n");
    printf("1.Yes\n2.No\n");
    printf("Select your answer:");
    scanf(" %d",&p);

    switch(p)
    {
    case 1:
        printf("If yes, select the symptoms you experienced:\n");
        printf("a.Cramps\nb.Headache\nc.Fatigue\nd.Nausea\ne.Backache\n");
        printf("Select your answer:");
        scanf(" %d",&r);
        break;

        case 2:
        break;
        
    default:
        printf("Invalid case");
        break;
    }

    printf("Do you want to journal right now?\n");
    printf("1.Yes\n2.No\n");
    printf("Select your answer:");
    scanf("%d",&a);

    switch(a)
    {
    case 1:
        printf("Do you want guided or unguided journaling?");
        printf("1.Guided\n2.Unguided\n");
        printf("Select your answer:");
        scanf("%d",&b);

       
    }
    return 0;
}
