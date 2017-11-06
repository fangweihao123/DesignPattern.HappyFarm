#include "Apple.h"
#include "ApplePie.h"
#include <iostream>

Item* Apple::pick(void) {
	std::cout << "class:Apple method:pick\n";
	return new ApplePie;
}

const char* Apple::typeName(void) const {
	return "Apple";
}

Entity* Apple::clone(void) const{
	
}