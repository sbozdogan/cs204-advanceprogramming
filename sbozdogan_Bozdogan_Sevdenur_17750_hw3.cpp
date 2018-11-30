/***** Sevdenur Bozdoðan 17750 *****/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "strutils.h"
using namespace std;

struct node{ // my struct for the doubly linked list with words of the file and their occurences.
	string word;
	int occurences;
	node *next;
	node *prev;

	node::node() //default constructor.
		: word(" "), occurences(0), next(NULL), prev(NULL)
	{}

	node::node( string w, int j, node *n, node *p) //constructor.
		: word(w), occurences(j), next(n), prev(p)
	{}
};

int main()
{
	string fileName;
	ifstream reader;

	cout << "Please enter the name of the file: " ;
	cin >> fileName;

	reader.open(fileName.c_str());

	while(reader.fail()) //if a fail occurs when reading the file, it must prompt again until it opens succesfully
	{
		cout << "File cannot be opened." << endl;
		cout << "Please enter the name of the file again: " ;
		cin >> fileName;
		reader.open(fileName); 
	}

	string wordInFile;
	while (!reader.eof())
	{
	
		while (reader >> wordInFile)
		{
			StripPunc(wordInFile);
			ToLower(wordInFile);
			char initial;
			reader >> initial;
			if( initial < 'a' || initial > 'z' )
			{
				cout << wordInFile << " cannot be added" << endl;
			}


		}
	}

	cout << "File " << fileName << " has been read and processed" << endl;


	while (true)
	{
		cout << "---------------------------------------------------------------" << endl;
		cout << "Please select one option:" << endl;
		cout << "1. Display the count of a specific word" << endl;
		cout << "2. Remove a specific word" << endl;
		cout << "3. Display words with the same initial letter (in alphabetical order)" << endl;
		cout << "4. Display words with the same initial letter (in reverse alphabetical order)" << endl;
		cout << "5. Display all words (in alphabetical order)" << endl;
		cout << "6. Display all words (in reverse alphabetical order)" << endl;
		cout <<"7. Exit" << endl;

		int option;
		cout << endl << endl << endl;
		cout << "Your choice:" ;
		cin >> option;

		if (option == 1)
		{
			string wordToFind;
			cout << "Please enter a word to find out its count: " ;
			cin >> wordToFind;
			cout << "*************************************" << endl;
		}

		else if(option == 2)
		{
			string wordToRemove;
			cout << "Please enter a word to remove: " ;
			cin >> wordToRemove;
			cout << "*************************************" << endl;
		}

		else if(option == 3)
		{
			char letter;
			cout << "Please enter a letter: " ;
			cin >> letter;
			cout << "*************************************" << endl;
		}

		else if(option == 4)
		{
			char letter;
			cout << "Please enter a letter: " ;
			cin >> letter;
			cout << "*************************************" << endl;
		}

		else if(option == 5)
		{
			cout << "*************************************" << endl;
		}

		else if(option == 6)
		{
			cout << "*************************************" << endl;
		}

		else
		{
			return 0;
		}





	}
}