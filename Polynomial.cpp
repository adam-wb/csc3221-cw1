#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;
// Constructors
Polynomial::Polynomial() {
	// Default constructor, initialise to cubic
	setDegree(3);
}

Polynomial::Polynomial(int degree) {
	setDegree(degree);
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& copy) {
	setDegree(copy.degree);
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = copy.coefficients[i];
	}
}

// Destructor
Polynomial::~Polynomial() {
	if (coefficients) {
		delete[] coefficients;
	}
}

double Polynomial::computeValue(double xval) const {
	double result = 0;
	for (int i = 0; i <= degree; i++) {
		result += pow(xval * coefficients[i], i);
	}
	return result;
}

// Returns the desired coefficient
double Polynomial::getCoefficient(int degree) const {
	return coefficients[degree];
}

// Set the desired coefficient
void Polynomial::setCoefficient(double val, int degree) {
	if (degree > this->degree) {
		// Illegal
		return;
	}
	coefficients[degree] = val;
}

// Assignment Operator
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this == &rhs) {
		return *this;
	}
	if (degree != -1) {
		delete[] coefficients;
	}
	setDegree(rhs.degree);
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = rhs.coefficients[i];
	}
	return *this;
}

// Arithmetic Operators
Polynomial Polynomial::operator+(Polynomial rhs) {
	Polynomial p;
	if (degree < rhs.degree) {
		p.setDegree(rhs.degree);
	}
	else {
		p.setDegree(degree);
	}
	for (int i = 0; i <= rhs.degree; i++) {
		p.coefficients[i] = coefficients[i] + rhs.coefficients[i];
	}
	return p;
}

Polynomial Polynomial::operator-(Polynomial rhs) {
	Polynomial p;
	if (degree < rhs.degree) {
		p.setDegree(rhs.degree);
	}
	else {
		p.setDegree(degree);
	}
	for (int i = 0; i <= rhs.degree; i++) {
		p.coefficients[i] = coefficients[i] - rhs.coefficients[i];
	}
	return p;
}

Polynomial Polynomial::operator*(int rhs) {
	Polynomial p(degree);
	for (int i = 0; i <= degree; i++) {
		p.coefficients[i] = rhs * (coefficients[i]);
	}
	return p;
}

Polynomial Polynomial::operator*(double rhs) {
	Polynomial p(degree);
	for (int i = 0; i <= degree; i++) {
		p.coefficients[i] = rhs * (coefficients[i]);
	}
	return p;
}

Polynomial Polynomial::operator*(Polynomial rhs) {
	Polynomial p(degree + rhs.degree);
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= rhs.degree; j++) {
			p.coefficients[i + j] += coefficients[i] * rhs.coefficients[j];
		}
	}
	return p;
}

// Comparison operators
bool Polynomial::operator==(Polynomial rhs) {
	if (degree != rhs.degree)
		return false;
	for (int i = 0; i <= degree; i++) {
		if (coefficients[i] != rhs.coefficients[i])
			return false;
	}
	return true;
}

bool Polynomial::operator!=(Polynomial rhs) {
	// Simple inversion of the == operator
	return !(*this == rhs);
}

// Update Operators
Polynomial& Polynomial::operator+=(Polynomial rhs) {
	if (degree < rhs.degree)
		extendArray(rhs.degree);
	for (int i = 0; i <= rhs.degree; i++) {
		coefficients[i] += rhs.coefficients[i];
	}
	return *this;
}

Polynomial& Polynomial::operator-=(Polynomial rhs) {
	if (degree < rhs.degree)
		extendArray(rhs.degree);
	for (int i = 0; i <= rhs.degree; i++) {
		coefficients[i] -= rhs.coefficients[i];
	}
	return *this;
}

Polynomial& Polynomial::operator*=(Polynomial rhs) {
	// Store current coefficients of 'this' in another array
	int tempLength = degree + 1;
	double* temp = new double[tempLength];
	for (int i = 0; i < tempLength; i++) {
		temp[i] = coefficients[i];
	}
	// Zero the coefficient array
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = 0;
	}
	extendArray(degree + rhs.degree);
	// Perform multiplication as normal
	for (int i = 0; i < tempLength; i++) {
		for (int j = 0; j <= rhs.degree; j++) {
			coefficients[i + j] += temp[i] * rhs.coefficients[j];
		}
	}
	delete[] temp;
	return *this;
}

// IO Operators
std::istream& operator>>(std::istream& inStream, Polynomial& polynomial) {
	double x;
	char seperator;
	for (int i = polynomial.degree; i >= 0; i--) {
		if (i != 0) {
			inStream >> x >> seperator;
		}
		else {
			inStream >> x;
		}
		polynomial.coefficients[i] = x;
	}
	return inStream;
}

std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial) {
	bool streamEmpty = true;
	for (int i = polynomial.degree; i >= 0; i--) {
		if (polynomial.coefficients[i] != 0) {
			streamEmpty = false;
			outStream << polynomial.coefficients[i] << showpos;
			if (i != 0)
				outStream << "x";
			if (i != 0 && i != 1)
				outStream << "^" << noshowpos << i << showpos;
		}
	}
	if (streamEmpty)
		outStream << "0";
	outStream << noshowpos;
	return outStream;
}


// Helper functions
// Set the degree of the polynomial and initialise the coefficient array as appropriate
void Polynomial::setDegree(int degree) {
	if (degree < 1) {
		// Invalid
		return;
	}
	this->degree = degree;
	coefficients = new double[degree + 1];
	for (int i = 0; i <= degree; i++) {
		coefficients[i] = 0;
	}
}

// Increase the degree of a polynomial while maintaining the existing coefficients
// Used for update operators
void Polynomial::extendArray(int newDegree) {
	// Copy current coefficients to a temporary array
	int oldDegree = degree;
	double* temp = new double[oldDegree + 1];
	for (int i = 0; i <= oldDegree; i++) {
		temp[i] = coefficients[i];
	}
	// Delete and reinitialse to new degree size
	delete[] coefficients;
	setDegree(newDegree);
	// Restore old coefficients
	for (int i = 0; i <= oldDegree; i++) {
		coefficients[i] = temp[i];
	}
	delete[] temp;
}