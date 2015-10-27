#include "polynomial.h"

namespace gpu_poly
{

class modular_polynomial
{
	public:
		modular_polynomial(const polynomial& poly, const polynomial& modulus);
		~modular_polynomial()
		
		polynomial&	get_polynomial();
		polynomial&	get_modulus();
		
		static modular_polynomial& operator+(const modular_polynomial& p, const modular_polynomial& q);
		static modular_polynomial& operator-(const modular_polynomial& p, const modular_polynomial& q);
		static modular_polynomial& operator*(const modular_polynomial& p, const modular_polynomial& q);
		static modular_polynomial& operator/(const modular_polynomial& p, const modular_polynomial& q);
		static modular_polynomial& operator^(const modular_polynomial& p, int n);
		static modular_polynomial& inverse(const modular_polynomial& p);
		
	private:
		polynomial	poly;
		polynomial	modulus;
};

}
