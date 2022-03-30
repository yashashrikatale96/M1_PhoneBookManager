/**
 * @file main.c
 * @author Aashish Kalra(aashish.kalra1999@.com)
 * @brief This file contains only the main fucntion
 * @version 1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"  // user defined header file
extern void test_main();
int main()
{
    // #if 0 // Uncomment while Unit testing
    retriveFromFile();
    char input[50];
    int user_choice;
    while(1)
    {
        printf("\nPhoneBook_Manager Utility Main menu\n\n");
        printf("    1. Add a new Contact\n");
        printf("    2. Display All Contacts\n");
        printf("    3. Search Contact by First Name\n");
        printf("    4. Search Contact by Phone Number\n");
        printf("    5. Search Contact by City\n");
        printf("    6. Delete a Contact by Phone Number \n");
        printf("    7. Save Data to a File\n");
        printf("    8. Exit\n");
        
        do {
            printf("\nEnter your choice: \n");
            fgets(input,50,stdin);
            user_choice = atoi(input);
        } 
        while (user_choice < 1 || user_choice > 8);

        switch(user_choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            displayAllContacts();
            break;
        case 3:
            printf("Please enter the First Name of contact to search:\n ");
            fgets(input,50,stdin);
            searchContact(input, FIRST_NAME);
            break;
        case 4:
            printf("Please enter the Phone Number of the contact to search: \n");
            fgets(input,50,stdin);
            searchContact(input, MOBILE_NUMBER);
            break;
        case 5:
            printf("Please enter the City of the contact to search: \n");
            fgets(input,50,stdin);
            searchContact(input, CITY);
            break;
        case 6:
            printf("Please enter the Phone Number of the contact to delete: \n");
            fgets(input,50,stdin);
            removeContact(input);
            break;
        case 7:
            storeToFile();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    }
    // Uncomment next 3 lines while unit testing
    /* #else
    test_main();
    #endif*/
    return 0;
}