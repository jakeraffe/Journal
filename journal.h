//Console journal that you would see in a sci-fi film from the 80's.
//Jacob Raffe
//3-22-19 - whatever end date....
//Note, I am using these namespaces because I can and I dont have the patients right now to not use them.


/*API.h file*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <ctime>
using namespace std;
using std::setw;
using std::left;
using std::right;
using namespace std::chrono;

//Main data entry class

class Entry
{
    private:
    public:
        string Title;
        string Date;
        string Time;
        string Log;

    Entry()

    //Default constructor
    : Title("Null"), Date("Null"), Time("Null"), Log("Null")
    { }

    //Parameterized constructor
    Entry(string title, string date, string time, string log)
        : Title(title), Date(date), Time(time), Log(log)
    { }

    //Methods
    string getLog() const
    {
        return Log;
    }

    string getDate() const
    {
        return Date;
    }

    string getTime() const
    {
        return Time;
    }

};

/*TODO:
1) do something with the current time - entries,
see the most receint entry to display it somewhere.
2) Sort entries in vector by date then by time using Lambda expressions.
3)


*/
class Journal
{
    private:
    public:
    string Name;
    string Date;
    string Time;
    vector<Entry> Entries;

    //Default constructor
    Journal()
    : Name("Blank Journal"), Date(0), Time(0)
    { }

    //Parameterized constructor
    Journal(string name, string date, string time)
    : Name(name), Date(date), Time(time)
    { }

};

void menu_Screen(string user);

void new_Entry(Journal& journal);

void journalEntries(Journal &journal);

void read_Entry(Journal &journal);

vector<Entry> edit_Entry(Journal &journal);

void delete_Entry(Journal &journal);


// sort_Entries();

// entry_Graveyard();



//Not sure about this yet...
//new_Journal(){ }
//delete_Journal(){ }
