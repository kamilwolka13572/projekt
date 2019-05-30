#include "search.h"
#include "structures.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 128


int search_na(contact* head)
{
    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        if(strstr(head->name, search))
        {
            id = head->ID;
            printf("Found: ID = %d \n", id);
            return id;
        }
        else
        {
            head = head->next;
        }
    }
    return -1;
}

int search_sur(contact* head)
{
    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        if(strstr(head->surname, search))
        {
            id = head->ID;
            printf("Found: ID = %d \n", id);
            return id;
        }
        else
        {
            head = head->next;
        }
    }
    return -1;
}

int search_c(contact* head)
{

    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {

        if(strstr(head->address->city, search))
        {
            id = head->ID;
            printf("Found: ID = %d \n", id);
            return id;
        }
        else
        {
            head = head->next;
        }
    }
    return -1;
}


int search_str(contact* head)
{
    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        if(strstr(head->address->street, search))
        {
            id = head->ID;
            printf("Found: ID = %d \n", id);
            return id;
        }
        else
        {
            head = head->next;
        }
    }
    return -1;
}


int search_zC(contact* head)
{
    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        if(strstr(head->address->zipCode, search))
        {
            id = head->ID;
            printf("Found: ID = %d \n", id);
            return id;
        }
        else
        {
            head = head->next;
        }
    }
    return -1;
}

int search_pO(contact* head)
{
    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        if(strstr(head->address->postOffice, search))
        {
            id = head->ID;
            printf("Found: ID = %d \n", id);
            return id;
        }
        else
        {
            head = head->next;
        }
    }
    return -1;
}

int search_ph(contact* head)
{
    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        phone_t* currentPhone = head->phoneHead;

        while(currentPhone != NULL)
        {
            if(strstr(currentPhone->phoneNumber, search))
            {
                id = head->ID;
                printf("Found: ID = %d \n", id);
                return id;
            }
            currentPhone = currentPhone->next;
        }

        head = head->next;
    }

    return -1;
}


int search_em(contact* head)
{

    int id;
    char search[LENGTH];
    printf("Write word or just part of:");
    fflush(stdin);
    fgets(search, LENGTH, stdin);
    search[strcspn(search, "\r\n")] = 0;
    while(head)
    {
        email_t* currentEmail = head->emailHead;

        while(currentEmail != NULL)
        {
            if(strstr(currentEmail->emailAddress, search))
            {
                id = head->ID;
                printf("Found: ID = %d \n", id);
                return id;
            }
            currentEmail = currentEmail->next;
        }

        head = head->next;
    }

    return -1;
}







