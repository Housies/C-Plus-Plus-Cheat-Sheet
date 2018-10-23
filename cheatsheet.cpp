#include <iostream> // this allows input and output, things like printing strings to the console
#include <vector> // this allows vectors
#include <algorithm> // this allows sorting vectors
#include "add.h" // includes my header and allows separate compilation. Look at "add.h" and "add.cpp" to see the function this imports. Compile them both with "g++ cheatsheet.cpp add.cpp -o cheatsheet"

using std::cout; // these mean I don't have to type "std::" before every standard library feature
using std::endl;

// If you're just using this script, this program can be compiled with "g++ cheatsheet.cpp -o cheatsheet". If you're using this script and "add.cpp" (you need it unless you comment out the add function), this program can be compiled with "g++ cheatsheet.cpp add.cpp -o cheatsheet". In either case, the resulting executable can be run with "./cheatsheet" on Linux

int myfunction(int firstnumber, int secondnumber, std::string stringtoprint) { // a function with variables passed to it
	std::cout << stringtoprint << std::endl;
	int result = firstnumber + secondnumber;
	return result; // returning from a function
}

int myfunction(int input, int& mynumberreference) { // this is an overloaded function because it has the same name as the other function. It works because the last variable (I think) is a different type (a reference that it modifes in order to modify the variable the reference points to)
// note: in passing a variable to a function in the normal way, it copies the whole thing. This is computationally expensive. If it's a large variable, like a string or vector, and the function doesn't modify it, it might be better to use "const" with a reference. (like the reference above) This doesn't copy the whole thing and reduces overhead

	mynumberreference += 26;
	return 0;
}

int arrayfunction(int twod[2][3]) { // a function with a two dimensional array passed to it
	std::cout << twod << std::endl;
	return 0;
}

struct mydatastructure { // this is a data structure
	int mynumber;
	std::string mystring;
}; // the semicolon is required after a data structure for some reason

