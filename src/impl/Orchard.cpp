#include"Orchard.h"
#include "Apple.h"
#include <iostream>
Orchard::~Orchard() {
}

const char* Orchard::typeName(void) const {
	return "Orchard";
}

Entity* Orchard::spawn(void) {
	std::cout << "class:Orchard method:spawn \n";
	return new Apple;
}