//Martin Bassett
//12/4/22
//Discriminant mini-project
//C++ Honors FLHS



#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>



using namespace std;
using namespace winrt;
using namespace Windows::Foundation;


//Function headers
int findDiscriminant(int a, int b, int c, int discriminant);
string findSolution(int discriminant, string solution);

int main()
{
	//Variables
	int a, b, c, discriminant = 0;
	string solution;

	//Getting initial values
	cout << "Enter the a value: ";
	cin >> a;
	cout << "Enter the b value: ";
	cin >> b;
	cout << "Enter the c value: ";
	cin >> c;
	 
	//Call the functions
	discriminant = findDiscriminant(a, b, c, discriminant);
	solution = findSolution(discriminant, solution);

	//Output the polynomial
	//First coefficient
	if (a != 1 && a != -1) //Checks if the first coefficient is 1 or -1 since 1 shouldn't be written infront of x
		cout << "Your polynomial: " << a << "x^2";
	else if (a == 1)
		cout << "Your polynomial: x^2"; 
	else if (a == -1)
		cout << "Your polynomial: -x^2"; 
	//Second coefficient
	if (b != 1 && b != -1) //Checks if the second  coefficient is 1 or -1 since 1 shouldn't be written infront of x
	{
		if (b > 0) //Check if the second coefficient is positive or negative; if negative then don't put "+" sign in the equation
			cout << "+" << b << "x";
		else if (b < 0)
			cout << b << "x";
	}
	else
	{
		if (b == 1) //Check if the second coefficient is positive or negative; if negative then don't put "+" sign in the equation
			cout << "+x";
		else if (b == -1)
			cout << "-x";
	}
	if (c > 0) //Check if the third coefficient is positive or negative; if negative then don't put "+" sign in the equation
		cout << "+" << c << endl;
	else if (c < 0)
		cout << c << endl;

	//Output final information
	cout << "The discriminant of your polynomial is " << discriminant << endl;
	cout << "Your polynomial has " << solution << endl;
	system("Pause");
	return 0;
}

int findDiscriminant(int a, int b, int c, int discriminant) //Functiion definition
{
	//Find the discriminant
	discriminant = (pow(b, 2) - (4 * a * c));
	return discriminant; //Returns the discriminant
}

string findSolution(int discriminant, string solution) //Functiion definition
{
	//Finds the amount of roots based on the value of the discriminant
	if (discriminant > 0)
		solution = "two real roots";
	else if (discriminant == 0)
		solution = "one repeated root";
	else
		solution = "no real roots";
	return solution; //Returns the amount of roots
}