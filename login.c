/***********************************************************************
 *  File Name   : login.c
 *  Description : Contains user and admin login functionalities for the
 *                Movie Ticket Booking System. Handles:
 *                  - User signup with validation
 *                  - User login with menu navigation
 *                  - Admin login with privileges
 *                  - Role-specific access to booking and management features
 *
 *  Functions:
 *                - signUp()
 *                - userLogin()
 *                - adminLogin()
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
#include "validate.h"
#include "login.h"
#include "search.h"

void signUp(Booking *booking) {

    if(booking->userCount > MAX_USERS)
    {
        printf("\nMax Users Limit Reached, Cannot Add More Users !\n");
        return ;
    }
    char username[30], password[20];
    printf("\n🔐 (Type '0' to go back) Enter Your Credentials\n");

    do {
        printf("👤 Username: ");
        scanf(" %[^\n]", username);

        if (strcmp(username, "0") == 0) {
            printf("🔙 Going back to the previous menu...\n");
            return;
        }

        if (!validUsername(username)) {
            printf("⚠️ Please enter a valid username.\n");
            continue;
        }

        if (usernameExists(booking, username)) {
            printf("❌ Username already exists!\n");
        } else {
            printf("🔑 Password: ");
            scanf(" %[^\n]", password);

            if (strcmp(password, "0") == 0) {
                printf("🔙 Going back to the previous menu...\n");
                return;
            }

            if (validPassword(password)) {
                strcpy(booking->user[booking->userCount].username, username);
                strcpy(booking->user[booking->userCount].password, password);
                booking->user[booking->userCount].booked_seat_count = 0;
                booking->userCount++;
                printf("✅ User created successfully! %d %d %d\n",booking->user[booking->userCount].booked_seat_count, booking->user[booking->userCount].booked_seats[39], booking->userCount);
                return;
            }
        }
    } while (1);
}

void userLogin(Booking *booking) {
    char username[30], password[20];
    int userIndex = -1;

    printf("\n🔐 (Type '0' to go back) Enter Your Credentials\n");

    do {
        printf("👤 Username: ");
        scanf(" %[^\n]", username);

        if (strcmp(username, "0") == 0) {
            printf("🔙 Going back to the previous menu...\n");
            return;
        }

        if (!validUsername(username)) {
            printf("⚠️ Enter a valid username.\n");
            continue;
        }

        userIndex = usernameExists(booking, username);

        if (userIndex > 0) {
            userIndex -= 1;

            printf("🔑 Password: ");
            scanf(" %[^\n]", password);

            if (strcmp(password, "0") == 0) {
                printf("🔙 Going back to the previous menu...\n");
                return;
            }

            if (matchPassword(booking, userIndex, password)) {
                printf("\n✅ You are logged in as: %s\n", booking->user[userIndex].username);
                break;
            } else {
                printf("❌ Wrong password.\n");
                continue;
            }

        } else {
            printf("\n❌ Username does not exist! Try again.\n");
        }
    } while (1);

    int choice;
    do {
        printf("\n🎬 ========== User Menu ========== 🎟️\n");
        printf("1. View Available Movies\n");
        printf("2. Book Tickets\n");
        printf("3. View Booked Tickets\n");
        printf("4. Cancel Booking\n");
        printf("5. Change Login Credentials\n");
        printf("6. Sign Out\n");
        printf("👉 Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewShows(booking);
                break;
            case 2:
                bookTicket(booking, userIndex);
                break;
            case 3:
                viewBookedTicket(booking, userIndex);
                break;
            case 4:
                cancelTicket(booking, userIndex);
                break;
            case 5:
                changeLogin(booking, userIndex);
                break;
            case 6:
                printf("💾 Saving and signing out...\n");
                break;
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

void adminLogin(Booking *booking) {
    char username[30], password[20];

    printf("\n🔐 (Type '0' to go back) Enter Admin Credentials\n");

    do {
        printf("👤 Username: ");
        scanf(" %[^\n]", username);

        if (strcmp(username, "0") == 0) {
            printf("🔙 Going back to the previous menu...\n");
            return;
        }

        if (strcmp(username, "pankaj") != 0) {
            printf("❌ Username does not exist.\n");
            continue;
        }

        printf("🔑 Password: ");
        scanf(" %[^\n]", password);

        if (strcmp(password, "0") == 0) {
            printf("🔙 Going back to the previous menu...\n");
            return;
        }

        if (strcmp(password, "1234") == 0) {
            printf("\n✅ Logged in as: Pankaj\n");
            break;
        } else {
            printf("❌ Wrong password.\n");
        }
    } while (1);

    int choice;
    do {
        printf("\n🎬 ========== Admin Menu ========== 🛠️\n");
        printf("1. View Available Movies\n");
        printf("2. Add Movies\n");
        printf("3. Edit Movie Details\n");
        printf("4. Delete Listed Movies\n");
        printf("5. View All Sold Tickets\n");
        printf("6. Sign out\n");
        printf("👉 Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewShows(booking);
                break;
            case 2:
                addMovies(booking);
                break;
            case 3:
                editMovies(booking);
                break;
            case 4:
                deleteMovies(booking);
                break;
            case 5:
                viewBookedTicketAdmin(booking);
                break;
            case 6:
                printf("📤 Exiting admin panel...\n");
                break;
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
