//Console journal that you would see in a sci-fi film from the 80's.
//Jacob Raffe
//3-22-19 - whatever end date....
//all namespaces inported from .h file
#include "journal.h"
// #include "new_Entry.cpp"
#include <stdlib.h>



//
//Same idea as journalEntries(). I do a search by title more than a few times so this made is easier.
//I return an iterator so It can be used in the function that needs it someplace else. Its really cool...
//Ex: auto iter = entriesSearch(journal); ---- now iter can be used like it normally would be.
vector<Entry>::const_iterator entriesSearch(Journal &journal, string userSearch){

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
        return f;
    }
}



// vector<Entry> sort_Entry(const vector<Entry>& entryTotal)
// {
//
// }
//
//
// //Looks at the vector to see the graveyard of deleted Entry to recover them.
// vector<graveyard> entry_Graveyard(const vector<Entry>& entry)
// {
////
// }


int main(int argc, char*argv[]){

    string userName;
    cout << right;
    cout << setw(50) << "\t" << "Please enter your name" << endl << endl << endl;
    // cout << setw(60) << "\t";
    getline(cin, userName);
    // system("cls");

    // while(!cin){
    //     cout << right;
    //     cout << setw(50) << "\t" << "Please enter your name" << endl << endl << endl;
    //     cout << setw(60) << "\t";
    //     cin >> userName;
    // }

    menu_Screen(userName);

    return 0;
}
