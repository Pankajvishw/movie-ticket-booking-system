/***********************************************************************
 *  File Name   : main.c
 *  Description : Entry point of the Movie Ticket Booking System.
 *                Handles the main user interface, sign up/login,
 *                and dispatches control to user/admin functionalities.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 08-Jul-2025
 ***********************************************************************/

#include "movies.h"
#include "populate.h"
#include "file.h"

// Function declarations
void signUp(Booking *booking);
void userLogin(Booking *booking);
void adminLogin(Booking *booking);

int main()
{
    char choice;
    Booking booking;

    initialize(&booking); // Initialize booking data

    do
    {
        printf("\n🎬 ========== Movie Ticket Booking ========== 🎟️\n");
        printf("1. User Login\n");
        printf("2. User Sign Up\n");
        printf("3. Admin Login\n");
        printf("4. Exit\n");
        printf("👉 Enter your choice: ");
        scanf(" %[^\n]", &choice);
        getchar();

        switch (choice)
        {
            case '1':
                userLogin(&booking);
                break;

            case '2':
                signUp(&booking);
                break;

            case '3':
                adminLogin(&booking);
                break;

            case '4':
                printf("👋 Exiting... Thank you for using Movie Ticket Booking System!\n");
                saveMovieToFile(&booking);
                saveUserToFile(&booking);
                break;

            default:
                printf("❌ Invalid choice. Please try again.\n");
        }

    } while (choice != '4');

    return 0;
}
