#include "save_to_file.h"

#include <stddef.h>
#include <stdio.h>

void saveContacts(char* filename, contact* head){
    if(head == NULL){
        printf("No contacts to be saved!");
        return;
    }

    FILE* file = fopen(filename, "w");

    if(file == NULL){
        printf("Error opening file while saving!");
        return;
    }
    contact* currentContact = head;
    while(currentContact != NULL){
        fprintf(file, "%d\n", currentContact->ID);
        fprintf(file, "%s\n", currentContact->name);
        fprintf(file, "%s\n", currentContact->surname);

        saveAddress(file, currentContact);

        fprintf(file, "%d\n", getNOfPhoneNumbers(currentContact));
        savePhoneNumbers(file, currentContact->phoneHead);

        fprintf(file, "%d\n", getNOfEmails(currentContact));
        saveEmails(file, currentContact->emailHead);

        currentContact = currentContact->next;
    }

    fclose(file);
}

void saveAddress(FILE* file, contact* cont){
        fprintf(file, "%s\n", cont->address->city);
        fprintf(file, "%d\n", cont->address->houseNumber);
        fprintf(file, "%s\n", cont->address->postOffice);
        fprintf(file, "%s\n", cont->address->street);
        fprintf(file, "%s\n", cont->address->zipCode);
}

int getNOfPhoneNumbers(contact* cont){
    phone_t* currPhone = cont->phoneHead;
    int size = 0;

    while(currPhone != NULL){
        size++;
        currPhone = currPhone->next;
    }

    return size;
}

void savePhoneNumbers(FILE* file, phone_t* head){
    phone_t* temp = head;
    while(temp != NULL){
        fprintf(file, "%d\n", temp->phoneNumber);
        temp = temp->next;
    }
}

int getNOfEmails(contact* cont){
    email_t* currEmail = cont->emailHead;
    int size = 0;

    while(currEmail != NULL){
        size++;
        currEmail = currEmail->next;
    }

    return size;
}

void saveEmails(FILE* file, email_t* head){
    email_t* temp = head;
    while(temp != NULL){
        fprintf(file, "%s\n", temp->emailAddress);
        temp = temp->next;
    }
}
