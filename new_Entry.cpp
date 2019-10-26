#include "journal.h"

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
    getline(cin, title, '\n');
    //cin >> title;
    if (title == "quit"){
        cout << "Journal entry cannot be named this. Please try again." << endl;
        new_Entry(journal);
    }
    else{
        entry.Title = title;
    }

    cout << "Date logged: ";
    getline(cin, date, '\n');
    // cin >> date;
    entry.Date = date;

    cout << "Time logged: ";
    getline(cin, time, '\n');
    // cin >> time;
    entry.Time = time;

    cout << "Enter your input please:" << endl;
    getline(cin, log, ';');
    entry.Log = log;

    cout << endl;

    cout << "Entry added to journal. Returning to menu" << endl << endl;

    // entry(title, time, date, log);
    journal.Entries.push_back(entry);

}