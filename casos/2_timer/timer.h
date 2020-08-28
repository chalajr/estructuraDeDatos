/*
 * timer.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <string>
#include <sstream>

class Timer {
private:
	int hours, minutes;

public:
	Timer();
	Timer(int, int);
	Timer(const Timer&);

	int getHours() const;
	int getMinutes() const;
	std::string toString() const;

	void operator= (const Timer&);
	void operator+= (const Timer&);
};

Timer::Timer() : hours(0), minutes(0) {}

Timer::Timer(int hh, int mm) {
	this->minutes = mm % 60;
	this->hours = (hh + mm/60) % 24;
}

Timer::Timer(const Timer &t) {}

int Timer::getHours() const {
	return this->hours;
}

int Timer::getMinutes() const {
	return this->minutes;
}

std::string Timer::toString() const {
	 std::stringstream aux;

	 if (hours < 10) {
		 aux << "0";
	 }
	 aux << hours << ":";
	 if (minutes < 10) {
		 aux << "0";
	 }
	 aux << minutes;
	 return aux.str();
}

void Timer::operator= (const Timer &right) {
	minutes = right.minutes;
	hours = right.hours;
}

void Timer::operator+= (const Timer &right) {
	int res;
	res = minutes + right.minutes;
	minutes = res % 60;
	hours = (hours + right.hours + (res / 60)) % 24;
}

bool operator== (const Timer &left, const Timer &right) {
	if(left.getMinutes()==right.getMinutes() && left.getHours()==right.getHours()){
		return true;
	}
	return false;
}

bool operator> (const Timer &left, const Timer &right) {
	if(left.getHours() == right.getHours()){
		return(left.getMinutes() > right.getMinutes());
	}
	return (left.getHours() > right.getHours());
}

#endif /* TIMER_H_ */