#include <memory>

#include "polynomial.h"

namespace gpu_finite_field
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
		modular_polynomial(std::shared_ptr<polynomial> poly, std::shared_ptr<polynomial> modulus);
		
		std::shared_ptr<polynomial>	poly;
		std::shared_ptr<polynomial>	modulus;
};

}
