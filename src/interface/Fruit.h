//定义了一个水果基类

#ifndef FRUIT_H
#define FRUIT_H
#include "Entity.h"

class Fruit :public Entity {							//只是一个interface 无需具体实现
public:
	//基类的默认析构函数
	virtual ~Fruit() = default;

	//作为被采摘之后会掉落物品
	virtual Item* pick(void) = 0;

	virtual const char* typeName(void) const = 0;
};



#endif

