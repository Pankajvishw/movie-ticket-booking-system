/***********************************************************************
 *  File Name   : file.c
 *  Description : Handles persistent storage using file I/O.
 *                Saves and loads movie and user data in CSV format.
 *
 *                Files Used:
 *                - movie.csv
 *                - user.csv
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

 #include <stdio.h>
#include "file.h"

void saveMovieToFile(Booking *booking)
{
    FILE *fp;
    fp = fopen("movie.csv", "w");
    if(fp == NULL)
    {
        perror("Error ");
        return;
    }
    fprintf(fp, "#%d\n", booking->movieCount);
    for(int i = 0; i < booking->movieCount; i++)
    {
        fprintf(fp, "%d,%s,%s,%.2f,%d,%d,{", booking->movies[i].movieId, booking->movies[i].movieName, booking->movies[i].time, booking->movies[i].price, booking->movies[i].total_seats, booking->movies[i].available_seats);
        for(int j = 0; j < booking->movies[i].total_seats; j++)
        {
            fprintf(fp, "%d,", booking->movies[i].seat_no[j]);
        }
        
        fprintf(fp, "}\n");
    }
    // booking->movieCount = 0;
    fclose(fp);
}

void saveUserToFile(Booking *booking)
{
    FILE *fp;
    fp = fopen("user.csv", "w");
    if(fp == NULL)
    {
        perror("Error ");
        return;
    }
    fprintf(fp, "#%d\n", booking->userCount);
    for(int i = 0; i < booking->userCount; i++)
    {
        fprintf(fp, "%s,%s,%d,%f,{", booking->user[i].username, booking->user[i].password, booking->user[i].booked_seat_count, booking->user[i].bill);
        for(int j = 0; j < booking->user[i].booked_seat_count; j++)
        {
            fprintf(fp, "%d,", booking->user[i].booked_seats[j]);
        }
        fprintf(fp, "}\n");
    }
    // booking->userCount = 0;
    fclose(fp);
}

void loadMovieFromFile(Booking *booking)
{
    FILE *fp = fopen("movie.csv", "r");
    if(fp == NULL) {
        perror("Error opening movie.csv");
        return;
    }

    fscanf(fp, "#%d\n", &booking->movieCount);
    for(int i = 0; i < booking->movieCount; i++) {
        int matched = fscanf(fp, "%d,%[^,],%[^,],%f,%d,%d,{", 
            &booking->movies[i].movieId, 
            booking->movies[i].movieName, 
            booking->movies[i].time, 
            &booking->movies[i].price, 
            &booking->movies[i].total_seats, 
            &booking->movies[i].available_seats);

        if (matched != 6) {
            printf("❌ Error reading movie at index %d. Only matched %d fields.\n", i, matched);
            continue;
        }

        for (int j = 0; j < booking->movies[i].total_seats; j++) {
            fscanf(fp, "%d,", &booking->movies[i].seat_no[j]);
        }
        fscanf(fp,"}");
        // Debug print
        // printf("✅ Movie %d Loaded: ID=%d, Name=%s, Time=%s\n", i+1, booking->movies[i].movieId, booking->movies[i].movieName, booking->movies[i].time);
    }

    fclose(fp);
}


void loadUserFromFile(Booking *booking)
{
    FILE *fp;
    fp = fopen("user.csv", "r");
    if(fp == NULL)
    {
        perror("Error ");
        return;
    }
    fscanf(fp, "#%d\n", &booking->userCount);
    for(int i = 0; i < booking->userCount; i++)
    {
        fscanf(fp, "%[^,],%[^,],%d,%f,{", booking->user[i].username, booking->user[i].password, &booking->user[i].booked_seat_count, &booking->user[i].bill);
        for(int j = 0; j < booking->user[i].booked_seat_count; j++)
        {
            fscanf(fp, "%d,", &booking->user[i].booked_seats[j]);
        }
        fscanf(fp, "}\n");

        // Debug print
        // printf("✅ User %d Loaded: ID=%d, Name=%s, Bill=%.2f\n", i+1, booking->user[i].booked_seat_count, booking->user[i].username, booking->user[i].bill);
    }
    fclose(fp);
}
