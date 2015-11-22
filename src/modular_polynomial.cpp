#include "modular_polynomial.h"
#include "polynomial.h"

#define mod_poly	modular_polynomial

namespace finite_field
{

mod_poly::mod_poly(const polynomial& poly, const polynomial& modulus) :
	poly(poly.copy()), modulus(modulus.copy())
{}

mod_poly::~mod_poly()
{}

polynomial& mod_poly::get_polynomial()	{return poly;}

polynomial& mod_poly::get_modulus()		{return modulus;}

static mod_poly::operator+(const mod_poly& p, const mod_poly& q)
{
	return mod_poly(p.poly+q.poly, p.modulus);
}

static mod_poly::operator-(const mod_poly& p, const mod_poly& q)
{
	return mod_poly(p.poly-q.poly, p.modulus);
}

static mod_poly::operator*(const mod_poly& p, const mod_poly& q)
{
	return mod_poly(p.poly*q.poly, p.modulus);
}

}
