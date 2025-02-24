#include "ns_state.h"

#include <stddef.h>
#include <stdint.h>

#include <nsfd.h>

#include "ns_chk.h"

size_t ns_state_mem_size(const ns_geom_data* data_p) {
  chk_null(data_p);
  size_t state_size = sizeof(ns_state);
  size_t p_size = ns_sf_mem_size(data_p);
  size_t u_size = ns_vf_mem_size(data_p);

  size_t total_size =
      chk_size_t_add(state_size, chk_size_t_add(p_size, u_size));

  return total_size;
}

ns_state* ns_state_init(const ns_geom_data* data_p, ns_state* sp, real pi,
                        ns_vec ui) {
  chk_null(data_p);
  chk_null(sp);

  sp->time = 0;

  // set location of and initialize pressure field
  sp->p = (ns_sf*)(sp + 1);
  ns_sf_init(data_p, sp->p, pi);

  // set location of and initialize velocity field
  sp->u = (ns_vf*)(&(sp->p) + 1);
  ns_vf_init(data_p, sp->u, ui);

  return sp;
}

real ns_state_time(ns_state* sp) {
  chk_null(sp);
  return sp->time;
}

ns_sf* ns_state_p(ns_state* sp) {
  chk_null(sp);
  return sp->p;
}

ns_vf* ns_state_u(ns_state* sp) {
  chk_null(sp);
  return sp->u;
}
