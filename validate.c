/***********************************************************************
 *  File Name   : validate.c
 *  Description : Provides input validation utilities for the system.
 *                Includes validation for usernames, passwords,
 *                movie name, time format, seat count, etc.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

#include "movies.h"

#include "validate.h"
#include <string.h>
#include <ctype.h>

int cmp(const void * a, const void * b)
{
    return *(int *) a - *(int *) b;
}

int validSeatNo(Booking *booking, int movieId, int seatNo) {
    int base = (movieId + 1) * 100;
    for (int j = 0; j < booking->movies[movieId].total_seats; j++) {
        if (seatNo == (base + j + 1)) {
            return 1;
        }
    }
    return 0;
}

int validMovieName(char *movieName) {
    int i = 0;
    while (movieName[i]) {
        if (!(isalnum(movieName[i]) || movieName[i] == ' ')) return 0;
        i++;
    }

    if (strlen(movieName) >= 50) {
        return 0;
    }
    return 1;
}

int movieIdExists(Booking *booking, int movieId) {
    for (int i = 0; i < booking->movieCount; i++) {
        if (movieId == booking->movies[i].movieId) {
            return 1;
        }
    }
    return 0;
}

int movieExists(Booking *booking, char *movieName) {
    for (int i = 0; i < booking->movieCount; i++) {
        if (strcmp(movieName, booking->movies[i].movieName) == 0) {
            return 1;
        }
    }
    return 0;
}

int validUsername(char *username) {
    int i = 0;
    while (username[i]) {
        if (!((username[i] >= '0' && username[i] <= '9') ||
              (username[i] >= 'a' && username[i] <= 'z'))) {
            return 0;
        }
        i++;
    }

    if (strlen(username) >= 30) {
        return 0;
    }
    return 1;
}

int usernameExists(Booking *booking, char *username) {
    for (int i = 0; i < booking->userCount; i++) {
        if (strcmp(booking->user[i].username, username) == 0)
            return i + 1;
    }
    return 0;
}

int validPassword(char *password) {
    int i = 0;
    while (password[i]) {
        if (!isalnum(password[i])) {
            printf("Invalid Password, Try Again !\n");
            return 0;
        }
        i++;
    }
    return strlen(password) >= 4;
}

int matchPassword(Booking *booking, int userIndex, char *password) {
    return strcmp(booking->user[userIndex].password, password) == 0;
}

void changeLogin(Booking *booking, int userIndex) {
    char username[30], password[20];

    printf("\n🔐 (Type '0' to go back) Enter your new credentials\n");

    do {
        printf("👤 New Username: ");
        scanf(" %[^\n]", username);

        if (strcmp(username, "0") == 0) {
            printf("🔙 Going back to the previous menu...\n");
            return;
        }

        if (!validUsername(username)) {
            printf("❌ Please enter a valid username (lowercase and numbers only)\n");
            continue;
        }
        printf("🔑 New Password: ");
        scanf(" %[^\n]", password);

        if (strcmp(password, "0") == 0) {
            printf("🔙 Going back to the previous menu...\n");
            return;
        }

        if (validPassword(password)) {
            strcpy(booking->user[userIndex].username, username);
            strcpy(booking->user[userIndex].password, password);
            printf("✅ Credentials changed successfully!\n");
            return;
        } else {
            printf("❌ Invalid password. Use only letters and digits (min 4 chars).\n");
        }
    } while (1);
}

int valid_price(float price) {
    if (price > 0) {
        return 1;
    } else {
        printf("❌ Invalid price. Must be greater than 0.\n");
        return 0;
    }
}

int valid_time(char *time) {
    int hour, minute;
    if (sscanf(time, "%2d:%2d", &hour, &minute) != 2) {
        printf("❌ Invalid format! Use HH:MM\n");
        return 0;
    }
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("❌ Time out of range! (00:00 to 23:59)\n");
        return 0;
    }
    return 1;
}

int valid_total_seat(int seats) {
    if (seats > MAX_SEATS) {
        printf("⚠️ Max seating capacity is only 40. Please enter a valid number.\n");
        return 0;
    }
    if (seats < 20) {
        printf("❌ Seating capacity cannot be less than 20.\n");
        return 0;
    }
    return 1;
}
