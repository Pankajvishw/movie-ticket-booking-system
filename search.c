/***********************************************************************
 *  File Name   : search.c
 *  Description : Implements movie search functionality based on
 *                movie name or movie ID. Also includes seat view display.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

 #include "movies.h"
#include "search.h"

void line() {
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printMovieHead()
{
    line();
    printf("%-10s%-50s%-20s%20s%40s\n", "S.No", "Name", "Time", "Price", "Available Seats");
    line();
}

void printBookedTicketHead()
{
    line();
    printf("%-10s%-50s%-20s%-40s\n", "S.No", "Movie Name", "Time", "Seat No.");
    line();
}

void viewShows(Booking *booking)
{
    printMovieHead();
    for(int i = 0; i < booking->movieCount; i++)
    {
        printf("%-10d%-50s%-20s%20g%40d\n", booking->movies[i].movieId, booking->movies[i].movieName, booking->movies[i].time, booking->movies[i].price, booking->movies[i].available_seats);
    }
    line();
}

void viewSeats(Booking *booking, int movieId) {
    int count = 0;
    line();
    for (int i = 0; i < booking->movies[movieId].total_seats; i++) {
        if (booking->movies[movieId].seat_no[i] == -1) {
            printf("%-15s", "Booked");
        } else {
            printf("%-15d", booking->movies[movieId].seat_no[i] % 100);
        }
        count++;
        if (count % 10 == 0) {
            printf("\n");
        }
    }
    line();
}

