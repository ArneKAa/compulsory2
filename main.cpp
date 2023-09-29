#include <iostream>
#include <string>

using namespace std;

int arraySum[4];	//globally saved arrays (had memory leak issues when using pointers that I didn't have time to fix)
int arrayProduct[7];
int arrayPoly[4];
int arrayPoly2[4];
string arrayabcd[4] = { "a", "b", "c", "d" };

int calcStart(); //defining the function early so that I can restart the calculation in calc()

/// Input for operator and second number, outputs answer, check if you want to continue, restart, or exit calculation
int calc(double number) {

	double number2;
	char operation;
	bool loop = true; // this boolean is used in a lot of my functions for error handling
	double answer;
	char calcRecursion;

	do {
		cout << "\nChoose an operation (+, -, *, /) ";
		cin >> operation;
		if (operation == '+' || operation == '-' || operation == '*' || operation == '/') { //ask for operation which is stored as char
			loop = false; //I set loop to false when user has put the right kind of input, which allows for user to exit loop
		}
		else if (cin.fail()) { //this is the error handling I use for when I ask for an int and am not given an int
			cin.clear();	//it is not fool proof
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (loop);

	do {
		loop = true;
		cout << "Choose a number "; // ask for second number in calculation (first number is chosen in calcStart())
		cin >> number2;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			loop = false;
		}
	} while (loop);

	if (operation == '+') {
		answer = number + number2; //here the calculation is done based on operation chosen
	}
	if (operation == '-') {
		answer = number - number2;
	}
	if (operation == '*') {
		answer = number * number2;
	}
	if (operation == '/') {
		answer = number / number2;
	}

	cout << endl << number << " " << operation << " " << number2 << " = " << answer; //prints problem and its answer

	do { //ask whether to continue or redo calculation, or go back to menu

		loop = true;
		cout << "\nContinue calculation, restart calculation, or exit? (c/r/e) ";
		cin >> calcRecursion;

		if (calcRecursion == 'c' || calcRecursion == 'r' || calcRecursion == 'e') {
			loop = false;
		}
		else if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	} while (loop);

	if (calcRecursion == 'c') { //recursion occurs using answer as argument instead of number1 from calcStart()
		calc(answer);
	}
	if (calcRecursion == 'r') { //goes to calcStart() to restart calculation
		calcStart();
	}

	return 0;
}

/// Start of calculations. Gets unput for first number which it uses as an argument into calc()
int calcStart() {

	double number;
	cout << "Choose a number "; 
	cin >> number; //asks for first number in calculation
	calc(number); //enters calc with first number as argument
	cout << "\n\n"
	return 0;
}

/// Calculation of factorial
unsigned long long int factorial(int number) {
	if (number == 0 || number == 1) { //factorial of 1 and 0 is 1, and ends chain of recursion if original number was higher than 1
		return 1;
	}										//a factorial of a number is itself times the factorial of the number below it
	return number * factorial(number - 1); //using this logic I can calculate factorials using recursion
}											//althogh a loop would have been more effective

/// Input for factorial, runs factorial()
int factorialStart() {
	int input;
	bool loop = true;
	do {
		cout << "\nChoose a number to calculate the factorial of (max 20): "; 
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (input < 21 && input >= 0) { //20 is the max my program can do with unsigned long long int
			loop = false;
		}
	} while (loop);
	cout << "\n" << input << "!" << " = " << factorial(input) << "\n\n\n"; //prints answer
	return 0;
}

///Prints product
int writeProduct() {

	bool printX = false; //Boolean for if something has been printed yet, don't want to print '+' after nothing
	cout << "\n\nThe product of your polynomials is\n\n";

	for (int i = 0; i < 7; i++) { //product of 2 polynomials to the 3rd degree is expected to have 7 values

		if (arrayProduct[i] != 0) {	//don't want to print anything if my coefficient of constant is 0
			if ((arrayProduct[i] != -1 && arrayProduct[i] != 1) || i == 6) { //dont want to write "1" if it's a coefficient
				cout << arrayProduct[i];
			}
			if (arrayProduct[i] == -1 && i != 6) { //code above forces me to add a minus if value is -1
				cout << "-";
			}
			if (i < 5) {					//manual code for before next to last iteration (by manual I mean I could've
				cout << "x^" << 7 - (i + 1) << " ";//written "if (i < arraySize - 2)" if I had an arraySize
			}
			if (i == 5) { // manual code for next to last iteration
				cout << "x ";
			}
			printX = true;
		}

		if (i != 6 && arrayProduct[i + 1] > 0 && printX == true) { //manual code for all except last iteration
			cout << "+ ";											//as well as checking next number is above 0, or that
		}															//nothing has been printed yet
	}

	return 0;
}

///Prints first polynomial
int writePoly() { //copy paste from writeProduct() with small edits

	bool printX = false;

	cout << "\n\nYour chosen polynomials are\n\n";

	for (int i = 0; i < 4; i++) {

		if (arrayPoly[i] != 0) {

			if ((arrayPoly[i] != -1 && arrayPoly[i] != 1) || i == 3) {
				cout << arrayPoly[i];
			}
			if (arrayPoly[i] == -1 && i != 3) {
				cout << "-";
			}
			if (i < 2) {
				cout << "x^" << 4 - (i + 1) << " ";
			}
			if (i == 2) {
				cout << "x ";
			}
			printX = true;
		}

		if (i != 3 && arrayPoly[i + 1] > 0 && printX == true) {
			cout << "+ ";
		}
	}
	return 0;
}

///Prints second polynomial
int writePoly2() { //copy paste from writeProduct() with small edits

	bool printX = false;

	cout << "\n\nAnd\n\n";

	for (int i = 0; i < 4; i++) {

		if (arrayPoly2[i] != 0) {
			if ((arrayPoly2[i] != -1 && arrayPoly2[i] != 1) || i == 3) {
				cout << arrayPoly2[i];
			}
			if (arrayPoly2[i] == -1 && i != 3) {
				cout << "-";
			}
			if (i < 2) {
				cout << "x^" << 4 - (i + 1) << " ";
			}
			if (i == 2) {
				cout << "x ";
			}
			printX = true;
		}
		if (i != 3 && arrayPoly2[i + 1] > 0 && printX == true) {
			cout << "+ ";
		}
	}
	return 0;
}

///Prints som or difference
int writePolySum() { //copy paste from writeProduct() with small edits

	bool printX = false;

	cout << "of your polynomials is\n\n";

	for (int i = 0; i < 4; i++) {

		if (arraySum[i] != 0) {
			if ((arraySum[i] != -1 && arraySum[i] != 1) || i == 3) {
				cout << arraySum[i];
			}
			if (arraySum[i] == -1 && i != 3) {
				cout << "-";
			}
			if (i < 2) {
				cout << "x^" << 4 - (i + 1) << " ";
			}
			if (i == 2) {
				cout << "x ";
			}
			printX = true;
		}
		if (i != 3 && arraySum[i + 1] > 0 && printX == true) {
			cout << "+ ";
		}
	}
	return 0;
}

///Creates values for arrayPoly
int createPoly() {

	cout << "\n\nFor the first polynomial";

	for (int i = 0; i < 4; i++) {//looping through already saved array and asking user for input
		if (i == 3) { //checking for last iteration because last iteration is a constant
			cout << "\nChoose value of constant " << arrayabcd[i] << endl;
		}
		else {
			cout << "\nChoose value of coefficient " << arrayabcd[i] << endl;
		}
		cin >> arrayPoly[i];
	}
	return 0;
}

///Creates values for arrayPoly2
int createPoly2() { //copy paste from createPoly()

	cout << "\n\nFor the second polynomial";

	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			cout << "\nChoose value of constant " << arrayabcd[i] << endl;
		}
		else {
			cout << "\nChoose value of coefficient " << arrayabcd[i] << endl;
		}
		cin >> arrayPoly2[i];
	}

	return 0;
}

