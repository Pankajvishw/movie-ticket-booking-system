/***********************************************************************
 *  File Name   : login.h
 *  Description : Header file for login operations in the
 *                Movie Ticket Booking System. Declares functions for:
 *                - User login with credential validation and user menu.
 *                - Admin login with hardcoded credentials and admin menu.
 *
 *                Functions:
 *                - userLogin()  : Handles user authentication and menu.
 *                - adminLogin() : Handles admin authentication and menu.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

 #include "movies.h"

void userLogin(Booking *booking);
void adminLogin(Booking *booking);
