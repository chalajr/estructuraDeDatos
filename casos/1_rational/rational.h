 /*
 * rational.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "exception.h"
#include <string>
#include <sstream>

class Rational {
private:
	int numerator;
	int denominator;

	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	std::string toString() const;

	void operator= (const Rational&);
	void operator+= (const Rational&);

	operator double () const;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}

Rational::Rational(int num, int dem){
    if (dem == 0){
        throw RangeError();
    }else{
        numerator = num;
        denominator = dem;
    }
	normalize();
}

Rational::Rational(const Rational&){

}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

Rational::operator double () const {
	double doubleRational = numerator/(double)denominator;
	return doubleRational;
}

//Greatest common divisor
int gcd(int a, int b) {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

void Rational::normalize() {
	int sign = 1;
	if (numerator < 0) {
		sign = -1;
		numerator = -numerator;
	}
	if (denominator < 0) {
		sign = -sign;
		denominator = -denominator;
	}
	if (denominator == 0) {
		throw RangeError();
	}
	int Rgcd = gcd(numerator, denominator);
	numerator = sign * numerator / Rgcd;
	denominator = denominator / Rgcd;
}


void Rational::operator= (const Rational &right) {
	denominator = right.denominator;
	numerator = right.numerator;
}

void Rational::operator+= (const Rational &right) {
	numerator = (numerator * right.denominator) + (right.numerator * denominator);
	denominator = denominator * right.denominator;
	normalize();
}

Rational operator+ (const Rational &left, const Rational &right) {
	int num, den;
	num = (left.getNumerator() * right.getDenominator()) + (right.getNumerator() * left.getDenominator());
	den  = left.getDenominator() * right.getDenominator();
	return Rational(num, den);
}

Rational operator- (const Rational &left, const Rational &right) {
	int num, den;
	num = (left.getNumerator() * right.getDenominator()) - (right.getNumerator() * left.getDenominator());
	den  = left.getDenominator() * right.getDenominator();
	return Rational(num, den);
}

Rational operator- (const Rational &right) {
	return Rational(-right.getNumerator(), right.getDenominator());
}

bool operator== (const Rational &left, const Rational &right) {
	return (left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator());
}

bool operator<  (const Rational &left, const Rational &right) {
	return (left.getNumerator() * right.getDenominator()) < (left.getDenominator() * right.getNumerator());
}

#endif /* RATIONAL_H_ */
