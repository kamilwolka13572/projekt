#ifndef _ADDING_
#define _ADDING_
#include "structures.h"

/*!< wczytuje podana ilosc numerow telefonow
nNumbers - ilosc numerow telefonow
zwracana wartosc - pierwszy element listy telefonow */
phone_t* enterPhoneNumbers(int nNumbers);

/*!< wczytuje podana ilosc emaili
nEmails - ilosc emaili
zwracana wartosc - pierwszy element listy emaili */
email_t* enterEmails(int nEmails);

/*!< wczytuje dane kontaktu i dodaje go na koniec listy
contactHead - pierwszy element listy
zwracana wartosc - pierwszy element listy */
contact* addContact(contact* contactHead);

#endif
