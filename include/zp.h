#ifndef ZP_H
#define ZP_H

namespace gpu_finite_field
{

/// Computes n modulo p.
/// @param n The input integer.
/// @param p A prime number (note: we do not check for primality).
/// @return n % p between 0 and p-1.
unsigned mod(int n, unsigned p);
/// Computes n + m modulo p.
/// @param n The first input integer.
/// @param m The second input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param (n + m) % p.
unsigned mod_add(unsigned n, unsigned m, unsigned p);
/// Computes n - m modulo p.
/// @param n The first input integer.
/// @param m The second input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param (n - m) % p.
unsigned mod_sub(unsigned n, unsigned m, unsigned p);
/// Computes n * m modulo p.
/// @param n The first input integer.
/// @param m The second input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param (n * m) % p.
unsigned mod_mul(unsigned n, unsigned m, unsigned p);
/// Computes n^k modulo p.
/// @param n The base.
/// @param k The power.
/// @param p A prime number (note: we do not check for primality.
/// @param (n^k) % p.
unsigned mod_exp(unsigned n, unsigned k, unsigned p);
/// Computes n^(-1) modulo p.
/// @param n The input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param (n^(-1)) % p.
unsigned mod_inv(unsigned n, unsigned p);

}

#endif
