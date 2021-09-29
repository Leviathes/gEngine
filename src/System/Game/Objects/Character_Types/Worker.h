#ifndef H_BUILDER
#define H_BUILDER
#include "Entity.h"

class Worker : public Entity {

 public :
	double team = {BLUE_TEAM};
  explicit Worker(const vd2d& pos);



};


#endif // H_BUILDER

