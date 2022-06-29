// Tanner Boswell
// MergeSort

// This program reads in the words from a data file and puts them into an array of strings. It then mergesorts those words alphabetically and prints the sorted list in a chart of five columns.

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes needed for mergesort

// Function that helps split the sections of data
void mergesort(string A[], int start, int end, string temp[]);

// Function that merges specific sections of data
void merge(string A[], int leftfirst, int leftlast, int rightfirst, int rightlast, string temp[]);

// Function that checks if the first string (word) is less than the second string (word)
bool operator<(string s1, string s2);

int main() {

	// Temporary string used for mergesort
	static string temp[1000];

	bool run = true;

	// Character array that holds the input file name
	char inputFileName[150];

	// String array that holds the words from the file
	string words[1000];

	// Integer that represents the number of words
	int numofwords = 0;

	// Integer used to create columns
	int column = 0;

	ofstream outFile1;
	ifstream inFile1;


	// Introduces the program

	cout << "Welcome to the sorting words program.\n";

	// Prompts the user to enter an input file and loops until it finds a valid file
	while (run)
	{
		cout << "Please enter the name of your INPUT data file: ";
		cin >> inputFileName;


		inFile1.open(inputFileName);

		if (inFile1.fail())
		{
			cout << "(ERROR - FAILED TO OPEN FILE). \n";
			cout << "Please try again. \n \n";

		}
		else
		{
			cout << "(SUCCESSFULLY OPENED FILE) \n \n";
			run = false;
		}
	}

	// Assures the user that the program will begin to read in from the input file
	cout << "Reading Players From: " << inputFileName << "\n";

	// Begins to read in from the input file while keeping count of the quantity of words
	for (int num = 0; !inFile1.eof(); num++)
	{
		inFile1 >> words[num];
		numofwords++;

	}

	// Tells the reader how many words were in the file
	cout << numofwords << " words were read in from the file.";

	// Calls the mergesort function
	mergesort(words, 0, numofwords - 1, temp);

	// Sorts the sorted list into five columns
	cout << "\n \nSORTED WITH MERGESORT:\n\n";
	for (int i = 0; i < numofwords; i++)
	{
		// once the column variable reaches five, it restarts and prints a new line
		if (column == 5)
		{
			cout << "\n";
			column = 0;
		}
		cout << right << setw(8) << words[i] << ", ";
		column++;
	}

	cout << "\n \n";

	// Closes all files that were used in the program
	inFile1.close();

	cout << "End of program\n\n";
	return 0;
}


// Function that splits sections of the data file to merge
void mergesort(string wordlist[], int start, int end, string temp[])
{
	int middle;
	if (start < end)
	{
		// Finds middle
		middle = (start + end) / 2;

		// Calls itself to merge/divide left side
		mergesort(wordlist, start, middle, temp);

		// Calls itself to merge/divide right side
		mergesort(wordlist, middle + 1, end, temp);

		// calls merge function to merge in correct order
		merge(wordlist, start, middle, middle + 1, end, temp);
	}
};

// Function that merges and orders divided sections
void merge(string wordlist[], int leftfirst, int leftlast, int rightfirst, int rightlast, string temp[])
{
	// variables to keep the positions of the divided sections
	int i = leftfirst;
	int save = leftfirst;
	while (leftfirst <= leftlast && rightfirst <= rightlast)
	{
		// If the left first word is less then the right first
		if (operator<(wordlist[leftfirst], wordlist[rightfirst]))
		{
			// Temporary position becomes the left first position
			temp[i] = wordlist[leftfirst];
			leftfirst++;
		}
		else
		{
			// Temporary position becomes the right first postion
			temp[i] = wordlist[rightfirst];
			rightfirst++;
		}
		i++;
	}
	// While not out of words on the left side
	while (leftfirst <= leftlast)
	{
		// increase temporary postion
		temp[i] = wordlist[leftfirst];
		leftfirst++;
		i++;
	}
	// While not out of words on the right side
	while (rightfirst <= rightlast)
	{
		// increase temporary position
		temp[i] = wordlist[rightfirst];
		rightfirst++;
		i++;
	}
	// Goes through the list to assign temporary words to word array
	for (i = save; i <= rightlast; i++)
	{
		wordlist[i] = temp[i];
	}
};

// Function that checks if the first words is less than the second word (case insensitive)
bool operator<(string s1, string s2)
{
	// Variable that holds the smallest word's size in the individual comparison
	int maximumSize;

	// Variable that holds the position of the letters in the words
	int letter1, letter2;

	// Boolean that returns true if string 2 is longer
	bool s2longer;

	if (s1.size() < s2.size())
	{
		// If string 1 is less than, assign it's size to the maximum size
		maximumSize = s1.size();
		s2longer = true;
	}
	else
	{
		// If string 2 is less than, assign it's size to the maximum size
		maximumSize = s2.size();
		s2longer = false;
	}

	// Enters a loop to compare each letter of the two words
	for (int i = 0; i < maximumSize; i++)
	{
		letter1 = tolower(s1[i]);
		letter2 = tolower(s2[i]);
		if (letter2 < letter1)
		{
			return false;
		}
		else if (letter2 > letter1)
		{
			return true;
		}
		// If the letters match until the maximum size, test to see which is longer
	}
	if (s2longer)
	{
		return true;
	}
	else
	{
		return false;
	}

};