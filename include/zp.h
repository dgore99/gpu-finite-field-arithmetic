#ifndef ZP_H
#define ZP_H

namespace gpu_finite_field
{

unsigned mod(int n, unsigned p);
unsigned mod_add(unsigned n, unsigned m, unsigned p);
unsigned mod_sub(unsigned n, unsigned m, unsigned p);
unsigned mod_mul(unsigned n, unsigned m, unsigned p);
unsigned mod_exp(unsigned n, unsigned k, unsigned p);
unsigned mod_inv(unsigned n, unsigned p);

}

#endif
