#include "structures.h"

#include <stdio.h>

/*!< zapisuje kontakty do pliku
filename - sciezka pliku do zapisu
head - pierwszy element listy kontaktow */
void saveContacts(char* filename, contact* head);

/*!< zapisuje adres danego kontaktu do pliku
file - uchwyt do pliku,
cont - kontakt, ktorego adres ma zostac zapisany */
void saveAddress(FILE* file, contact* cont);

/*!< zwraca ilosc numerow telefonow danego kontaktu
contact - kontakt, ktorego ilosc telefonow zwracamy
wartosc zwracana - ilosc telefonow */
int getNOfPhoneNumbers(contact* cont);

/*!< zwraca ilosc adresow email danego kontaktu
contact - kontakt, ktorego ilosc emaili zwracamy
wartosc zwracana - ilosc emaili */
int getNOfEmails(contact* cont);

/*!< zapisuje numery telefonow do pliku
file - uchwyt do pliku,
head - pierwszy element listy numerow telefonow */
void savePhoneNumbers(FILE* file, phone_t* head);

/*!< zapisuje adresy email do pliku
file - uchwyt do pliku,
head - pierwszy element listy adresow email*/
void saveEmails(FILE* file, email_t* head);
