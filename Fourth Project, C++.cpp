#include <iostream>
#include <math.h>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

/*
Take 1: Write a function that accepts a matrix, its number of rows and columns, and the position of an element in the matrix (row and column number). The function must return true if a number in place (the member) [i][j] is greater than all of its neighbors in the matrix (neighbors to the right, to the left, from below, from below and diagonally). Also, there should be no overflow from the matrix boundaries. If not - returns false.
The function title is
bool is_peak (int a[][5], int rows,int cols,int i,int j)
For example: a matrix with 5 rows and 5 columns

10 1 4 16 26
5 12 5 14 12
6 2 8 3 25
12 4 5 12 10
8 6 5 22 18

A term in place of 0=i, 4=j is -26 - the output is true.
A term in the place 3=i, 4=j is -10 - the output is false.
*/
#define ROWS 5 // Set number of lines 
#define COLS 5 // Setting the number of columns

void get_matrix(int a[][COLS], int rows, int cols) // A function to define a matrix 
{
	srand((int)time(0)); // Defining a random matrix 
	for (int i = 0; i < rows; i++) // First loop to the matrix 
	{
		for (int j = 0; j < cols; j++) // A second loop for the matrix 
		{
			a[i][j] = rand() % 20; // Setting a limit for the numbers in the matrix 
		}

	}
}
void print_matrix(int a[][COLS], int rows, int cols) // A function to print a matrix 
{
	for (int i = 0; i < rows; i++) // First loop to the matrix 
	{
		for (int j = 0; j < cols; j++) // A second loop for the matrix 
		{
			cout << setw(5) << a[i][j]; // matrix printing
		}
		cout << endl;
	}
}

bool is_peak(int  a[][5], int rows, int cols, int i, int j)

{
	for (int x = i - 1; x <= i + 1; x++) // A loop for checking neighboring rows 
	{
		for (int y = j - 1; y <= j + 1; y++)  // A loop for checking neighbor columns 
		{
			if ((x >= 0) && (x <= rows) && (y >= 0) && (y <= cols)) // Setting the four conditions to not go out of bounds in the matrix 
				if (a[i][j] < a[x][y]) // Setting a condition greater than the other neighbors - if not, return no
				{
					return false;
				}
		}

	}
	return true;
}


void get_is_peak()
{
	int mat[ROWS][COLS]; // Array definition 
	get_matrix(mat, ROWS, COLS); // Call to function 1
	print_matrix(mat, ROWS, COLS); // Call to function 2
	int i = 0, j = 0; // Defining variables for rows and columns
	cout << "Please enter index in matrix:" << endl; // Output definition
	cout << "Please enter number row Luba (0-4): "; // Output definition
	cin >> i; // Column variable - output
	cout << "Please enter number colum Luba (0-4): "; // Output definition
	cin >> j; // row variable - output

	if (is_peak(mat, ROWS, COLS, i, j)) // Condition for return is your number is greater than all the neighbors
		cout << "Your numbrer is the biggest from all is neighbors." << endl;
	else
		cout << "Sorry, but there is some neighbors that is bigger from your number." << endl;
}

/*
 Second take:write a function that accepts as input a string of characters, which has a number with a decimal point, and check if the digits
that after the decimal point appear in the same order as the digits before it, so the function returns true,
otherwise it returns false.
Input 2345.234, output, false: Example: input 2345.2345, output true.
*/

bool beforEqAfter(string str) 
{
	{
		int x = 0; // Variable definition 1
		int y = 1 + str.length() / 2; // Setting variable 2 to the second part after the dot
		for (x = 0; x < (str.length() / 2); x++, y++) //A loop to check the condition later 
		{
			if (str[x] != str[y]) //A condition for checking whether the second part of the number is equal to the second part after the point
				return false; // If the condition is not met
		}
	}
	return true; // If the condition is met
}

void get_beforEqAfter()

{
	string str1; // Defining a variable of type string
	cout << "Please enter your number:" << endl; // Output definition
	cin >> str1;  // Input to check the mother number is symmetrical
	if (beforEqAfter(str1) == false) // Calling the function to check if the condition is met and the second part of the number is equal to the second part
	{
		cout << "The word is NOT simetric." << endl; // If your number is indeed symmetrical
	}
	else if (beforEqAfter(str1) == true)  //Calling the function to check if the condition is met and the second part of the number is equal to the second part
	{
		cout << "The word IS simetric - true." << endl; // If your number is not symmetrical
	}
}


/*
Take 3: Write a function that accepts two strings a and b and returns a string that contains the elements of string a that do not occur in b.
string diff(string a, string b){…}
Example: input: b="abvd", a="abcd",
output "c"
  Input: b="abcde", a="abcd",
Output: ""
  Input: b="mngk", a="abcd",
output: "abcd"
*/

string diff(string a, string b)
{
	string strA = ""; // Defining a variable of type string 
	int lenA = a.length(); // Variable definition a 
	int lenB = b.length(); // Variable definition b 

	for (int i = 0; i < lenA; i++) // Setting up a test loop 
		if (b.find(a[i]) == (-1)) // A condition to check whether there is a part in number A that is equal to part B
			strA = strA + a[i];

	return strA;
}
void get_is_diff() // Function of task 3
{
	string s1, s2; // Defining two variables of type string
	cout << "Enter 2 string to Diff operation:\n"; // Output definition

	cout << "s1: "; // Setting an output to receive a variable 
	cin >> s1;// Setting an input to receive a variable 

	cout << "s2: "; // Setting an output to receive a variable  
	cin >> s2; // Setting an input to receive a variable 

	cout << "The Diff string is: " << diff(s1, s2) << endl; // Finish a line

}



int main() // Main function for running the program
{

	//Opening messages
	cout << "Matala_04 by Ariel Topaz\n\n";
	cout << "Choose opertion from the menu below\n\n";

	int opCod = 0;
	do
	{
		//menu
		cout << endl
			<< "Menu:\n"
			<< "0. for  exit\n"
			<< "1. get_is_peak\n"
			<< "2. get_beforEqAfter\n"
			<< "3. get_is_diff\n"
			<< "Enter your choice:\n";
		cin >> opCod; // Using functions to define the three exercises for convenience and using the menu
		switch (opCod)
		{
		case 1:
			get_is_peak();
			break;

		case 2:
			get_beforEqAfter();
			break;

		case 3:
			get_is_diff();
			break;

		case 0:
			cout << "Exiting The Progtam, have a nice day." << endl << endl << endl << endl;//exit messeg
			break;

		default:
			cout << "Invloid opertion cod" << endl << endl;//eror messeg for invalid input
		}
	} while (opCod != 0);

	return 0;

}
