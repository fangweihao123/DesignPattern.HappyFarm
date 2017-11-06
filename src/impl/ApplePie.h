#ifndef APPLEPIE_H
#define APPLEPIE_H

#include "Food.h"
class ApplePie :public Food {
public:
	virtual ~ApplePie() = default;
	virtual const char* name(void) const;
	virtual void usedBy(Player* player);
};

#endif // !APPLEPIE_H
