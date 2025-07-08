/***********************************************************************
 *  File Name   : editmovie.c
 *  Description : Defines admin-side functions for editing movie
 *                details such as name, price, and time.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

 #include "editmovie.h"
#include <string.h>
#include "validate.h"

void changeMovieName(Booking *booking, int movieId) {
    char name[50];
    int valid = 0;

    do 
    {
        printf("\n🎬 Enter New Movie Name: ");
        scanf(" %[^\n]", name);
        if (!validMovieName(name)) 
        {
            printf("❌ Invalid movie name. Only alphanumeric characters allowed, max 50 characters.\n");
        } 
        else 
        {
            valid = 1;
        }
    } while (!valid);

    strcpy(booking->movies[movieId].movieName, name);
}

void changeMoviePrice(Booking *booking, int movieId) {
    float price;
    int invalid = 0;

    do {
        printf("\n💰 Enter Movie Ticket Price: ");
        scanf(" %f", &price);
        invalid = !valid_price(price);
    } while (invalid);

    booking->movies[movieId].price = price;
}

void changeMovieTime(Booking *booking, int movieId) {
    char time[20];
    int invalid = 0;

    do {
        printf("\n🕒 Enter Movie Time (HH:MM): ");
        scanf(" %[^\n]", time);
        invalid = (!valid_time(time));
    } while (invalid);

    strcpy(booking->movies[movieId].time, time);
}
