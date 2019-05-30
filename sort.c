#include "editing.h"
#include "printing.h"
#include "adding.h"
#include "structures.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int getSizeOfAList(contact* head)
{
    contact* tmp = head;
    int size = 0;

    while(tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }

    return size;
}

contact* listToArray(contact* head)
{
    int size = getSizeOfAList(head);
    contact *tmp = head;

    contact* contactArray = malloc(size * sizeof(contact));

    int i = 0;
    for(; i < size; i++, tmp = tmp->next)
        contactArray[i] = *tmp;

    return contactArray;
}

void bsort_by_name(contact* contactArray, int size)
{
    int i=0, j = 0;
    contact temp;
    for(; j<=size; j++)
    {
        for(i=0; i<size-1; i++)
        {
            if(strcmp(contactArray[i].name, contactArray[i+1].name) > 0)
            {
                temp = contactArray[i];
                contactArray[i] = contactArray[i+1];
                contactArray[i+1] = temp;

            }
        }
    }
}

void printNameWithArray(contact* contactArray, int size)
{
    int i = 0;

    for(; i < size; i++)
    {

        printf("\nID: %d\n", contactArray[i].ID);
        printf("Name: %s\n", contactArray[i].name);
        printf("Surname: %s\n", contactArray[i].surname);
        printf("City: %s\n", contactArray[i].address->city);
        printf("Street: %s\n", contactArray[i].address->street);
        printf("House number: %d\n", contactArray[i].address->houseNumber);
        printf("Zip code: %s\n", contactArray[i].address->zipCode);
        printf("Post office: %s\n", contactArray[i].address->postOffice);
        int itterator =1;
        int mailIterator = 1;
        phone_t *temp = contactArray[i].phoneHead;
        email_t *temp2 = contactArray[i].emailHead;
        printf("Phone numbers:\n");
        while(temp != NULL)
        {

            printf("%d) %d\n", itterator, temp->phoneNumber);
            itterator++;
            temp = temp->next;
        }
        printf("Emails:\n");
        while(temp2 != NULL)
        {

            printf("%d) %s\n", mailIterator, temp2->emailAddress);
            mailIterator++;
            temp2=temp2->next;
        }
    }
}


void bsort_by_surname(contact* contactArray, int size)
{
    int i=0,j=0, k=0;
    contact temp;
    for(; j<=size; j++)
    {
        for(i=0; i<size-1; i++)
        {
            if(strcmp(contactArray[i].surname, contactArray[i+1].surname) > 0)
            {
                temp = contactArray[i];
                contactArray[i] = contactArray[i+1];
                contactArray[i+1] = temp;
            }
        }
    }
}

void bsort_by_city(contact* contactArray, int size)
{
    int i=0,j=0, k=0;
    contact temp;
    for(; j<=size; j++)
    {
        for(i=0; i<size-1; i++)
        {
            if(strcmp(contactArray[i].address->city, contactArray[i+1].address->city) > 0)
            {
                temp = contactArray[i];
                contactArray[i] = contactArray[i+1];
                contactArray[i+1] = temp;
            }
        }
    }
}



void swap(contact *a, contact *b)
{
    contact temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(contact *head)
{
    int swapped, i;
    contact *ptr1;
    contact *ptr2 = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2)
        {
            if (ptr1->name > ptr1->next->name)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while (swapped);
}
