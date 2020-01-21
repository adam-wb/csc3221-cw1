#pragma once
#include <iostream>
class Polynomial {
public:
// Constructors
	Polynomial();
	Polynomial(int degree);
	Polynomial(const Polynomial& copy);

// Destructor
	~Polynomial();

// Member functions
	double computeValue(double xval) const;
	double getCoefficient(int degree) const;
	void setCoefficient(double val, int degree);

// Assignment Operator
	Polynomial& operator=(const Polynomial& rhs);

// Arithmetic operators
	Polynomial operator+(Polynomial rhs);
	Polynomial operator-(Polynomial rhs);
	Polynomial operator*(int rhs);
	Polynomial operator*(double rhs);
	Polynomial operator*(Polynomial rhs);

// Comparison operators
	bool operator==(Polynomial rhs);
	bool operator!=(Polynomial rhs);

// Update operators
	Polynomial& operator+=(Polynomial rhs);
	Polynomial& operator-=(Polynomial rhs);
	Polynomial& operator*=(Polynomial rhs);

// I/O operators
	friend std::istream& operator>>(std::istream& inStream, Polynomial& polynomial);
	friend std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial);

private:
// Helper functions
	void setDegree(int degree);
	void extendArray(int newDegree);

// Data representation
	int degree;
	double* coefficients;
};

