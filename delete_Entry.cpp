#include "journal.h"

//Deletes an entire entry from the vector.
void delete_Entry(Journal &journal)
{
    journalEntries(journal);

    string userDeleteEntry;

    cout << "Which entry would you like to delete? Please select by title: ";
    getline(cin, userDeleteEntry, ';');

    // auto f = entriesSearch(journal, userDeleteEntry);

    cout << "Returning to menu." << endl;
}