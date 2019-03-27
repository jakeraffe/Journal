//Console journal that you would see in a sci-fi film from the 80's.
//Jacob Raffe
//3-22-19 - whatever end date....
//all namespaces inported from .h file
#include "journal.h"
#include <stdlib.h>

//Creates a new entry object and adds it to the Entry vector in Journal.
/*TODO: 
    1. Figure out how getline can work with this or if we cant use it..
    2. Dont know why this works... It shouldnt let me push_back multiple objects of the same name. Could be part of the problem
    3. Maybe related to above, search doesn not find the added entry and I cannot read its contents in read_Entry. Says the title is not found..
*/  
void new_Entry(Journal &journal){
    Entry entry;
    string title;
    string date;
    string time;
    string log;

    cout << "Please end your inputs with a semicolon."<< endl << endl;

    cout << "Entry Title: ";
    cin >> title;
    if (title == "quit"){
        cout << "Journal entry cannot be named this. Please try again." << endl;
        new_Entry(journal);
    }
    else{
        entry.Title = title;
    }

    cout << "Date logged: ";
    // getline(cin, date, ';');
    cin >> date;
    entry.Date = date;

    cout << "Time logged: ";
    // getline(cin, time, ';');
    cin >> time;
    entry.Time = time;

    cout << "Enter your input please:" << endl;
    getline(cin, log, ';');
    entry.Log = log;

    cout << endl;

    cout << "Entry added to journal. Returning to menu" << endl << endl;

    // entry(title, time, date, log);
    journal.Entries.push_back(entry);

}

//
//I wanted to loop over the journal entries and display the title, date, and time multiple times so I just 
    //made a function instead of copying and pasting.
//It does takes a Journal object and loops over the entries in that journal using a range based loop.
void journalEntries(Journal &journal){
    //lets me number the entries
    int i = 0;
    cout << "Entries in journal: " << endl;
    for (const auto &j : journal.Entries){
        i++;
        cout << i << ". " << j.Title << " | " << j.Date << "| "<< j.Time << "| " << endl;
    }
}


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

    while(userSearch !="quit")
    {
        //Calls a function that searches for title via lambda find_if
        auto f = entriesSearch(journal, userSearch);

        cout << "Log contents:" << endl;
        cout << f->Log << endl << endl;

        //loops through entries and prints out their information.
        journalEntries(journal);

        cout << endl;
        cout << "Please select entry by its title or type 'no' to exit." << endl;
        cout << "Which entry would you like to read?" << endl;
        cin >> userSearch;
    }
    cout << "Ok. Returning to menu" << endl << endl;
}
//
// //accepts an entry and edits its contents. No const so it can change.
vector<Entry> edit_Entry(Journal &journal)
{
    journalEntries(journal);
    cout << endl;

    //Asks the user which entry they want to edit.
    string userInput;
    cout << "Which entry would you like to edit?: ";
    cin >> userInput;

    while (userInput != "quit"){
        //finds the users input or throws an error if it is wrong.
        auto f = find_if(journal.Entries.begin(), journal.Entries.end(),
                [=](const Entry &e){
                    {
                        if (e.Title == userInput)
                            return true;
                        else
                            return false;
                    }
                });

        if (f == journal.Entries.end()){
            cout << "There are no journals of that title. Please type a valid title." << endl;
        }
        else {
            string userEdit;
            cout << "What would you like to edit? Title, Date, Time or Log?: ";
            cin >> userEdit;
            cout << endl;
            if (userEdit == "Title" || userEdit == "title"){
                string userNewTitle;
                cout << "Please add the new title: ";
                getline(cin, userNewTitle, ';');
                f->Title = userNewTitle;
                cout << "Title updated.";
            }
            else if (userEdit == "Date" || userEdit == "date"){
                string userNewDate;
                cout << "Please add the new date for this entry: ";
                getline(cin, userNewDate, ';');
                f->Date = userNewDate;
                cout << "Date updated.";
            }
            else if (userEdit == "Time" || userEdit == "time"){
                string userNewTime;
                cout << "Please add the new time: ";
                getline(cin, userNewTime, ';');
                f->Time = userNewTime;
                cout << "Time updated.";
            }
            else if (userEdit == "Log" || userEdit == "log"){
                string userNewLog;
                cout << "Please add the new log for this entry: ";
                getline(cin, userNewLog, ';');
                f->Log = userNewLog;
                cout << "Log updated.";
            }
            else {
                cout << "Not a valid entry. Try again please." << endl;
            }
        }
        cout << endl;
        cout << "Which entry would you like to edit?: ";
        cin >> userInput;
    }
}
//
// //Deletes an entire entry from the vector.
void delete_Entry(Journal &journal)
{
    journalEntries(journal);

    string userDeleteEntry;

    cout << "Which entry would you like to delete? Please select by title: ";
    getline(cin, userDeleteEntry, ';');

    // auto f = entriesSearch(journal, userDeleteEntry);

    cout << "Returning to menu." << endl;
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
//
// }

void menu_Screen(string user){

    Entry entry2("first", "2/3/2018", "1400", "Hello there!");
    Entry entry3("second", "8/3/2019", "0200", "Goodbye!");
    Journal journal("Personal Journal", "3/23/2019", "1844");

    journal.Entries.push_back(entry2);
    journal.Entries.push_back(entry3);

    // Journal journal;
    //Flush screen of Name text...
    // cout << "\r";
    // cout << right;
    //Display welcome screen
    cout /*<< setw(56) << "\t"*/ << "Welcome " << user << endl << endl << endl;

    //Flush Screen of welcome text.


    cout << "Main Menu" << endl << endl;
    //Options to choose
    int choice;
    cout << "Please choose an option below" << endl;
    cout << "1. New Journal Entry" << endl;
    cout << "2. Read Old Entry" << endl;
    cout << "3. Edit Entry" << endl;
    cout << "4. Delete Entry" << endl;
    cout << "5. Sort Entry" << endl;
    cin >> choice;

    while(choice != 0){

        if (choice == 1){
            // entryIndex++;
            // Entry entryIndex;
            new_Entry(journal);
        }
        else if (choice == 2){
            read_Entry(journal);
        }
        else if (choice == 3){
            edit_Entry(journal);
        }
        else if (choice == 4){
            delete_Entry(journal);
        }
        else {
            cout << "Option not valid." << endl;
        }
        cout << endl;

        cout << "Main Menu" << endl << endl;
        cout << "Please choose an option below or '0' to exit" << endl;
        cout << "1. New Journal Entry" << endl;
        cout << "2. Read Old Entry" << endl;
        cout << "3. Edit Entry" << endl;
        cout << "4. Delete Entry" << endl;
        cout << "5. Sort Entry" << endl;

        cin >> choice;
        cout << endl;

    }
}

int main(int argc, char*argv[]){

    string userName;
    cout << right;
    cout /*<< setw(50) << "\t"*/ << "Please enter your name" << endl << endl << endl;
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
