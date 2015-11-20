#include "../include/zp.h"

namespace gpu_finite_field
{

unsigned mod_exp_helper(unsigned n, unsigned k, unsigned p);

unsigned mod(int n, unsigned p)
{
	int n_p(n % p);

	return (unsigned)(n_p >= 0 ? n_p : n_p + p);
}

unsigned mod_add(unsigned n, unsigned m, unsigned p)
{
	return (n + m) % p;
}

unsigned mod_sub(unsigned n, unsigned m, unsigned p)
{
	return (n + (p-1) * m) % p;
}

unsigned mod_mul(unsigned n, unsigned m, unsigned p)
{
	return (n * m) % p;
}

unsigned mod_div(unsigned n, unsigned m, unsigned p)
{
	return (n * mod_inv(n, p)) % p;
}

unsigned mod_exp(unsigned n, unsigned k, unsigned p)
{
	// Invoke Fermat's Little Theorem
	k = k % (p - 1);

	return mod_exp_helper(n, k, p);
}

unsigned mod_exp_helper(unsigned n, unsigned k, unsigned p)
{
	if (k == 1)
	{
		return n;
	}
	else if (k % 2 == 0)
	{
		unsigned out(mod_exp_helper(n, k/2, p));
		return (out * out) % p;
	}
	else
	{
		unsigned out(mod_exp_helper(n, (k-1)/2, p));
		return (out * out * n) % p;
	}
}

unsigned mod_inv(unsigned n, unsigned p)
{
	int t(0), t_new(1);
	int r(p), r_new(n);
	int q, temp;

	while (r_new != 0)
	{
		q		= r / r_new;

		temp	= t_new;
		t_new	= t - q * t_new;
		t		= temp;

		temp	= r_new;
		r_new	= r - q * r_new;
		r		= temp;
	}

	if (t < 0)
		t += p;

	return (unsigned)t;
}

}
