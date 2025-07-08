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
    booking->movieCount = 0;
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
        fprintf(fp, "%s,%s,%d,{", booking->user[i].username, booking->user[i].password, booking->user[i].booked_seat_count);
        for(int j = 0; j < booking->user[i].booked_seat_count; j++)
        {
            fprintf(fp, "%d,", booking->user[i].booked_seats[j]);
        }
        fprintf(fp, "}\n");
    }
    booking->movieCount = 0;
    fclose(fp);
}

void loadMovieFromFile(Booking *booking)
{
    FILE *fp;
    fp = fopen("movie.csv", "r");
    if(fp == NULL)
    {
        perror("Error ");
        return;
    }
    fscanf(fp, "#%d\n", &booking->movieCount);
    for(int i = 0; i < booking->movieCount; i++)
    {
        fscanf(fp, "%d,%[^,],%[^,],%f,%d,%d,{", &booking->movies[i].movieId, booking->movies[i].movieName, booking->movies[i].time, &booking->movies[i].price, &booking->movies[i].total_seats, &booking->movies[i].available_seats);
        for(int j = 0; j < booking->movies[i].total_seats; j++)
        {
            fscanf(fp, "%d,", &booking->movies[i].seat_no[j]);
        }
        
        fscanf(fp, "}\n");
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
        fscanf(fp, "%[^,],%[^,],%d,{", booking->user[i].username, booking->user[i].password, &booking->user[i].booked_seat_count);
        for(int j = 0; j < booking->user[i].booked_seat_count; j++)
        {
            fscanf(fp, "%d,", &booking->user[i].booked_seats[j]);
        }
        fscanf(fp, "}\n");
    }
    fclose(fp);
}
