#include "structures.h"
#include <stdio.h>

/*!< wczytuje adres z pliku
file - uchwyt pliku
zwracana wartosc - wczytany adres */
address_t* loadAddress(FILE* file);

/*!< wczytuje numery telefonow z pliku
file - uchwyt pliku
nPhoneNumbers - ilosc numerow telefonow do wczytania
zwracana wartosc - lista wczytanych telefonow */
phone_t* loadPhoneNumbers(FILE* file, int nPhoneNumbers);

/*!< wczytuje adresy email z pliku
file - uchwyt pliku
nEmails - ilosc adresow email do wczytania
zwracana wartosc - lista wczytanych adresow email */
email_t* loadEmails(FILE* file, int nEmails);

/*!< wczytuje kontakty z pliku
filename - sciezka pliku z ktorego wczytujemy
zwracana wartosc - lista kontaktow */
contact* loadContactsFromAFile(char* filename);
