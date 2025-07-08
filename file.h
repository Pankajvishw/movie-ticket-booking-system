/***********************************************************************
 *  File Name   : file.h
 *  Description : Header file for file handling operations in the
 *                Movie Ticket Booking System. Declares functions used
 *                to save and load movie and user data to/from CSV files.
 *
 *                Functions:
 *                - saveMovieToFile() : Writes movie data to "movie.csv".
 *                - saveUserToFile()  : Writes user data to "user.csv".
 *                - loadMovieFromFile(): Loads movie data from "movie.csv".
 *                - loadUserFromFile() : Loads user data from "user.csv".
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

#ifndef FILE_H
#define FILE_H

#include "movies.h"

void saveMovieToFile(Booking *booking);
void saveUserToFile(Booking *booking);
void loadMovieFromFile(Booking *booking);
void loadUserFromFile(Booking *booking);

#endif
