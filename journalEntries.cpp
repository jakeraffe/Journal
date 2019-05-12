#include "journal.h"


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