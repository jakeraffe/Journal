driver: driver.o delete_Entry.o edit_Entry.o journalEntries.o menu_Screen.o new_Entry.o read_Entry.o 
	g++ -g -o driver driver.o delete_Entry.o edit_Entry.o journalEntries.o menu_Screen.o new_Entry.o read_Entry.o 

driver.o: driver.cpp
	g++ -g  -c -pthread -I/sw/include/root driver.cpp

delete_Entry.o: delete_Entry.cpp
	g++ -g  -c -pthread -I/sw/include/root delete_Entry.cpp

edit_Entry.o: edit_Entry.cpp
	g++ -g  -c -pthread -I/sw/include/root edit_Entry.cpp

journalEntries.o: journalEntries.cpp
	g++ -g  -c -pthread -I/sw/include/root journalEntries.cpp

menu_Screen.o: menu_Screen.cpp
	g++ -g  -c -pthread -I/sw/include/root menu_Screen.cpp

new_Entry.o: new_Entry.cpp
	g++ -g  -c -pthread -I/sw/include/root new_Entry.cpp

read_Entry.o: read_Entry.cpp
	g++ -g  -c -pthread -I/sw/include/root read_Entry.cpp

journal.o: joural.cpp joural.h
	g++ -c joural.cpp