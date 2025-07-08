/***********************************************************************
 *  File Name   : bokking.h
 *  Description : Header file for booking and managing tickets in the
 *                Movie Ticket Booking System.
 *
 *                Functions:
 *                - bookTicket()        : Book seats for a user.
 *                - viewBookedTicket()  : Display user's booked tickets.
 *                - removeUserSeat()    : Remove a specific seat from user booking.
 *                - cancelTicket()      : Cancel one or more booked tickets.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

 #include "movies.h"

void bookTicket(Booking *booking, int userIndex);
int viewBookedTicket(Booking *booking, int userIndex);
void removeUserSeat(Booking *booking, int userIndex, int seatIndex);
void cancelTicket(Booking *booking, int userIndex);