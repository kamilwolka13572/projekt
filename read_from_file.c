#include "read_from_file.h"

#include <stdlib.h>
#include <stddef.h>

contact* loadContactsFromAFile(char* filename){

    FILE* file = fopen(filename, "r");

    if(file == NULL)
        return NULL;

    contact* head = (contact*)malloc(sizeof(contact));
    contact* currentContact = head;
    char buffer[128];
    int id;

    if(fscanf(file,"%[^\n]\n", buffer) != EOF){

        sscanf(buffer, "%d", &(head->ID));

        int nPhoneNumbers, nEmails;

        fscanf(file,"%[^\n]\n", head->name);

        fscanf(file,"%[^\n]\n", head->surname);

        head->address = loadAddress(file);

        fscanf(file,"%[^\n]\n", buffer);
        sscanf(buffer, "%d", &nPhoneNumbers);
        head->phoneHead = loadPhoneNumbers(file, nPhoneNumbers);

        fscanf(file,"%[^\n]\n", buffer);
        sscanf(buffer, "%d", &nEmails);
        head->emailHead = loadEmails(file, nEmails);
    }else{
        free(head);
        return NULL;
    }

    while(fscanf(file,"%[^\n]\n", buffer) != EOF){
        sscanf(buffer, "%d", &id);

        contact* contactBuffer = (contact*)malloc(sizeof(contact));
        contactBuffer->ID = id;

        int nPhoneNumbers, nEmails;

        fscanf(file,"%[^\n]\n", contactBuffer->name);
        fscanf(file,"%[^\n]\n", contactBuffer->surname);

        contactBuffer->address = loadAddress(file);

        fscanf(file,"%[^\n]\n", buffer);
        sscanf(buffer, "%d", &nPhoneNumbers);
        contactBuffer->phoneHead = loadPhoneNumbers(file, nPhoneNumbers);

        fscanf(file,"%[^\n]\n", buffer);
        sscanf(buffer, "%d", &nEmails);
        contactBuffer->emailHead = loadEmails(file, nEmails);

        currentContact->next = contactBuffer;
        currentContact = currentContact->next;
    }

    currentContact->next = NULL;

    fclose(file);

    return head;
}

address_t* loadAddress(FILE* file){

    address_t* address = (address_t*)malloc(sizeof(address_t));
    char buffer[128];

    fscanf(file,"%[^\n]\n", address->city);
    fscanf(file,"%[^\n]\n", buffer);
    sscanf(buffer, "%d", &(address->houseNumber));
    fscanf(file,"%[^\n]\n", address->postOffice);
    fscanf(file,"%[^\n]\n", address->street);
    fscanf(file,"%[^\n]\n", address->zipCode);

    return address;
}

phone_t* loadPhoneNumbers(FILE* file, int nPhoneNumbers){

    phone_t* head = (phone_t*)malloc(sizeof(phone_t));
    phone_t* currentPhone = head;
    char buffer[128];

    if(nPhoneNumbers < 1)
        return NULL;

    fscanf(file,"%[^\n]\n", buffer);
    sscanf(buffer, "%d", &(currentPhone->phoneNumber));

    int i = 1;
    for(; i < nPhoneNumbers; i++){
        phone_t* phoneBuffer = (phone_t*)malloc(sizeof(phone_t));
        fscanf(file,"%[^\n]\n", buffer);
        sscanf(buffer, "%d", &(phoneBuffer->phoneNumber));
        currentPhone->next = phoneBuffer;
        currentPhone = currentPhone->next;
    }

    currentPhone->next = NULL;

    return head;
}

email_t* loadEmails(FILE* file, int nEmails){
    email_t* emailHead = (email_t*)malloc(sizeof(email_t));
    email_t* currentEmail = emailHead;

    if(nEmails < 1)
        return NULL;

    fscanf(file,"%[^\n]\n", emailHead->emailAddress);

    int i = 1;
    for(; i < nEmails; i++){
        email_t* emailBuffer = (email_t*)malloc(sizeof(email_t));
        fscanf(file, "%[^\n]\n", emailBuffer->emailAddress);
        currentEmail->next = emailBuffer;
        currentEmail = currentEmail->next;
    }

    currentEmail->next = NULL;

    return emailHead;
}
