/***********************************************************************
 *  File Name   : editmovie.h
 *  Description : Header file for editing movie-related information in
 *                the Movie Ticket Booking System. Declares functions to:
 *                  - Change movie name
 *                  - Change movie ticket price
 *                  - Change movie show time
 *
 *  Functions:
 *                - changeMovieName()
 *                - changeMoviePrice()
 *                - changeMovieTime()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

 #include "movies.h"

void changeMovieName(Booking *booking,int movieId);
void changeMoviePrice(Booking *booking,int movieId);
void changeMovieTime(Booking *booking,int movieId);