#pragma once
#include <iostream> 
class Cubic {
public:
// Constructors
	Cubic();
	Cubic(double x3, double x2, double x, double constant);

// Member functions
	double computeValue(double xval) const;
	double getCoefficient(int degree) const;
	void setCoefficient(double val, int degree);

// Arithmetic operators
	Cubic operator+(Cubic rhs);
	Cubic operator-(Cubic rhs);
	Cubic operator*(int rhs);
	Cubic operator*(double rhs);

// Comparison operators
	bool operator==(Cubic rhs);
	bool operator!=(Cubic rhs);

// Update operators
	Cubic& operator+=(Cubic rhs);
	Cubic& operator-=(Cubic rhs);

// I/O operators
	friend std::istream& operator>>(std::istream& inStream, Cubic& cubic);
	friend std::ostream& operator<<(std::ostream& outStream, const Cubic& cubic);

private:
// Data representation
	double x3Coefficient;
	double x2Coefficient;
	double xCoefficient;
	double constantVal;

};