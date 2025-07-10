/***********************************************************************
 *  File Name   : validate.h
 *  Description : This header file declares validation and authentication
 *                related functions for the Movie Ticket Booking System.
 *                These functions ensure correctness of input data like
 *                usernames, passwords, movie names, seat numbers, etc.
 *
 *                Functions:
 *                - int cmp()
 *                - valid_price()
 *                - valid_time()
 *                - valid_total_seat()
 *                - validSeatNo()
 *                - validMovieName()
 *                - movieExists()
 *                - movieIdExists()
 *                - validUsername()
 *                - usernameExists()
 *                - validPassword()
 *                - matchPassword()
 *                - changeLogin()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

#include "movies.h"

int cmp(const void * a, const void * b);
int valid_price(float price);
int valid_time(char *time);
int valid_total_seat(int seats);
int validSeatNo(Booking * booking, int movieId, int seatNo);
int movieIdExists(Booking * booking, int movieName);
int validMovieName(char *movieName);
int movieExists(Booking * booking,char * movieName);
void changeLogin(Booking * booking, int userIndex);
int validUsername(char *username);
int usernameExists(Booking *booking,char *username);
int validPassword(char *password);
int matchPassword(Booking *booking, int userindex, char *password);