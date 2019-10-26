#include "journal.h"


//Sends a journal entry to this function and prints its contents as well as date and Time
void read_Entry(Journal& journal)
{
    cout << endl << endl;
    //used later to search for an entry.
    string userSearch;

    //loops through entries and prints out their information.
    journalEntries(journal);

    cout << endl << endl;
    //only searching by title for now. Can change later if I want to add more.
    cout << "Please select entry by its title or type 'no' to exit." << endl;
    cin >> userSearch;

    while(userSearch !="q" || userSearch != "Q")
    {
        //Calls a function that searches for title via lambda find_if
        //searched the journal entries from beginning to end and tries to match with a passed title string.
        auto f = find_if(journal.Entries.begin(), journal.Entries.end(),
                [=](const Entry &e){
                    {
                        if (e.Title == userSearch)
                            return true;
                        else
                            return false;
                    }
                });
        cout << endl;

        //if nothing returns true, there was no match.
        if (f == journal.Entries.end()){
            cout << "There are no entries with that title. Please try again." << endl;
        }
        //returns the iterator
        else {
            printf("\n\n\n\n");
            cout << "Log contents:" << endl;
            cout << f->Log << endl << endl;
            printf("\n\n\n\n");
        }

        //loops through entries and prints out their information.
        journalEntries(journal);

        cout << endl;
        cout << "Please select entry by its title or type 'q' to exit." << endl;
        cout << "Which entry would you like to read?" << endl;
        cin >> userSearch;
    }
    cout << "Ok. Returning to menu" << endl << endl;
}