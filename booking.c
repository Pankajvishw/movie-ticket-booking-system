/***********************************************************************
 *  File Name   : bokking.c
 *  Description : This file implements functions for ticket booking,
 *                viewing booked tickets, and cancelling booked seats
 *                in the Movie Ticket Booking System.
 *
 *                Functions:
 *                - bookTicket()        : Allows a user to book seats for a movie.
 *                - viewBookedTicket()  : Displays tickets currently booked by a user.
 *                - removeUserSeat()    : Removes a seat from the user's booking list.
 *                - cancelTicket()      : Cancels a selected booked seat for the user.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : https://github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 *
 ***********************************************************************/

 #include "booking.h"
#include "validate.h"
#include "search.h"

void bookTicket(Booking *booking, int userIndex)
{
    int movieId, seatNo;
    printf("✅ User created successfully! %d %d\n",userIndex, booking->userCount);
    do
    {
        printf("\n%40s==================== Available Movies ====================\n", " ");
        viewShows(booking);
        printf("\n(Type '0' to go back) Enter the Movie ID to book : ");
        scanf(" %d", &movieId);
        if( movieId == 0)
        {
            printf("\nGoing back to previous Menu...\n");
            break;
        }
        movieId -= 1;
        if(movieId >= 0 && movieId < booking->movieCount)
        {
            do
            {
                printf("\n%40s==================== Available Seats ====================\n", " ");
                viewSeats(booking, movieId);
                if(booking->user[userIndex].booked_seat_count > MAX_BOOKED_SEATS)
                {
                    printf("\nMax Booking Limit Reached, Going Back..!\n");
                    return ;
                }
                printf("\n(Type '0' to go back) Enter the seat No. : ");
                scanf(" %d", &seatNo);
                if( seatNo == 0)
                {
                    printf("\nGoing back to previous Menu...\n");
                    break;
                }
                
                seatNo = (movieId + 1) * 100 + seatNo;
                if(validSeatNo(booking, movieId, seatNo))
                {
                    int seatIndex = -1;
                    for (int i = 0; i < booking->movies[movieId].total_seats; i++)
                    {
                        if (booking->movies[movieId].seat_no[i] == seatNo) {
                            seatIndex = i;
                            break;
                        }
                    }

                    if (seatIndex != -1 && booking->movies[movieId].seat_no[seatIndex] != -1)
                    {
                        printf("Seat No. %d is booked.\n", seatNo % 100);
                        booking->movies[movieId].seat_no[seatIndex] = -1;
                        booking->user[userIndex].booked_seats[booking->user[userIndex].booked_seat_count] = seatNo;
                        booking->movies[movieId].available_seats--;
                        booking->user[userIndex].booked_seat_count++;
                    }
                    else
                    {
                        printf("\n🚫 Seat already booked.\n");
                    }
                }
                else
                {
                    printf("\n🚫 Invalid Seat No.\n");
                }
            } while(1);
        }
        else
        {
            printf("\n🚫 Invalid Movie ID.\n");
        }
    } while(1);
}

int movieIdArr[MAX_MOVIES];
int viewBookedTicket(Booking *booking, int userIndex)
{
    int k = 0;
    if (booking->user[userIndex].booked_seat_count == 0)
    {
        printf("\nNo tickets booked yet.\n");
        return 0;
    }
    int movieindex[booking->movieCount], ticketCount = 0, count = 1, totalseats;;
    for(int i = 0; i < booking->movieCount; i++)
    {
        movieindex[i] = -1;
    }
    for(int i = 0; i < booking->user[userIndex].booked_seat_count; i++)
    {
        movieindex[(booking->user[userIndex].booked_seats[i] / 100) - 1] = 1;
    }
    printf("\n%40s==================== Booked Seats ====================\n", " ");
    printBookedTicketHead();
    for(int i = 0; i < booking->movieCount; i++)
    { 
        if(movieindex[i] != -1)
        {
            printf("%-10d%-50s%-20s", count, booking->movies[i].movieName, booking->movies[i].time);
            
            movieIdArr[k++] = i;
            for(int k = 0 ; k < booking->user[userIndex].booked_seat_count; k++)
            {
                int movieId = booking->user[userIndex].booked_seats[k] / 100;
                if (movieId - 1 == i)
                {
                    printf("%d, ", booking->user[userIndex].booked_seats[k] % 100);
                }
            }
            printf("\n");
            count++;
        }
    }
    line();
    return count;
}

void removeUserSeat(Booking *booking, int userIndex, int seatIndex)
{
    for(int i = seatIndex + 1; i < booking->user[userIndex].booked_seat_count; i++)
    {
        booking->user[userIndex].booked_seats[i - 1] = booking->user[userIndex].booked_seats[i];
    }
    booking->user[userIndex].booked_seat_count--;
}

void cancelTicket(Booking *booking, int userIndex)
{
    do
    {
        int count = booking->user[userIndex].booked_seat_count;
        if(count)
        {
            viewBookedTicket(booking, userIndex);
            int movieId = -1, flag = 0;
            printf("Type the movie index : ");
            scanf("%d", &movieId);

            if( movieId == 0)
            {
                printf("\nGoing back to previous Menu...\n");
                break;
            }
            if( movieId < 1 || movieId > count )
            {
                printf("Invalid index : ");
                continue;
            }
            else
            {
                int seatNo, seatIndex = 0, flag = 0, i, j;
                scanf("%d", &seatNo);
                seatNo = (movieIdArr[movieId - 1] + 1) * 100 + seatNo;
                for(int i = 0; i < booking->user[userIndex].booked_seat_count; i++)
                {
                    if(seatNo == booking->user[userIndex].booked_seats[i])
                    {
                        flag = 1;
                        seatIndex = i;
                        break;
                    }
                }
                if(flag)
                {
                    booking->movies[seatNo / 100 - 1].seat_no[seatNo % 100 - 1] = seatNo;
                    booking->movies[seatNo / 100 - 1].available_seats++;
                    
                    removeUserSeat(booking, userIndex, seatIndex);
                    printf("Seat No : %d cancelled !\n", seatNo % 100);             
                }
                else
                {
                    printf("ERROR : Invalid Seat No !\n");
                }
            }
        }
        else
        {
            printf("No Movie Availabe.. Going Back\n");
            return;
        }
    } while(1);
}