//������һ��ˮ������

#ifndef FRUIT_H
#define FRUIT_H
#include "Entity.h"

class Fruit :public Entity {							//ֻ��һ��interface �������ʵ��
public:
	//�����Ĭ����������
	virtual ~Fruit() = default;

	//��Ϊ����ժ֮��������Ʒ
	virtual Item* pick(void) = 0;

	virtual const char* typeName(void) const = 0;
};



#endif

