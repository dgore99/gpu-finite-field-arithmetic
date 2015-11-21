#include <algorithm>
#include <iostream>

#include "polynomial.h"

using std::cout;
using std::endl;
using std::fill_n;
using std::make_pair;

typedef std::unique_ptr<unsigned> c_ptr;

namespace gpu_finite_field
{

polynomial& poly_zp(int* coeffs, unsigned degree, unsigned p)
{
	unsigned* arr = new unsigned[degree + 1];

	for (unsigned j = 0 ; j <= degree ; j++)
	{
		arr[j] = coeffs[j] % p;

		if (arr[j] < 0)
			arr[j] += p;
	}

	return make_pair(c_ptr(arr), degree);
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

	unsigned* q = new unsigned[a ->second + 1];

	for (int j = 0 ; j <= b ->second ; j++)
		q[j] = (a ->first[j] + b ->first[j]) % p;

	for (int j = b ->second + 1 ; j <= a ->second ; j++)
		q[j] = a ->first[j];

	a = nullptr;
	b = nullptr;

	return make_pair(c_ptr(arr), a ->second);
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

	return make_pair(c_ptr(coeffs), deg);
}

polynomial& poly_const_mul(int k, const polynomial& f, unsigned p)
{
	// Force the multiple to be non-negative.
	unsigned mult = (k < 0 ? ((p - 1) * k) % p : k % p);

	if (mult == 0)
	{
		unsigned* o = new unsigned[1];
		o[0] = 0;
		return make_pair(c_ptr(o), 0);
	}

	unsigned* coeffs(new unsigned[f.second]);

	for (int j = 0 ; j <= f.second  ; j++)
		coeffs[j] = (mult * f.first[j]) % p;

	return make_pair(c_ptr(coeffs, f.second));
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
