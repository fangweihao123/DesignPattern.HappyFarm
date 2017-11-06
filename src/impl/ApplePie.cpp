#include "ApplePie.h"
#include <iostream>


const char* ApplePie::name(void) const {
	return "ApplePie";
}

void ApplePie::usedBy(Player* player) {
	std::cout << "class:ApplePie method:usedBy \n";
}