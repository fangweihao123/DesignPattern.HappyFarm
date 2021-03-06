#include "Sheep.h"
#include "Item.h"
#include "Mutton.h"

Entity* Sheep::clone(void) const {
    return new Sheep;
}

Item* Sheep::pick(void) {
    return new Mutton;
}

const char* Sheep::typeName(void) const {
    return "Sheep";
}
