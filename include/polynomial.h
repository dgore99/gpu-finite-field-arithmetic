#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <memory>
#include <utility>

namespace gpu_finite_field
{

typedef std::pair<std::unique_ptr<unsigned>, unsigned> polynomial;

/// Creates a polynomial in Z_p[x].
/// @param coeffs The coefficient vector of a monic polynomial ordered
///			like [a_0,a_1,...,a_n], where a_i is the coefficient of x^i.
/// @param degree The degree of the polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A coefficient vector along with the polynomial's degree.
polynomial& poly_zp(int* coeffs, unsigned degree, unsigned p);
/// Adds polynomials f and g in Z_p[x].
/// @param f The first polynomial.
/// @param g The second polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing f+g in Z_p[x].
polynomial& poly_add(const polynomial& f, const polynomial& g, unsigned p);
/// Subtracts a polynomial g from another polynomial f in Z_p[x].
/// @param f The first polynomial.
/// @param g The polynomial to subtract.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing f-g in Z_p[x].
polynomial& poly_sub(const polynomial& f, const polynomial& g, unsigned p);
/// Multiplies polynomials f and g in Z_p[x].
/// @param f The first polynomial.
/// @param g The second polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing f*g in Z_p[x].
polynomial& poly_mul(const polynomial& f, const polynomial& g, unsigned p);
/// Multiplies a polynomial f by a constant k in Z_p[x].
/// @param k The constant in Z_p.
/// @param f The first polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing k*f in Z_p[x].
polynomial& poly_const_mul(int k, const polynomial& f, unsigned p);

/// Prints a polynomial in its canonical form.
/// @param f The polynomial.
void print_poly_form(const polynomial& f);
/// Prints a vector listing the coefficients of f, e.g. [a_0, a_1,..., a_n].
/// @param f The polynomial.
void print_vect_form(const polynomial& f);

}

#endif // POLYNOMIAL_H
