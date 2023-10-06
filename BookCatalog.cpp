#include <vector>
#include <iostream>
#include <list>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

list<string> commands{ "Save", "Load", "Edit", "End" };
list<string> Book_Format{ "Title", "Author", "Published Year", "Inventory Count", "Genre" };


/*********************************
Basic Prompt function. Will recieve
user input and make it lower case.
**********************************/
string prompt(string message, bool lowerCase)
{
   string input = " ";
   cout << (message+" "), cin >> input;

   //This will help prevent user mishap by lowercasing everything.
   if (lowerCase) {
      for (char& c : input) {
      }
   }
   return input;

}

///*********************************
//Another Prompt function. Will recieve
//user input as is.
//**********************************/
//string promptNoEdits(string message)
//{
//   string input = " ";
//   cout << (message), cin >> input;
//   return input;
//}

/*********************************************************
* This will open and return the user's file as a vector.
* If file is created, will add in the format for the first line
*********************************************************/
vector<string> getAndOpenFile()
{
   string fileName = prompt("Please enter file name", false);

   fstream BookCatalog(fileName);

   if (!BookCatalog.is_open()) {
      throw runtime_error("File not opened");
   }

   vector<string> contents = {};
   string item = " ";

   while (getline(BookCatalog, item))
   {
      contents.push_back(item);
   }
   return contents;

}

void loadFile(vector<string> BookCatalog)
{
   for (auto element : BookCatalog) {
      cout << element << " " << "\n";
   }
}

/********************************************************
* The function to edit the file. This one will call 2
* functions. One will either edit the file and the other will
* delete item. For multiple edits, the file will use recursion.
* When a user is done editing, they need to tell the program.
*********************************************************/
vector<string> editFile(vector<string> BookCatalog)
{
   string action = prompt("Would like to add new items or delete? ", true);

   string input;
   list < string> BookInformation;

   if (action == "add") {
      //for (string i : Book_Format) {
      //   cout << i + " ";
      //   getline(cin, input);

      //   BookInformation.push_back(input);

      //}
      //for (string content : BookInformation) {
      //   BookCatalog.push_back(content);
      //}

      for (string i : Book_Format) {
         input = prompt(i, false);
         BookInformation.push_back(input);

      }
   }
   
   for()
   //else if (action == "delete") {
      // call function to delete items
   //}

   //else if (action == "end") {
      // end the function
   //}
   //else {
      // editFile(); Here do some recursion until user ends the program officially. 
   //}

   return BookCatalog;
}


/********************************************************
*This will get the user commands for what they wish to do
* to the file. Each command calls a function. Recursion
* will also be implemented until the file is saved and closed
********************************************************/
void getCommands() //this will get user command and decide what to do next. 
{
   vector<string> BookCatalog = getAndOpenFile();

   string action = " ";

   cout << "What would you like to do? \n";

   for (auto i : commands) {
      cout << i << '\n';
   }
   while (action != "end") {


      action = prompt("-", true);

      if (action == "save") {
         //write to file
      }

      else if (action == "load") {
         loadFile(BookCatalog);
      }

      else if (action == "edit") {
         BookCatalog = editFile(BookCatalog);
      }
   }
}

int main()
{
   getCommands();
   return 0;
}
