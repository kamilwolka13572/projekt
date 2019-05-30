#include "editing.h"
#include "printing.h"
#include "adding.h"
#include <stddef.h>
#include <stdio.h>

contact* editing(contact* head){

    if(head == NULL){
        printf("No contacts to edit!\n");
        return NULL;
    }

    printAllContacts(head);

    printf("\n");

    int id;
    printf("Enter the id of contact that you want to edit: ");
    scanf("%d", &id);
    getchar();

    contact* prevContact = NULL;
    contact* contactToEdit = head;
    while(contactToEdit != NULL && contactToEdit->ID != id){
        prevContact = contactToEdit;
        contactToEdit = contactToEdit->next;
    }

    if(contactToEdit == NULL){
        printf("Given id does not exist!\n");
        return head;
    }

    contact* nextContact = contactToEdit->next;
    contact* editedContact = addContact(NULL);

    if(prevContact != NULL) //wybrany kontakt nie jest pierwszym elementem listy
        prevContact->next = editedContact;
    else //wybrany kontakt jest pierwszym elementem listy
        head = editedContact;

    editedContact->next = nextContact;
    editedContact->ID = id;

    printf("Contact edited successfully\n");

    return head;
}
