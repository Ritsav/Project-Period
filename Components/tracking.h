#include "time.h"
#include "stdlib.h"
#include "stdio.h"

#ifndef C_PROGRAMMING_TRACKING_H
#define C_PROGRAMMING_TRACKING_H

int numOfDays(int cur_month){
    int daysInMonth;

    if (cur_month == 1){
        daysInMonth = 31; // 31
    } else if (cur_month == 2) {
        daysInMonth = 31; // 31
    } else if (cur_month == 3) {
        daysInMonth = 28; // 28
    } else if (cur_month == 4) {
        daysInMonth = 31; // 31
    } else if (cur_month == 5) {
        daysInMonth = 30; // 30
    } else if (cur_month == 6) {
        daysInMonth = 31; // 31
    } else if (cur_month == 7) {
        daysInMonth = 30; // 30
    } else if (cur_month == 8) {
        daysInMonth = 31; // 31
    } else if (cur_month == 9) {
        daysInMonth = 31; // 31
    } else if (cur_month == 10) {
        daysInMonth = 30; // 30
    } else if (cur_month == 11) {
        daysInMonth = 31; // 31
    } else{
        daysInMonth = 30; // 30
    }

    return daysInMonth;
}

void displayTrack(int diff_day){
    int irregularDays;

    if(diff_day <= 28){
        irregularDays = 28 - diff_day;
        printf("\nExpected number of days till next cycle: %d\n\n", irregularDays);
    }else {
        irregularDays = diff_day - 28;
        printf("\nPeriod hasn't happened %d days since expected date.\n\n", irregularDays);
    }
}

void Tracking(FILE *file){
    int year, month, day, daysInMonth; //Declaration
    fscanf(file, "Date: %d/%d/%d", &day, &month, &year); //Reading date from file

    rewind(file);

    // Get the current time
    time_t current_time = time(NULL);

    // Convert to local time
    struct tm *local_time = localtime(&current_time);

    int cur_day = local_time->tm_mday;
    int cur_month = local_time->tm_mon + 1;
    int cur_year = local_time->tm_year + 1900; // tm_year is years since 1900

    int diff_day = cur_day - day;
    int diff_month = cur_month - month;
    int diff_year = year - cur_year;

//    printf("%d/%d/%d\n", day, month, year);
//
//    printf("%d/%d/%d\n", cur_day, cur_month, cur_year);
//
//    printf("%d/%d/%d\n", diff_day, diff_month, diff_year);

    // Logic for number of days in a month.
    daysInMonth = numOfDays(cur_month);

    // Logic Formation Part:
    // Last Period: 5/8/2024
    // Case 1: Current time: 10/9/2024
    // Case 2: Current time: 20/8/2024
    // Case 3 for year change: 1/1/2025, Last period: 10/12/2024
    // if ( diff_month = 1 )
    // 31 - 5 = 26 + 10 = 36 days ???

    int pastMonthDays;

    if(diff_year == 0){
        if (diff_month == 0) {
            diff_day = cur_day - day;
        } else if (diff_month == 1) {
            diff_day = (daysInMonth - day) + cur_day; // Only considering user uses the app regularly
        } else if(diff_month == 2) {
            pastMonthDays = numOfDays(cur_month - 1);
            diff_day = (daysInMonth - day) + cur_day + pastMonthDays;
        }
    }else if(diff_year == 1){
        diff_day = (daysInMonth - day) + cur_day; // 31 - 10 = 21 + 1 = 22
    }

    displayTrack(diff_day);
}

// User1 : 3/5/2024
// User2 : 1/6/2024
// User3 : 1/1/2025
// User4 : 4/4/2024

#endif //C_PROGRAMMING_TRACKING_H