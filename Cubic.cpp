#include "Cubic.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructors
Cubic::Cubic() {
	// Default constructor, initialise to all 1's
	x3Coefficient = 1;
	x2Coefficient = 1;
	xCoefficient = 1;
	constantVal = 1;
}

Cubic::Cubic(double x3, double x2, double x, double c) {
	x3Coefficient = x3;
	x2Coefficient = x2;
	xCoefficient = x;
	constantVal = c;
}

// Member functions
double Cubic::computeValue(double xval) const {
	return pow((xval * x3Coefficient), 3) + pow((xval * x2Coefficient), 2) + (xval * xCoefficient) + constantVal;
}

// Returns the desired coefficient
double Cubic::getCoefficient(int degree) const {
	switch (degree) {
	case 3: 
		return x3Coefficient;
	case 2: 
		return x2Coefficient;
	case 1: 
		return xCoefficient;
	case 0: 
		return constantVal;
	default: // Invalid degree 
		return -1;
	}
}

// Sets the desired coefficient
void Cubic::setCoefficient(double val, int degree) {
	switch (degree) {
	case 3: x3Coefficient = val;
		return;
	case 2: x2Coefficient = val;
		return;
	case 1: xCoefficient = val;
		return;
	case 0: constantVal = val;
		return;
	default: // Invalid degree
		return;
	}
}

// Arithmetic operators
Cubic Cubic::operator+(Cubic rhs) {
	Cubic result((x3Coefficient + rhs.x3Coefficient),
		(x2Coefficient + rhs.x2Coefficient),
		(xCoefficient + rhs.xCoefficient),
		(constantVal + rhs.constantVal));
	return result;
}

Cubic Cubic::operator-(Cubic rhs) {
	Cubic result((x3Coefficient - rhs.x3Coefficient),
		(x2Coefficient - rhs.x2Coefficient),
		(xCoefficient - rhs.xCoefficient),
		(constantVal - rhs.constantVal));
	return result;
}

Cubic Cubic::operator*(int rhs) {
	Cubic result((rhs * x3Coefficient),
		(rhs * x2Coefficient),
		(rhs * xCoefficient),
		(rhs * constantVal));
	return result;
}

Cubic Cubic::operator*(double rhs) {
	Cubic result((rhs * x3Coefficient),
		(rhs * x2Coefficient),
		(rhs * xCoefficient),
		(rhs * constantVal));
	return result;
}

// Comparison operators
bool Cubic::operator==(Cubic rhs) {
	return (x3Coefficient == rhs.x3Coefficient &&
		x2Coefficient == rhs.x2Coefficient &&
		xCoefficient == rhs.xCoefficient &&
		constantVal == rhs.constantVal);
}

bool Cubic::operator!=(Cubic rhs) {
	// Simple inversion of the == operator
	return !(*this == rhs);
}

// Update operators
Cubic& Cubic::operator+=(Cubic rhs) {
	x3Coefficient += rhs.x3Coefficient;
	x2Coefficient += rhs.x2Coefficient;
	xCoefficient += rhs.xCoefficient;
	constantVal += rhs.constantVal;
	return *this;
}

Cubic& Cubic::operator-=(Cubic rhs) {
	x3Coefficient -= rhs.x3Coefficient;
	x2Coefficient -= rhs.x2Coefficient;
	xCoefficient -= rhs.xCoefficient;
	constantVal -= rhs.constantVal;
	return *this;
}

// I/O operators
istream& operator>>(istream& inStream, Cubic& cubic)
{
	double x3, x2, x, c;
	char seperator;
	inStream >> x3 >> seperator >> x2 >> 
		seperator >> x >> seperator >> c;
	cubic = Cubic(x3, x2, x, c);
	return inStream;
}

ostream& operator<<(ostream& outStream, const Cubic& cubic) {
	outStream << cubic.x3Coefficient << "x^3" << showpos
		<< cubic.x2Coefficient << "x^2"
		<< cubic.xCoefficient << "x" <<
		cubic.constantVal << noshowpos;
	return outStream;
}