///Function for adding polynomials together
int addPoly() {

	createPoly();
	createPoly2();

	for (int i = 0; i < 4; i++) { //takes the 2 polynomials given by user and adds each correlating coefficient/constant together
		arraySum[i] = arrayPoly[i] + arrayPoly2[i];
	}

	writePoly(); //print
	writePoly2();
	cout << "\n\nThe sum ";
	writePolySum();
	cout << "\n\n";

	return 0;
}

///function for multiplying polynomials with each other
int multiplyPoly() {

	createPoly();
	createPoly2();

	for (int i = 0; i < 4; i++) { //collects correlating coeffiecients backwards from how humans would do it on paper
		for (int j = 0; j < 4; j++) { //(j+i creating the correlating coefficients) and adds them together
			arrayProduct[j + i] += arrayPoly[i] * arrayPoly2[j];
		}
	}
	
	writePoly();
	writePoly2();
	writeProduct();
	cout << "\n\n";

	return 0;
}

///function for finding the difference between 2 polynomials
int subtractPoly() { //copy paste from addPoly(), changing plus to minus

	createPoly();
	createPoly2();

	for (int i = 0; i < 4; i++) {
		arraySum[i] = arrayPoly[i] - arrayPoly2[i];
	}

	writePoly();
	writePoly2();
	cout << "\n\nThe difference ";
	writePolySum();
	cout << "\n\n";

	return 0;
}

int main() {

	int input;

	do {//switch case menu

		cout << "Please select an option from the following selection of options:\n";
		cout << "[1] Multiply polynomials together\n";
		cout << "[2] Add polynomials together\n";
		cout << "[3] Subtract polynomial from another\n";
		cout << "[4] Calculator\n";
		cout << "[5] Factorial of a number\n";
		cout << "[6] Exit program\n";
		cin >> input;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (input) {

		case 1:
			multiplyPoly();
			break;

		case 2:
			addPoly();
			break;

		case 3:
			subtractPoly();
			break;

		case 4:
			calcStart();
			break;

		case 5:
			factorialStart();
			break;

		case 6:
			return 0;
		}

	} while (true);

	return 0;
}