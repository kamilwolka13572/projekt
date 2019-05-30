#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editing.h"
#include "printing.h"
#include "adding.h"
#include "deleting.h"
#include "save_to_file.h"
#include "read_from_file.h"
#include "search.h"
#include "sort.h"
#include <stdio.h>
#include <windows.h>

void menu(); //!< funkcja, ktora sprawdza, jaka operacje uzytkownik chce aktualnie wykonac

char* contactsFilename = "contacts.txt"; /*!< sciezka pliku do zapisu/odczytu danych */
contact* contactHead = NULL; /*!< glowa listy kontaktow */

int main()
{
    contactHead = loadContactsFromAFile(contactsFilename);
    menu();

    return 0;
}

void menu()
{
    int wybor2;
    while(1)
    {

        printf("\n     PHONEBOOK\n\n");
        printf("What you want to do:\n");
        printf("1. Show all contacts\n");
        printf("2. Add \n");
        printf("3. Delete \n");
        printf("4. Edit \n");
        printf("5. Search \n");
        printf("6. Exit\n");
        printf("Your choice: ");
        int choice1;
        scanf("%d", &choice1);
        getchar();


        if(choice1 == 1)
        {
            Sleep(500);
            system("cls");
            printAllContacts(contactHead);
            printf("\n\nYou want to sort?\n");
            printf("1.Sort by name\n");
            printf("2.Sort by surname\n");
            printf("3.Sort by city\n");
            printf("4.Go back\n");
            printf("Your choice: ");
            scanf("%d", &wybor2);
            printf("\n\n");

            switch(wybor2)
            {
            case 1:
            {

                contact* contactArray = listToArray(contactHead);
                bsort_by_name(contactArray, getSizeOfAList(contactHead));
                system("cls");
                printNameWithArray(contactArray, getSizeOfAList(contactHead));
                menu();
            }

            case 2:
            {
                contact *contactArray = listToArray(contactHead);
                bsort_by_surname(contactArray, getSizeOfAList(contactHead));
                system("cls");
                printNameWithArray(contactArray, getSizeOfAList(contactHead));
                menu();
            }
            case 3:
                {
                contact *contactArray = listToArray(contactHead);
                bsort_by_city(contactArray, getSizeOfAList(contactHead));
                system("cls");
                printNameWithArray(contactArray, getSizeOfAList(contactHead));
                menu();
                }


            case 4:
                {
                Sleep(500);
                system("cls");
                menu();
                break;
                }

            }


        }
        else if(choice1 == 2)
        {
            system("cls");
            printf("\n");
            contactHead = addContact(contactHead);
            printf("\nContact has been added!");
            Sleep(1500);
            system("cls");
            saveContacts(contactsFilename, contactHead);
            menu();
        }
        else if(choice1 == 3)
        {
            contactHead = deleteContact(contactHead);
            saveContacts(contactsFilename, contactHead);
            Sleep(1000);
            system("cls");
            menu();
        }
        else if(choice1 == 4)
        {
            contactHead = editing(contactHead);
            saveContacts(contactsFilename, contactHead);
            Sleep(1000);
            system("cls");
            menu();

        }
        else if(choice1 == 5){
            int choice_to_search;
            printf("What do you want to search?\n[1]Name\n[2]Surame\n[3]City\n[4]Street\n[5]Zip code\n[6]Post Office\n[7]Phone\n[8]E-mail\n");
            scanf("%d", &choice_to_search);

        if(choice_to_search==1){
            search_na(contactHead);}
        else if(choice_to_search==2){
            search_sur(contactHead);}
        else if(choice_to_search==3){
            search_c(contactHead);}
            else if(choice_to_search==4){
            search_str(contactHead);}
            else if(choice_to_search==5){
            search_zC(contactHead);}
            else if(choice_to_search==6){
            search_pO(contactHead);}
            else if(choice_to_search==7){
            search_ph(contactHead);}
            else if(choice_to_search==8){
            search_em(contactHead);}
            else{
                printf("Wrong choice!");}

            Sleep(3000);
            system("cls");
            menu();
        }
        else if(choice1 == 6)
            exit(1);
        else
            printf("Wrong choice!\n\n\n");
            Sleep(1500);
            system("cls");
    }
}
