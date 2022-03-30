/**
 * @file demo.c
 * @author Aashish Kalra(aashish.kalra1999@.com)
 * @brief This file contains description to all the functions 
 * @version 1
 * @date 2022-02-09
 * @copyright Copyright (c) 2022
 * 
 */
#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_size 100
int currentSize = 0; //current number of contacts in the Contact structure

Contact contacts[MAX_size]; // array of structure Contact

int addContact()
{
    if(currentSize == MAX_size) 
    {
        printf("\nContact List Full\n");
        return 0;
    }
    else
    {
    Contact* c1;
    c1 = (Contact*)(malloc(sizeof(Contact)));
        int flag=0;
        printf("\n First Name: ");
        fgets(c1->firstName,25,stdin);
        printf("\n Last Name: ");
        fgets(c1->lastName,25,stdin);
        printf("\n Phone Number: ");
        fgets(c1->phoneNumber,11,stdin);
        printf("\n Email Id: ");
        fgets(c1->email,50,stdin);
        printf("\n City: ");
        fgets(c1->city,50,stdin);
        contacts[currentSize] = *c1;
        ++currentSize;
        printf("\nContact sucessfully added.\n");
        free(c1);
    }
}

int displayContact(int i)
{
    if(i < 0 || i >= currentSize) 
    {
        printf("\nInvalid index entered");
        return 0;
    }
    Contact* c1 = &contacts[i];
    printf("\nFirst Name: %s\n", c1->firstName);
    printf("Last Name : %s\n", c1->lastName);
    printf("Mobile No : %s\n", c1->phoneNumber);
    printf("Email Id : %s\n\n",c1->email);
    printf("City : %s\n\n",c1->city);
    return 1;
}

int displayAllContacts()
{
    if(currentSize == 0) 
    {
        printf("\nNo Existing Contacts\n");
        return 0;
    }
    int k;
    for(k = 0;k< currentSize; k++)
    {
        displayContact(k);
        printf("\n");
    }
}

int searchContact(char *input, search_t attribute)
{
    int flag = 0,i;
    char content[25];
    if(attribute == FIRST_NAME) 
    { // searching by first name
        for(i=0; i<currentSize; i++)
         {
            strcpy(content, contacts[i].firstName);
            if(strcmp(content, input) == 0) 
            {
                displayContact(i);
                flag = 1;
            }
        }
    }
    else if(attribute  == MOBILE_NUMBER) 
    { // searching by mobile number
        for(i=0; i<currentSize; i++) 
        {
            strcpy(content, contacts[i].phoneNumber);
            if(strcmp(content, input) == 0) 
            {
                displayContact(i);
                flag = 1;
            }
        }
    }
    else if(attribute == CITY)
    {
       // searching by email id
        for(i=0; i<currentSize; i++) 
        {
            strcpy(content, contacts[i].city);
          
            if(strcmp(content, input) == 0) 
            {
                displayContact(i);
                flag = 1;
            }
        } 
    }
    else 
    {
        printf("\nInvalid Searching type\n");
        return 0;
    }

    if(!flag) 
    {
        printf("\nContact not found in the phonebook manager\n");
    }
}

int removeContact(char *phoneNumber)
{
    if(currentSize == 0) 
    {
        printf("\nPhoneBook Manager is empty, Cannot delete anything\n");
        return 0;
    }
    int i, j;
    int cnt = 0;
    for(i=0; i<currentSize; i++) 
    {
        if(strcmp(contacts[i].phoneNumber, phoneNumber) == 0) 
        {
            for(j=i; j<currentSize-1; j++) 
            {
                contacts[j] = contacts[j+1];
            }
            strcpy(contacts[j].firstName, "");
            strcpy(contacts[j].lastName, "");
            strcpy(contacts[j].phoneNumber, "");
            strcpy(contacts[j].email, "");
            currentSize -= 1;
            ++cnt;
        }
    }
    if(cnt == 0) 
    {
        printf("\nNo Contact is deleted\n");
    }
    else 
    {
        printf("%d contact deleted\n", cnt);
    }
}
int retriveFromFile()
{
    FILE *fp;
    if((fp = fopen("PhoneBook_Manager.txt", "r")) == NULL) 
    {
        printf("\nError: Cannot load the Contact Manager file\n");
        return 5;
    }

    /* read the size of the phone book */
    if(fread(&currentSize, sizeof(currentSize), 1, fp) != 1) 
    {
        printf("\nError, Cannot read data\n");
        return 3;
    }

    /* read the actual phone book content */
    if(fread(contacts, sizeof(contacts), 1, fp) != 1) 
    {
        printf("\nError, Cannot read data\n");
        return 4;
    }
    fclose(fp);
    return 5;

}
int storeToFile()
{
    FILE *fp;
    if( (fp = fopen("PhoneBook_Manager.txt", "w")) == NULL ) 
    {
        printf("\nCannot create Contact Manager file\n");
        return 2;
    }

    /* Save the current size of the phonebook */
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1 ) 
    {
        printf("\nCannot save the contact\n");
        return 3;
    }
    /* save the phonebook contents */
    if(fwrite(contacts, sizeof(contacts), 1, fp) != 1)
     {
        printf("\nCannot save the contact\n");
        return 4;
    }
    printf("\nPhoneBook Manager saved to file successfully! \n");
    fclose(fp);
    return 5;
}
