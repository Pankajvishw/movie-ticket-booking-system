/***********************************************************************
 *  File Name   : movies.h
 *  Description : This header file defines core data structures and 
 *                function declarations for the Movie Ticket Booking System.
 *
 *                Structures:
 *                - Movies: Holds movie details including seat information.
 *                - User  : Holds user credentials and their bookings.
 *                - Booking: Manages all users and movies.
 *
 *                Constants:
 *                - MAX_MOVIES        : Maximum movies in system.
 *                - MAX_BOOKED_SEATS  : Maximum bookings per user.
 *                - MAX_USERS         : Maximum number of users.
 *                - MAX_SEATS         : Maximum seats per movie.
 *
 *                Functions:
 *                - initialize()
 *                - addMovies(), editMovies(), deleteMovies()
 *                - bookTicket(), cancelTicket(), viewBookedTicket()
 *                - viewBookedTicketAdmin()
 *                - removeUserSeat(), searchMovie()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

#ifndef MOVIES_H
#define MOVIES_H
#include <stdio.h>

#define MAX_MOVIES 20
#define MAX_BOOKED_SEATS 40
#define MAX_USERS 10
#define MAX_SEATS 40

typedef struct Movies
{
    int movieId;
    char movieName[50];
    char time[15];
    float price;
    int total_seats;
    int available_seats;
    int seat_no[40];
} Movies;

typedef struct User
{
    char username[30];
    char password[20];
    int booked_seats[40];
    int booked_seat_count;
    float bill;
} User;

typedef struct
{
    Movies movies[MAX_MOVIES];
    User user[10];
    int userCount;
    int movieCount;
} Booking;


void initialize(Booking *booking);
void addMovies(Booking * booking);
void editMovies(Booking *booking);
void deleteMovies(Booking *booking);
void viewBookedTicketAdmin(Booking *booking);


void bookTicket(Booking *booking, int userIndex);
int viewBookedTicket(Booking *booking, int userIndex);
void removeUserSeat(Booking *booking, int userIndex, int seatIndex);
void cancelTicket(Booking *booking, int userIndex);
void searchMovie(Booking *booking);

#endif

