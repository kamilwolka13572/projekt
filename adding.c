#include "adding.h"
#include <stddef.h>
#include <stdlib.h>

phone_t* enterPhoneNumbers(int nNumbers){
    phone_t* head = malloc(sizeof(phone_t));

    if(head == NULL)
        return NULL;

    phone_t* lastPhone = head;

    printf("Enter 1. number: ");
    scanf("%d", &(head->phoneNumber));

    int i = 2;
    for(; i <= nNumbers; i++){

        phone_t* buffer = malloc(sizeof(phone_t));

        if(buffer != NULL){
            printf("Enter %d. number: ", i);
            scanf("%d", &(buffer->phoneNumber));

            lastPhone->next = buffer;
            lastPhone = lastPhone->next;
        }
    }

    lastPhone->next = NULL;

    return head;
}

email_t* enterEmails(int nEmails){
    email_t* head = (email_t*)malloc(sizeof(email_t));

    if(head == NULL)
        return NULL;

    email_t* lastEmail = head;

    printf("Enter 1. email: ");
    scanf("%s", head->emailAddress);

    int i = 2;
    for(; i <= nEmails; i++){

        email_t* buffer = (email_t*)malloc(sizeof(email_t));

        if(buffer != NULL){
            printf("Enter %d. email: ", i);
            scanf("%s", buffer->emailAddress);

            lastEmail->next = buffer;
            lastEmail = lastEmail->next;
        }
    }

    lastEmail->next = NULL;

    return head;
}

contact* addContact(contact* contactHead){
    contact* newContact = malloc(sizeof(contact));

    address_t* address = malloc(sizeof(address_t));

    printf("Name: ");
    scanf ("%[^\n]%*c", newContact->name);
    printf("Surname: ");
    scanf ("%[^\n]%*c", newContact->surname);
    printf("City: ");
    scanf ("%[^\n]%*c", address->city);
    printf("Street: ");
    scanf ("%[^\n]%*c", address->street);
    printf("House number: ");
    scanf("%d", &(address->houseNumber));
    getchar();
    printf("Zip code: ");
    scanf ("%[^\n]%*c", address->zipCode);
    printf("Post office: ");
    scanf ("%[^\n]%*c", address->postOffice);

    int nPhoneNum;
    printf("How many phone numbers: ");
    scanf("%d", &nPhoneNum);

    if(nPhoneNum <= 0)
        newContact->phoneHead = NULL;
    else{
        phone_t* head = enterPhoneNumbers(nPhoneNum);
        if(head != NULL)
            newContact->phoneHead = head;
        else
            newContact->phoneHead = NULL;
    }

    int nEmails;
    printf("How many emails: ");
    scanf("%d", &nEmails);

    if(nEmails <= 0)
        newContact->emailHead = NULL;
    else{
        email_t* head = enterEmails(nEmails);
        if(head != NULL)
            newContact->emailHead = head;
        else
            newContact->emailHead = NULL;
    }

    newContact->address = address;

    if(contactHead == NULL){
        newContact->ID = 0;
        contactHead = newContact;
        contactHead->next = NULL;
    }else{
        contact* endOfContacts = contactHead;
        while(endOfContacts->next != NULL)
            endOfContacts = endOfContacts->next;

        newContact->ID = endOfContacts->ID + 1;

        endOfContacts->next = newContact;
        newContact->next = NULL;
    }
    getchar();

    return contactHead;
}

