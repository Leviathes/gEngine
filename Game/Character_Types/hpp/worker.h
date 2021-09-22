#ifndef H_BUILDER
#define H_BUILDER
#include "../../hpp/entity.h"

class worker : public entity {

 public :
	double team = {Team_Blue};
  explicit worker(const vd2d& pos);



};


#endif // H_BUILDER

