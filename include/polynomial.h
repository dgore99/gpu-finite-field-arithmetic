#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <memory>
#include <utility>

namespace gpu_finite_field
{

typedef std::pair<std::unique_ptr<unsigned>, unsigned> polynomial;

/// Computes a polynomial modulo p.
/// @param coeffs The coefficient vector of a monic polynomial ordered
///			like [a_0,a_1,...,a_n], where a_i is the coefficient of x^i.
/// @param degree The degree of the polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A coefficient vector along with the polynomial's degree.
polynomial& poly_zp(int* coeffs, unsigned degree, unsigned p);
polynomial& poly_add(const polynomial& f, const polynomial& g, unsigned p);
polynomial& poly_sub(const polynomial& f, const polynomial& g, unsigned p);
polynomial& poly_mul(const polynomial& f, const polynomial& g, unsigned p);
polynomial& poly_const_mul(int k, const polynomial& f, unsigned p);

void print_poly_form(const polynomial& f);
void print_vect_form(const polynomial& f);

}

#endif // POLYNOMIAL_H