int main() { // this is the main function. Every program needs this, except programs that are used in another program via a header

	cout << "This is a string written to the console, making use of the \"using\" statements above" << endl; // from this point on I'll use "std::" every time for clarity, although you should remember that you don't have to if you put the "using" statements above
	std::cout << "This is what the line would look like if I didn't use the \"using\" statements above" << std::endl; // notice the quotes that have been escaped with backslashes

	std::cout << "This is a line with no line break at the end";
	std::cout << "New line in the program" << std::endl;

	int mynumber; // declaring a variable
	mynumber = 7; // giving that variable a value

	std::string mystring = "this is my string"; // declaring a variable and giving it a value in one line

	const int constantnumber = 4; // a constant variable. Making it constant is saying that we don't intend to change it. It doesn't affect the code, but does make it more readable. A constant variable has to be given a value as it's declared, because it shouldn't be changed later

	int maths = (mynumber + constantnumber) * 2; // doing maths with my variables

	std::cout << maths << std::endl; // printing my maths

	std::cout << mystring + " more string" << std::endl; // concatenating strings

	int functionreturn = myfunction(mynumber, 24, "This string was printed from a function"); // calling a function and passing variables to it

	std::cout << functionreturn << std::endl; // printing the result from the function

	std::vector<std::string> myvector; // creating a vector that's going to contain strings

	int count = 0; // yet another variable

	std::string stringtoadd; // declaring a string variable

	while (count != 4) { // a while loop
		std::cout << count << std::endl;
		stringtoadd = std::to_string(count); // converting an integer to a string
		myvector.push_back("somestring" + stringtoadd); // adding something to a vector
		++count; // increments count by one
	}

	count += 8; // adding to a variable in place

	std::sort(myvector.begin(), myvector.end()); // this sorts the vector in nondecreasing order (in this case it doesn't change anything)

	for (int n = 0; n != 4; ++n) { // a for loop
		std::cout << myvector[n] << std::endl; // getting a particular item from a vector and printing it

		if (myvector[n] == "somestring2" && "astring" != "differentstring") { // an if statement with an and
			std::cout << "The first if statement is true" << std::endl;

			if (true == false || true == true) { // a nested if statement with an or
				std::cout << "The first nested if statement is true" << std::endl;
			}

		} else if (2 > 1) { // an else if statement with a "greater than" operator
			std::cout << "The first statement is not true, but the first else if is" << std::endl;

		} else { // an else statement
			std::cout << "Neither of the first two statements are true" << std::endl;
		}
	}

	for (int n = 0; n < 50; n += 6) { // a for loop, but in steps
		std::cout << n << std::endl;
	}

	for (int n = 4; n != 0; --n) // a for loop going backwards. Notice how it doens't need the curly braces because it only contains one statement
		std::cout << n << std::endl;

	int ifstatement = 4 > 2 ? 6 : 8; // I'm not sure what it's called, but this is like a one line if statement. If the condition before the question mark is true, the variable is the thing on the left of the colon. If it's not, the variable is the thing on the right of the colon. I'm not very good at explaining things

	std::cout << ifstatement << std::endl;

	std::string multiplyliteral(8, 'h'); // this multiplies a character literal (one character only between two single quotes) by 8
	std::cout << multiplyliteral << std::endl;

	std::cout << "Type your name here: "; // prints a line to the console without a new line, prompting the user to type something

	std::string name;
	std::cin >> name; // this takes whatever was typed into the console and puts it in a variable

	std::cout << "Hello, " + name << std::endl;

	if (false) {
		throw std::domain_error("This is an exception"); // throwing an exception, in an if statement so it doesn't stop the rest of the program
	}

	int& mynumberreference = mynumber; // a reference. Anything that is done to "mynumberreference" will also be done to "mynumber"

	myfunction(3, mynumberreference); // this calls the second function, passing the reference I just made. This means that the function modifies the "mynumber" variable the reference points to

	std::cout << "mynumber is " + std::to_string(mynumber) << std::endl; // prints "mynumber" to show that it's changed

	try { // a try and catch statement
		std::cout << "This is a try" << std::endl;
	} catch(int) {
		std::cout << "This is a catch" << std::endl;
	}

	mydatastructure dobby; // using my data structure, creating an instance of it with the name "dobby"
	dobby.mynumber = 6;
	std::cout << dobby.mynumber << std::endl;

	std::cout << add(4, 3) << std::endl; // uses a function from the other file

	for (int n = 0; n != 10; ++n) {
		if (n == 4) {
			continue; // a continue statement. If used, skips the rest of the current iteration of the loop and starts the next one
		}
		if (n == 6) {
			break; // a break statement. If used, exits the current loop
		}
		std::cout << n << std::endl;
	}

	int switchconstant = 6;

	switch (switchconstant) { // this is a switch statement. It is preferable to an if...else if... for checking the value of a single variable
		case 2:
			std::cout << "The constant is 2" << std::endl;
			break; // this is needed. Without it, it executes every case after the correct one
		case 4:
			std::cout << "The constant is 4" << std::endl;
			break;
		case 6:
			std::cout << "The constant is 6" << std::endl;
			break;
		default:
			std::cout << "The constant is unknown" << std::endl;
	}

	goto gotodestination; // this is a goto. It jumps to the line with "gotodestination:". It's bad practice and should be avoided if possible

	std::cout << "Text between goto and destination" << std::endl;

	gotodestination: // the goto's destination
	std::cout << "Text after goto destinaiton" << std::endl;

	int numbers[6] = {2, 4, 6, 8, 10, 12}; // an array with 6 elements
	std::cout << "Element number 3 of my array is " + std::to_string(numbers[3]) << std::endl;

	int twod[2][3] = {	{2, 4, 6}, // a two dimensional array, with the new line for clarity (you can have more dimensions)
						{8, 10, 12}};

	for (int first = 0; first != 2; ++first) {
		std::cout << "The first dimension is " + std::to_string(first) << std::endl;
		for (int second = 0; second != 3; ++second) {
			std::cout << "The second dimension is " + std::to_string(second) << std::endl;
			std::cout << "The corresponding array element is " + std::to_string(twod[first][second]) << std::endl; // getting the corresponding element from the two dimensional array
		}
	}

	arrayfunction(twod); // passing a two dimensional array to a function

	double mydouble = 3.841592653589793; // a double. It allows decimals, but is prone to innacuracy
	int myint = mydouble; // this converts a double to an integer. Notice how it rounds it to three even though it's closer to four
	std::cout << myint << std::endl;

	std::cout << mystring[12] << std::endl; // this displays one particular character from a string

	for (int n : numbers) { // this is a loop that goes through an array
		std::cout << n << std::endl;
	}

	return 0; // this returns from the main function. The zero means it completed successfully. Anything else would mean it failed
}