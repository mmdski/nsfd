#ifndef NS_STATE_H_
#define NS_STATE_H_

#include <nsfd.h>

struct ns_state {
  real time;
  ns_sf *p;
  ns_vf *u;
};

#endif
