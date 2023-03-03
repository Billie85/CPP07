#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed
{
	private:
		int fixed_point_number;
		const int fractional_bits;
	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void)const;
		int toInt(void)const;

		Fixed();
		Fixed(int i);
		Fixed(const Fixed &f);
		Fixed(float fl);
		~Fixed();

		Fixed &operator=(const Fixed &other);
		//The 6 comparison operators: >, <, >=, <=, == and !=.
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		//The 4 arithmetic operators: +, -, *, and /.
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		 //Overload pre-increment operator
		 Fixed &operator++(void);
		 //Overload post-increment operator
		 Fixed operator++(int);
		 //Overload pre-decrement operator
		 Fixed &operator--(void);
		 //Overload post-decrement operator
		 Fixed operator--(int);
		
		//min
		static Fixed const &min(Fixed const& a, Fixed const& b);
		static Fixed &min(Fixed &a,  Fixed &b);
		//max
		static Fixed const &max(Fixed const& a, Fixed const& b);
		static Fixed &max(Fixed &a, Fixed &b);
};
std::ostream &operator<< (std::ostream &os, Fixed const f);

#endif
