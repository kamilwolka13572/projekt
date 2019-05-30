#ifndef _PRINTING_
#define _PRINTING_

#include "structures.h"

/*!< wypisuje wszystkie kontakty
contactHead - pierwszy element listy kontakow */
void printAllContacts(contact* contactHead);

/*!< wypisuje pojedynczy kontakt
contact - kontakt do wypisania*/
void printContact(contact* contact);

/*!< wypisuje pojedynczny adres
address - adres do wypisania */
void printAddress(address_t* address);

/*!<wypisuje wszystkie telefony w danej liscie
phoneHead - pierwszy element listy */
void printPhone(phone_t* phoneHead);

/*!<wypisuje wszystkie emaile w danej liscie
emailHead - pierwszy element listy*/
void printEmail(email_t* emailHead);

#endif
