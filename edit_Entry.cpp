#include "journal.h"



//accepts an entry and edits its contents. No const so it can change.
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