#include <algorithm>
#include <cmath>
#include <memory>

#include "polynomial.h"

using std::copy_n;
using std::shared_ptr;

namespace gpu_finite_field
{

polynomial::polynomial(const unsigned* coeffs_i, unsigned degree_i, unsigned charecteristic_i) :
	coeffs(new unsigned[degree_i+1]), degree(degree_i), charecteristic(charecteristic_i)
{
	unsigned* arr((this -> coeffs).get());
	copy_n(coeffs_i, degree + 1, arr);
}

polynomial::polynomial(polynomial&& move_me) : coeffs(move_me.coeffs),
	degree(move_me.degree), charecteristic(move_me.charecteristic)
{
}

polynomial(shared_ptr<unsigned> coeffs, unsigned degree, unsigned charecteristic);

polynomial::~polynomial()
{
	delete coeffs;
}

unsigned* polynomial::get_coeffs()
{
	unsigned* copy_coeffs(new unsigned[degree + 1]);
	unsigned* arr(coeffs.get())
	copy_n(arr, degree + 1, copy_coeffs);
}

unsigned polynomial::get_charecteristic()
{
	return charecteristic;
}

unsigned polynomial::get_degree()
{
	return degree;
}

polynomial& polynomial::copy()
{
	return polynomial(coeffs.get(), degree, charecteristic);
}

static polynomial& polynomial::operator+(const polynomial& p, const polynomial& q)
{
	unsigned		charecteristic(p.charecteristic);
	const unsigned	*p_co(p.coeffs), *q_co(q.coeffs), *b_co;
	int				p_deg(p.degree), q_deg(q.degree);
	
	// Find min and max
	int			diff		= p_deg - q_deg;
	int			sum			= p_deg + q_deg;
	unsigned	abs_diff	= (unsigned) sqrt(diff*diff);
	unsigned	max			= (sum + abs_diff)/2, maxp1 = max + 1;
	unsigned	min			= (sum - abs_diff)/2, minp1 = min + 1;
	
	unsigned*	r_co(new unsigned[max + 1]);
	
	// Sum shared
	for ( unsigned i = 0 ; i < minp1 ; i++ )
		r_co[i] = (p_co[i] + q_co[i]) % charecteristic;
	
	b_co	= ( (p_deg == max) ? p_co : q_co );
	
	// Copy big
	for ( unsigned i = minp1 ; i < maxp1 ; i++ )
		r_co[i] = b_co[i];
		
	unsigned	r_deg(max);
	
	// Find the degree of the new polynomial
	while ( r_co[r_deg] == 0 && r_deg > 0 )
		r_deg--;
	
	return polynomial(shared_ptr<unsigned>(r_co), r_deg, charecteristic);
}

// Hacky way, not efficient but works with mimimal control statements
static polynomial& polynomial::operator-(const polynomial& p, const polynomial& q)
{
	unsigned		charecteristic(p.charecteristic);
	const unsigned	*q_co(q.coeffs);
	int				q_deg(q.degree), q_deg_p1 = q_deg+1;
	unsigned		r_co[q_deg+1];
		
	return p + (charecteristic - 1) * q ;
}

static polynomial& polynomial::operator*(const polynomial& p, const polynomial& q)
{
	const unsigned	*p_co(p.coeffs),	*q_co(q.coeffs);
	unsigned		p_deg(p.degree),	q_deg(q.degree);
	unsigned		p_deg_p1(p_deg+1),	q_deg_p1(q_deg+1);
	unsigned		r_deg(p_deg+q_deg),	r_deg_p1(r_deg+1);
	unsigned		charecteristic(p.charecteristic);
	
	unsigned		r_co[r_deg_p1];
	
	// Compute the new vector of coefficients
	for ( i = 0 ; i < p_deg_p1 ; i++)
		for ( j = 0 ; j < q_deg_p1 ; j++)
			r_co[i+j] = p_co[i] + q_co[j];
	
	return polynomial(r_co, r_deg, charecteristic);
}

static polynomial& polynomial::operator*(unsigned n, const polynomial& p)
{
	unsigned		charecteristic(p.charecteristic);
	const unsigned	*p_co(p.coeffs);
	int				p_deg(p.degree), p_deg_p1 = p_deg+1;
	unsigned*		r_co(new unsigned[q_deg+1]);
	
	// Multiply everything in p
	for ( i = 0 ; i < p_deg_p1 ; i++ )
		r_co[i] = (n*p_co[i])%charecteristic;
		
	// Reduce
	unsigned	r_deg(q_deg);
	
	// Find the degree of the new polynomial
	while ( r_co[r_deg] == 0 && r_deg > 0 )
		r_deg--;
		
	return p + polynomial(shared_ptr<unsigned>(r_co), r_deg, charecteristic);
}

}
