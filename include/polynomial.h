/// @file
/// @brief A file containing functions for operations in \f$Z_p[x]\f$.
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <memory>
#include <utility>

/// Contains finite field operations.
namespace finite_field
{

/// A polynomial is a list of coefficients and a degree.
typedef std::pair<std::unique_ptr<unsigned>, unsigned> polynomial;

/// Creates a polynomial in \f$Z_p[x]\f$.
/// @param coeffs The coefficient vector of a monic polynomial ordered
///	like \f$[a_0,a_1,\ldots,a_n]\f$,
/// where \f$a_i\f$ is the coefficient of \f$x^i\f$.
/// @param len The length of the array.
/// @param p A prime number (note: we do not check for primality).
/// @return A coefficient vector along with the polynomial's degree.
polynomial& poly_zp(const int* coeffs, unsigned len, unsigned p);
/// Adds polynomials \f$f\f$ and \f$g\f$ in \f$Z_p[x]\f$.
/// @param f The first polynomial.
/// @param g The second polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing \f$f+g\f$ in \f$Z_p[x]\f$.
polynomial& poly_add(const polynomial& f, const polynomial& g, unsigned p);
/// Subtracts a polynomial $g$ from another polynomial \f$f\f$ in \f$Z_p[x]\f$.
/// @param f The first polynomial.
/// @param g The polynomial to subtract.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing \f$f-g\f$ in \f$Z_p[x]\f$.
polynomial& poly_sub(const polynomial& f, const polynomial& g, unsigned p);
/// Multiplies polynomials \f$f\f$ and \f$g\f$ in \f$Z_p[x]\f$.
/// @param f The first polynomial.
/// @param g The second polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing \f$f\cdot g\f$ in \f$Z_p[x]\f$.
polynomial& poly_mul(const polynomial& f, const polynomial& g, unsigned p);
/// Multiplies a polynomial \f$f\in Z_p[x]]\f$ by a constant \f$k\in Z_p\f$.
/// @param k The constant in \f$Z_p\f$.
/// @param f The first polynomial.
/// @param p A prime number (note: we do not check for primality).
/// @return A polynomial representing \f$kf\f$ in \f$Z_p[x]\f$.
polynomial& poly_const_mul(int k, const polynomial& f, unsigned p);

/// Checks if a polynomial is the zero polynomial.
/// @param f The polynomial.
/// @return true if zero, false otherwise.
bool is_zero(const polynomial& f);

/// @brief Prints a polynomial in its canonical form,
/// e.g. \f$a_0+a_1x+\ldots+a_nx^n\f$.
/// @param f The polynomial.
void print_poly_form(const polynomial& f);
/// @brief Prints a vector listing the coefficients of \f$f\f$,
/// e.g. \f$[a_0, a_1,\ldots, a_n]\f$.
/// @param f The polynomial.
void print_vect_form(const polynomial& f);

}

#endif // POLYNOMIAL_H
