/*
ourExceptions.h
Teng Zhao 40089560
Thomas Flynn 40034877

*/


#pragma once
#include <iostream>
#include <exception>

using namespace std;

class notFound : public exception {

	virtual const char* what() const throw()
	{
		return "Element not found in List !";
	}

};

class outOfRange : public exception {
	virtual const char* what() const throw()
	{
		return "position entered is out of Range !";
	}
};