//自定义的类   果园的场景

#ifndef ORCHARD_H
#define ORCHARD_H
#include "Scene.h"

class Orchard:public Scene{
	public:
		Orchard(Decorator* dec = new Decorator) : Scene("Orchard", dec) {}
		virtual ~Orchard();
		virtual const char* typeName(void) const;
		virtual Entity* spawn(void);							//在这个场景中生成的植物或者动物 都隶属于entity类
};


#endif
