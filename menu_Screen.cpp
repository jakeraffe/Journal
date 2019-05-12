#include "journal.h"


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