#include <iostream>
#include "Cubic.h"
#include "Polynomial.h"
using namespace std;

int main() {
	// Cubic class testing
	// Two identical cubics
	Cubic c1(4, 2, 5, 8);
	Cubic c2(4, 2, 5, 8);

	// Equality should return 1 (true) and inequality 0 (false)
	cout << "Result of comparison was: " << (c1 == c2) << " (Should be 1)" << endl;
	cout << "Result of comparison was: " << (c1 != c2) << " (Should be 0)" << endl;

	double result, resultExpected;
	// Compute c1 when x is 2 (should be 546)
	result = c1.computeValue(2);
	cout << "When x = 2 " << c1 << " resolves to " << result << endl;

	Cubic c3(5, 3, 6, 8);
	Cubic c4(3, 6, 4, 9);

	// Add c3 and c4
	cout << c3 << " + " << c4 << " = " << c3 + c4 << endl;

	// Subtract c4 from c3
	cout << c3 << " - " << c4 << " = " << c3 - c4 << endl;

	// Multiply c3 by 3
	cout << c3 << " * " << " 3 " << " = " << c3 * 3 << endl;

	// Multiply c4 by 0.5
	cout << c4 << " * " << " 0.5 " << " = " << c3 * 0.5 << endl;

	// Default constructor - initialises to (1, 1, 1, 1)
	Cubic updateTest;
	Cubic c6(2, 5, 1, 3);
	// Take updateTest, add c6 to it and store the updated value
	updateTest += c6;
	Cubic updateTestExpected1(3, 6, 2, 4);
	cout << updateTest << " += " << c6 << " = " << updateTest << endl;
	// Take updateTest, subtract c6 from it and store the updated value (returning it to its original value)
	updateTest -= c6;
	cout << updateTest << " -= " << c6 << " = " << updateTest << endl;

	// Print cubics used in the tests
	cout << "Some cubics: " << "\n" << c1 << "\n" << c2 << "\n" << c3 << endl;

	// Input cubics
	Cubic userIn;
	cout << "Please enter a cubic (ax^3+bx^2+cx+d). Enter your values for a, b, c and d seperated by commas." << endl;
	cin >> userIn;
	cout << "You entered: " << userIn << endl;

	// Polynomial class testing

	// I/O Operators testing
	// Input testing
	Polynomial* p1 = new Polynomial(4);
	cout << "Please enter coefficients for a polynomial of degree 4 (5 arguments) seperated by a comma" << endl;
	cin >> *p1;
	Polynomial* p2 = new Polynomial(2);
	cout << "Please enter coefficients for a polynomial of degree 2 (3 arguments) seperated by a comma" << endl;
	cin >> *p2;
	Polynomial* p3 = new Polynomial(2);
	cout << "Please enter coefficients for another polynomial of degree 2 (3 arguments) seperated by a comma" << endl;
	cin >> *p3;
	// Output testing
	cout << "You entered: " << *p1 << endl;
	cout << "You entered: " << *p2 << endl;
	cout << "You entered: " << *p3 << endl;

	// Arithmetic operators testing
	// Addition
	// Different degrees
	cout << *p1 << " + " << *p2 << " = " << *p1 + *p2 << endl;
	cout << *p2 << " + " << *p1 << " = " << *p2 + *p1 << endl;
	// Same degree
	cout << *p2 << " + " << *p3 << " = " << *p2 + *p3 << endl;
	// Subtract
	// Different degrees
	cout << *p1 << " - " << *p2 << " = " << *p1 - *p2 << endl;
	cout << *p2 << " - " << *p1 << " = " << *p2 - *p1 << endl;
	// Same degree
	cout << *p2 << " - " << *p3 << " = " << *p2 - *p3 << endl << "\n";
	// Polynomial multiplication
	// Different degrees
	cout << *p1 << " * " << *p2 << " = " << *p1 * *p2 << endl;
	cout << *p2 << " * " << *p1 << " = " << *p2 * *p1 << endl;
	// Same degree
	cout << *p2 << " * " << *p3 << " = " << *p2 * *p3 << endl;
	// Integer multiplication
	cout << *p1 << " * " << "2" << " = " << *p1 * 2 << endl;
	// Double multiplication
	cout << *p1 << " * " << "0.5" << " = " << *p1 * 0.5 << endl << "\n";

	// Comparison operators testing
	// Equality tests should return opposite values
	cout << *p1 << " equal to? " << *p2 << " returns " << (*p1 == *p2) << endl;
	cout << *p1 << " not equal to? " << *p2 << " returns " << (*p1 != *p2) << endl << "\n";

	// Copy constructor testing
	Polynomial* p4 = new Polynomial(*p3);
	cout << "p4 should be the same as: " << *p3 << endl;
	cout << "p4 is: " << *p4 << endl << "\n";

	// Destructor testing
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	// Update operator testing
	// 2x^2+1x+4
	Polynomial* p5 = new Polynomial(2);
	p5->setCoefficient(2, 2);
	p5->setCoefficient(1, 1);
	p5->setCoefficient(4, 0);

	// x^3+3x^2+2x+7
	Polynomial* p6 = new Polynomial(3);
	p6->setCoefficient(1, 3);
	p6->setCoefficient(3, 2);
	p6->setCoefficient(2, 1);
	p6->setCoefficient(7, 0);

	cout << "p5 is: " << *p5 << endl;
	cout << "p6 is: " << *p6 << endl;
	// += testing (should be x^3+5x^2+3x+11)
	*p5 += *p6;
	cout << "p5 += p6 is: " << *p5 << endl;
	// -= testing (should be back to original value of p5)
	*p5 -= *p6;
	cout << "p5 -= p6 is: " << *p5 << endl;
	// *= testing (should be 2x^5+7x^4+11x^3+28x^2+15x+28)
	*p5 *= *p6;
	cout << "p5 *= p6 is: " << *p5 << endl;

 	return 0;
}