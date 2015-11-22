#include <algorithm>
#include <iostream>

#include "../include/polynomial.h"
#include "../include/zp.h"

using std::cout;
using std::endl;
using std::fill_n;
using std::make_pair;

typedef std::unique_ptr<unsigned> c_ptr;

namespace finite_field
{

polynomial& poly_zp(const int* coeffs, unsigned len, unsigned p)
{
	unsigned	d;

	for (d = len - 1 ; d >= 0 && coeffs[d] == 0 ; d--);

	unsigned*	arr(new unsigned[d + 1]);

	for (unsigned j = d ; j >= 0 ; j--)
		arr[j] = mod(coeffs[j], p);

	return make_pair(c_ptr(arr), d);
}

polynomial& poly_zp(const unsigned* coeffs, unsigned degree, unsigned p)
{
	unsigned	d;

	for (d = degree ; d >= 0 && coeffs[d] == 0 ; d--);

	unsigned*	arr(new unsigned[d + 1]);

	for (unsigned j = d ; j >= 0 ; j--)
		arr[j] = mod(coeffs[j], p);

	return make_pair(c_ptr(arr), d);
}

polynomial& poly_add(const polynomial& f, const polynomial& g, unsigned p)
{
	polynomial* a, b;

	if (f.second <= g.second)
	{
		a = &g;
		b = &f;
	}
	else
	{
		a = &f;
		b = &g;
	}

	unsigned	d(a ->second);
	c_ptr 		q(new unsigned[d + 1]);

	for (int j = 0 ; j <= b ->second ; j++)
		q[j] = (a ->first[j] + b ->first[j]) % p;

	for (int j = b ->second + 1 ; j <= d ; j++)
		q[j] = a ->first[j];

	a = nullptr;
	b = nullptr;

	return poly_zp(q.get(), d);
}

polynomial& poly_sub(const polynomial& f, const polynomial& g, unsigned p)
{
	return poly_add(f, poly_const_mul(p - 1, g));
}

polynomial& poly_mul(const polynomial& f, const polynomial& g, unsigned p)
{
	unsigned	deg(f.second * g.second);
	unsigned*	coeffs(new unsigned[deg + 1]);

	fill_n(coeffs, deg + 1, 0);

	for (unsigned i = 0 ; i <= f.second ; i++)
		for (unsigned j = 0 ; j <= g.second ; j++)
			coeffs[i + j] += (f.first[i] * g.second[j]) % p;

	c_ptr		q(coeffs);

	return poly_zp(q.get(), deg);
}

polynomial& poly_const_mul(int k, const polynomial& f, unsigned p)
{
	// Force the multiple to be in Z_p.
	unsigned mult = mod(k, p);

	if (mult == 0)
	{
		unsigned	d(0);
		c_ptr		q(new unsigned);
		*q = 0;
		return make_pair(q, d);
	}

	else
	{
		unsigned* coeffs(new unsigned[f.second]);

		// Multiply the polynomials
		for (int j = 0 ; j <= f.second  ; j++)
			coeffs[j] = (mult * f.first[j]) % p;

		return make_pair(c_ptr(coeffs), f.second));
	}
}

bool is_zero(const polynomial& f)
{
	for (unsigned j = 0 ; j < f.second ; j++)
		if (f.first[j] != 0)
			return false;

	return true;
}

void print_poly_form(const polynomial& f)
{
	cout << f.first[0];

	for (int j = 1 ; j <= f.second ; j++)
		cout << "+" << f.first[j] << "x^" << j;

	cout << endl;
}

void print_vect_form(const polynomial& f)
{
	cout << "[" << f.first[0];

	for (int j = 1 ; j <= f.second ; j++)
		cout << "," << f.first[j];

	cout << "]" << endl;
}

}
