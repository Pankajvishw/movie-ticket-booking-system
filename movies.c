/***********************************************************************
 *  File Name   : movies.c
 *  Description : Contains the core functions for booking, viewing,
 *                canceling tickets, and managing movies (admin).
 *                Implements movie CRUD operations and user bookings.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "movies.h"
#include "populate.h"
#include "search.h"
#include "validate.h"
#include "editmovie.h"
#include "file.h"


void initialize(Booking *booking)
{
    // booking->movieCount = 0, booking->userCount = 0;;
	// populateMovies(booking);
    // populateUser(booking);
    loadMovieFromFile(booking);
    loadUserFromFile(booking);
    // populateSeatNo(booking);
}

void addMovies(Booking * booking)
{
    if(booking->movieCount == MAX_MOVIES)
    {
        printf("❌ Movie list full! Cannot add more movies.\n");
        return;
    }	

    char name[50], time[20];
    float price;
    int total_seats;
    
    int valid = 0;
    int invalid = 0;

    do
    {
        printf("🎬 Enter Movie Name: ");
        scanf(" %[^\n]", name);

        if (!validMovieName(name))
        {
            printf("❌ Invalid movie name. Only letters and digits allowed (max 50 characters).\n");
            continue;
        }

        if (movieExists(booking, name))
        {
            printf("⚠️ Movie already exists! Please choose a different name.\n");
            continue;
        }

        valid = 1;
    } while (!valid);
    strcpy(booking->movies[booking->movieCount].movieName, name);

    do
    {
        printf("🕒 Enter Movie Time (HH:MM): ");
        scanf(" %[^\n]", time);
    } while (!valid_time(time));
    strcpy(booking->movies[booking->movieCount].time, time);

    do
    {
        printf("💰 Enter Movie Ticket Price: ");
        scanf(" %f", &price);
    } while (!valid_price(price));
    booking->movies[booking->movieCount].price = price;

    do
    {
        printf("💺 Enter Total Seat Count: ");
        scanf(" %d", &total_seats);
    } while (!valid_total_seat(total_seats));

    booking->movies[booking->movieCount].total_seats = total_seats;
    booking->movies[booking->movieCount].available_seats = total_seats;

    for(int i = 0; i < booking->movies[booking->movieCount].total_seats; i++)
    {
        booking->movies[booking->movieCount].seat_no[i] = ((booking->movieCount + 1) * 100) + i + 1;
    }
    
    booking->movies[booking->movieCount].movieId = booking->movieCount + 1;
    booking->movieCount++;
    printf("\n✅ Movie '%s' added successfully with ID %d!\n", name, booking->movieCount);
}

void editMovies(Booking *booking)
{
    viewShows(booking);
    int movieId = -1, flag = 0;
    printf("Type the movie index : ");
    do
    {
        scanf("%d", &movieId);

        if( movieId == 0)
        {
            printf("\nGoing back to previous Menu...\n");
            return;
        }
        if( movieId < 1 || movieId > booking->movieCount )
        {
            printf("Invalid index, Enter Again");
        }
        else
        {
            break;
        }
    } while(1);
    int choice;
    do
    {
        printf("\n******%s*******\n", booking->movies[movieId - 1].movieName);
        printf("1. Change Name\n");
        printf("2. Change Price\n");
        printf("3. Change Time\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            changeMovieName(booking, movieId - 1);
            break;
        case 2:
            changeMoviePrice(booking, movieId - 1);
            break;
        case 3:
            changeMovieTime(booking, movieId - 1);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void deleteMovies(Booking *booking)
{
    viewShows(booking);
    int movieId = -1, flag = 0;
    printf("Type the movie index : ");
    do
    {
        scanf("%d", &movieId);
        if( movieId == 0)
        {
            printf("\nGoing back to previous Menu...\n");
            return;
        }
        if( movieId < 1 || movieId > booking->movieCount )
        {
            printf("Invalid index, Enter Again");
            continue;
        }
        if(booking->movies[movieId - 1].available_seats != booking->movies[movieId - 1].total_seats)
        {
            printf("Tickets are Booked, Cannot delete this Movie !\n");
            return;
        }
        break;
    } while(1);
    int i, j;
    for(i = 0; i < booking->userCount; i++)
    {
        j = 0;
        while(j < booking->user[i].booked_seat_count)
        {
            if((booking->user[i].booked_seats[j] / 100) == movieId)
            {
                removeUserSeat(booking, i, j);
            }
            else if(booking->user[i].booked_seats[j] / 100 >  movieId)
            {
                booking->user[i].booked_seats[j] = booking->user[i].booked_seats[j] - 100;  
            }
            j++;
        }
    }
    for (i = movieId; i < booking->movieCount; i++)
    {
        booking->movies[i - 1] = booking->movies[i];
        booking->movies[i - 1].movieId--;
    }
    booking->movieCount--;
    printf("\n🗑️ Movie Deleted Successfully...\n");
}

void viewBookedTicketAdmin(Booking *booking)
{
    printf("\n%40s==================== Booked Tickets ====================\n", " ");
    line();
    printf("%-10s%-40s%-50s%-20s%-20s\n", "S.No", "Username", "Movie Name", "Time", "Seat No.");
    line();
    int count = 0;
    for(int i = 0; i < booking->userCount; i++)
    {
        int movieindex[booking->movieCount], flag = 0;
        for(int j = 0; j < booking->movieCount; j++)
        {
            movieindex[j] = -1;
        }
        for (int j = 0; j < booking->user[i].booked_seat_count; j++)
        {
            int movieId = booking->user[i].booked_seats[j] / 100;
            if (movieId >= 1 && movieId <= booking->movieCount)
            {
                movieindex[movieId - 1] = 1;  
            }
        }
        for(int j = 0; j < booking->movieCount; j++)
        { 
            if(movieindex[j] != -1)
            {
                printf("%-10d%-40s%-50s%-20s", count + 1, booking->user[i].username, booking->movies[j].movieName, booking->movies[j].time);
                for(int k = 0 ; k < booking->user[i].booked_seat_count; k++)
                {
                    int movieId = booking->user[i].booked_seats[k] / 100;
                    if (movieId - 1 == j)
                    {
                        printf("%d, ", booking->user[i].booked_seats[k] % 100);
                    }
                }
                printf("\n");
                count++;
            }
        }
    }
    line();
    if(count == 0)
    {
        printf("No Booked Seats Found !\n");
    }
}
