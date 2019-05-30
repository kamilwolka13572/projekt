#include "structures.h"

/*!< usuwa wybrany przez uzytkownika kontakt
head - pierwszy element listy kontaktow
zwracana wartosc - pierwszy element listy kontaktow */
contact* deleteContact(contact* head);

/*!< uwalnia zawartosc pamieci danego kontaktu
con - kontakt ktorego pamiec chcemy uwolnic */
void freeMemory(contact* con);
