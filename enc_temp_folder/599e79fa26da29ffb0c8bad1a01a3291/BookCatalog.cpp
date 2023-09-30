
#include <vector>
#include <iostream>
#include <list>
#include <cctype>
#include <fstream>

using namespace std;

list<string> commands { "Save", "Load", "Edit", "End" };

string prompt(string message)
{
   string input = " ";
   cout << (message), cin >> input;
   
   for (char& c : input) { //This will help prevent user mishap by lowercasing everything. Need to make sure it wont affect the file name. 
      c = tolower(c);
   }
   return input;
}

ofstream getAndOpenFile()
{
   string fileName = prompt("Please enter the file name");
   ofstream BookCatalog;
   BookCatalog.open(fileName);
   return BookCatalog;
}

ofstream editFile(ofstream BookCatalog)
{
   ofstream updateFile;
   string action = prompt("Would like to add new items or delete?");

   if (action == "add") {
      //call function to add new items
   }

   else if (action == "delete") {
      // call function to delete items
   }

   else if (action == "end") {
      // end the function
   }
   else {
      // editFile(); Here do some recursion until user ends the program officially. 
   }

   return updateFile;
}

void getCommands() //this will get user command and decide what to do next. 
{
   ofstream BookCatalog = getAndOpenFile();

   string action = " ";

   cout << "What would you like to do? \n";

   for (auto i : commands) {
      cout << i << '\n';
   }

   action = prompt("-");

   if (action == "save"){
      //write to file
   }

   else if (action == "load"){
      //display file
   }

   else if (action == "edit"){
      // editFile(BookCatalog); //Unsure why error is here
   }

   else if (action == "end"){
      //close file
   }
}

int main()
{
   getCommands();
   return 0;
}
