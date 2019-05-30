#include "printing.h"
#include <stddef.h>
#include <windows.h>

void printAllContacts(contact* contactHead){
    if(contactHead == NULL){
        printf("\n");
        printf("Zero contacts available to print!\n");
        Sleep(1500);
        system("cls");
        menu();

    }

    contact* currentContact = contactHead;
    while(currentContact != NULL){
            printf("\n");
        printContact(currentContact);
        currentContact = currentContact->next;
    }
}

void printContact(contact* contact){
    printf("Id: %d\n", contact->ID);
    printf("Name: %s\n", contact->name);
    printf("Surname: %s\n", contact->surname);
    printAddress(contact->address);
    printPhone(contact->phoneHead);
    printEmail(contact->emailHead);
}

void printAddress(address_t* address){
    printf("City: %s\n", address->city);
    printf("Street: %s\n", address->street);
    printf("House number: %d\n",address->houseNumber);
    printf("Zip code: %s\n", address->zipCode);
    printf("Post office: %s\n", address->postOffice);
}

void printPhone(phone_t* phoneHead){
    if(phoneHead == NULL){
        printf("Zero phone numbers.\n");
        return;
    }

    if(phoneHead->next == NULL)
        printf("Phone number: %d\n", phoneHead->phoneNumber);
    else{
        printf("Phone numbers:\n");
        int phoneNumberIterator = 1;

        while(phoneHead != NULL){
            printf("%d) %d\n", phoneNumberIterator, phoneHead->phoneNumber);
            phoneNumberIterator++;
            phoneHead = phoneHead->next;
        }
    }
}

void printEmail(email_t* emailHead){
    if(emailHead == NULL){
        printf("Zero emails.\n");
        return;
    }

    if(emailHead->next == NULL)
        printf("Email address: %s\n", emailHead->emailAddress);
    else{
        printf("Emails:\n");
        int emailNumberIterator = 1;

        email_t* currentEmail = emailHead;
        while(currentEmail != NULL){
            printf("%d) %s\n", emailNumberIterator, currentEmail->emailAddress);
            emailNumberIterator++;
            currentEmail = currentEmail->next;
        }
    }
}
