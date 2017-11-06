#ifndef APPLE_H
#define APPLE_H
#include "Fruit.h" 

class Item;

class Apple :public Fruit {
public:
	Apple() = default;
	virtual ~Apple() = default;
	virtual Item* pick(void);
	virtual const char* typeName(void) const;
	virtual Entity* clone(void) const;
};
#endif // !APPLE_H

