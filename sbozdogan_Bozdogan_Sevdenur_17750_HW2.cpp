/***** Sevdenur Bozdoðan 17750 *****/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct node {   //my struct for the movie rating system with names of movies, total ratings and number of ratings.
	string movieName;
	double totalRating;
	int numRatings;
	node *next;

	node::node() //my default constructor
		:movieName(" "), totalRating(0), numRatings(0), next(NULL)
	{}

	node::node(string name, int j, int k, node *n) //constructor
		: movieName(name), totalRating(j), numRatings(k), next(n)
	{}

};



void showList (node *head) //i used this function for fourth option
{
	cout << "Movie Name\t\t" <<  "Ratings Received\t"  << "Avg. Rating" << endl;

	while (head != NULL)
	{

		cout << head -> movieName << "\t\t" << head -> numRatings << "\t\t\t" << (head -> totalRating)/(head -> numRatings) << "\t" << endl;
		head = head -> next;
	}
}

bool searchMovie (node *head, string nameOfMovie) // i used this function for catching an update for a movie
{
	node *temp = head;
	while (temp != NULL)
	{
		if(temp->movieName == nameOfMovie)
		{
			return true;
		}
		temp = temp -> next;

	}
	return false;
}


int main()
{
	node *head = NULL;

	while (true) //menu should be displayed and new option is selected until user enters 5.
	{
		cout << "Movie Rating System" << endl;  //the option part
		cout << "--------------------------------------" << endl;
		cout << "Please select one option:" << endl << "1. Load movie ratings from a file." << endl << "2. Add a new rating manually." << endl;
		cout << "3. Remove an existing movie. " << endl << "4. Display the list of movies and rating information." << endl <<"5. Exit." << endl;
		int option;
		cout << endl << endl << endl;
		cout << "Your choice:" ;
		cin >> option;



		if( option == 1) //loading movie names and ratings from a file
		{
			string fileName;
			ifstream reader;

			cout << "Please enter the name of the file:" ;
			cin >> fileName;

			reader.open(fileName.c_str());

			while(reader.fail()) //if a fail occurs when reading the file, it must prompt again until it opens succesfully
			{
				cout << "File cannot be opened." << endl;
				cout << "Please enter the name of the file again:" ;
				cin >> fileName;
				reader.open(fileName); 
			}
			string line;
			while(getline (reader,line))
			{
				string nameMovie;
				double ratingMovie;
				double numOfRatings;


				stringstream iss(line); //because first part is a movie name, second part is the rating of this movie

				iss >> nameMovie;
				iss >> ratingMovie;
				if ( ratingMovie < 1 || ratingMovie > 10 ) //input check
				{
					cout << "Movie " << nameMovie << " does not have a valid rating." << endl;
				}

				else //when entered rating from user is accurate
				{
					if(searchMovie(head, nameMovie)) //when searched name and the movie name from user is same
					{
						node *temp1;
						temp1 = head;
						while (nameMovie !=  temp1 -> movieName)
						{
							temp1 = temp1 -> next;

						}

						temp1 -> totalRating = (temp1 -> totalRating) + ratingMovie; //the totalrating must be the sum when it catches a movie name again
						temp1 -> numRatings++;
						cout << nameMovie << " has been updated." << endl;
					}
					else //when the movie name from the user is not in the list
					{
						node * temp2 = head;   

						if(head == NULL || nameMovie < head-> movieName)       
						{   
							node * temp = new node(nameMovie, ratingMovie, 1, head) ;  

							head =temp;
							cout << nameMovie << " has been added to the list." << endl;


						}

						else
						{
							while (temp2->next != NULL && temp2->next->movieName < nameMovie)
							{   
								temp2 = temp2->next;
							} 


							node * temp = new node(nameMovie, ratingMovie, 1, temp2 -> next);  

							temp2 ->next = temp;
							cout << nameMovie << " has been added to the list." << endl;
						}

					}

				}

			}
			cout <<endl;
			cout << "Movies from file " << fileName << " has been loaded. " << endl;




		}

		else if (option == 2) //adding a new rating manually
		{
			string movie_Name;
			int rating;
			cout << "Please enter the name of the movie you wish to rate:" ;
			cin >> movie_Name;
			cout << "Please enter the rating you wish to submit (1..10):" ;
			cin >> rating;
			if ( rating < 1 || rating > 10) //input check
			{
				cout << endl;
				cout << "You have entered an invalid rating." << endl;
			}

			else 
			{
				if(searchMovie(head, movie_Name)) // when the movie is in the list
				{
					node *temp1;
					temp1 = head;
					while (movie_Name !=  temp1 -> movieName)
					{
						temp1 = temp1 -> next;

					}

					temp1 -> totalRating = (temp1 -> totalRating) + rating; //updating the info of movie with the input from the user
					temp1 -> numRatings++;
					cout << movie_Name << " has been updated." << endl;
				}
				else // adding according to alphabetical order
				{
					node * temp2 = head; 
					if(head == NULL)
					{
						node * temp = new node(movie_Name, rating, 1, head) ;  

						head =temp;
						cout << movie_Name << " has been added to the list." << endl;

					}
					else
					{
						node * temp = new node(movie_Name, rating, 1, NULL);
						if (head -> movieName > movie_Name) //adding to beginning
						{
							temp -> next = head;
							head=temp;
							cout << movie_Name << " has been added to the list." << endl;
						}
						else
						{


							while(temp2 != NULL)
							{
								if(movie_Name > temp2 -> movieName && temp2 -> next -> movieName > movie_Name) //adding a place in the middles
								{
									node * temp = new node(movie_Name, rating, 1, temp2);
									temp -> next = temp2 -> next;
									temp2 -> next = temp;
									cout << movie_Name << " has been added to the list. " << endl;
									break;
								}
								if( temp2 -> next = NULL) //adding to end
								{
									temp2 -> next = temp;
									cout << movie_Name << " has been added to the list. " << endl;
									break;
								}


								temp2=temp2->next;

							}
						}
					}    
				}
			}
		}

		else if (option == 3) //removing an existing movie
		{
			string movie_Name;
			cout << "Please enter the name of the movie you wish to remove: " ;
			cin >> movie_Name;


			if(searchMovie(head, movie_Name)) // name of the movie must be in the list for removing
			{
				node *ptr = head;
				node *toBeDeleted = head -> next;
				if(ptr -> movieName == movie_Name) //when movie is the first
				{
					head = head->next;
					delete ptr;
				}
				else //when movie is not the first
				{
					while(toBeDeleted-> movieName != movie_Name)
					{
						toBeDeleted = toBeDeleted -> next;

						ptr = ptr -> next;
					}
					ptr -> next = toBeDeleted -> next;
					delete toBeDeleted;

				}
				cout << "Movie " << movie_Name << " has been removed from the list." << endl;
			}

			else // checking : movie name from the user is not in the list
			{
				cout << "Movie " << movie_Name << " does not exist." <<endl;
			}





		}

		else if (option == 4) //displaying the list of movies and rating information
		{
			showList(head); 
		}

		else //option 5 = exit
		{
			while(head != NULL)
			{
				node *temp = head;
				head = head -> next;
				delete temp;
			}
			return 0; 

		}


	} //paranthesis of the menu(option part) loop 
	cin.get();
	cin.ignore();
	return 0;


}












