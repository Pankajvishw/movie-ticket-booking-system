/***********************************************************************
 *  File Name   : search.h
 *  Description : This header file declares functions responsible for 
 *                displaying available movies, seats, and booked tickets
 *                in a formatted manner for the Movie Ticket Booking System.
 *
 *                Functions:
 *                - line()                  : Prints a horizontal divider.
 *                - viewSeats()             : Displays available/booked seats for a movie.
 *                - printMovieHead()        : Displays header for movie list.
 *                - viewShows()             : Lists all available movies.
 *                - printBookedTicketHead() : Displays header for booked ticket list.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

#include "movies.h"

void line(void);
void viewSeats(Booking * booking,int movieId);
void printMovieHead();
void viewShows(Booking *booking);
void printBookedTicketHead();
