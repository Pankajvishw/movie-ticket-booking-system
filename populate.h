/***********************************************************************
 *  File Name   : populate.h
 *  Description : This header file declares functions to populate initial
 *                data into the Movie Ticket Booking System. It is useful
 *                for testing and initializing default values at startup.
 *
 *                Functions:
 *                - populateMovies()   : Loads dummy movie data.
 *                - populateUser()     : Loads dummy user data.
 *                - populateSeatNo()   : Initializes seat numbers for each movie.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

#include "movies.h"

void populateMovies(Booking *booking);
void populateUser(Booking *booking);
void populateSeatNo(Booking *booking);