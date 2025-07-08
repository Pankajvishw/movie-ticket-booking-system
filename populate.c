/***********************************************************************
 *  File Name   : populate.c
 *  Description : Loads initial dummy data for movies and users
 *                (used for testing) and generates seat numbers.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

#include "movies.h"
#include "populate.h"


static Movies dummyMovies[] = {
    {1, "Avengers: Endgame", "10:00", 250.0, 40, 40},
    {2, "Inception", "13:00", 200.0, 40, 40},
    {3, "Interstellar", "16:00", 220.0, 40, 40},
    {4, "Joker", "19:00", 180.0, 40, 40 },
    {5, "The Dark Knight", "21:30", 200.0, 40, 40}
};

static User dummyUser[] = {
    {"pankaj", "1234"},
    {"pkpk", "1212"},
};

void populateMovies(Booking *booking)
{
    int numDummyMovies = sizeof(dummyMovies) / sizeof(dummyMovies[0]);
    for (int i = 0; i < numDummyMovies; i++)
    {
        booking->movies[booking->movieCount++] = dummyMovies[i];
    }
}

void populateUser(Booking *booking)
{
    int numDummyUser = sizeof(dummyUser) / sizeof(dummyUser[0]);
    for(int i = 0; i < numDummyUser; i++) {
        booking->user[booking->userCount++] = dummyUser[i];
    }

    for(int i = 0; i < booking->userCount; i++)
    {
        booking->user[i].booked_seat_count = 0;
    }
}

void populateSeatNo(Booking *booking)
{
    for(int i = 0; i < booking->movieCount; i++)
    {
        for(int j = 0; j < booking->movies[i].total_seats; j++)
        {
            booking->movies[i].seat_no[j] = ((i + 1) * 100) + j + 1;
        }
    }
}