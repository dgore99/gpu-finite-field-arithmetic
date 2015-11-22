/// @file
/// @brief A file containing functions for operations in \f$Z_p\f$.
#ifndef ZP_H
#define ZP_H

/// Contains finite field operations.
namespace finite_field
{

/// Computes \f$ n \mod{p}\f$.
/// @param n The input integer.
/// @param p A prime number (note: we do not check for primality).
/// @return \f$ n \mod{p}\f$.
unsigned mod(int n, unsigned p);
/// Computes \f$ n + m \mod{p}\f$.
/// @param n The first input integer.
/// @param m The second input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param \f$ n + m \mod{p}\f$.
unsigned mod_add(unsigned n, unsigned m, unsigned p);
/// Computes \f$ n - m \mod{p}\f$.
/// @param n The first input integer.
/// @param m The second input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param \f$ n - m \mod{p}\f$.
unsigned mod_sub(unsigned n, unsigned m, unsigned p);
/// Computes \f$ n \cdot m\mod{p}\f$.
/// @param n The first input integer.
/// @param m The second input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param \f$ n \cdot m\mod{p}\f$.
unsigned mod_mul(unsigned n, unsigned m, unsigned p);
/// Computes \f$ n^k \mod{p}\f$.
/// @param n The base.
/// @param k The power.
/// @param p A prime number (note: we do not check for primality.
/// @param \f$ n^k \mod{p}\f$.
unsigned mod_exp(unsigned n, unsigned k, unsigned p);
/// Computes \f$ n^{-1} \mod{p}\f$.
/// @param n The input integer.
/// @param p A prime number (note: we do not check for primality.
/// @param \f$ n^{-1} \mod{p}\f$.
unsigned mod_inv(unsigned n, unsigned p);

}

#endif
