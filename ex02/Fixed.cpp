#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << " operator= called " <<std::endl;
	this->fixed_point_number = other.getRawBits();
	return (*this);
}

// -------- set and get ----------
int Fixed::getRawBits(void) const
{
	//std::cout << " getRawbits called " <<std::endl;
	return(this->fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << " setRawBits called " <<std::endl;
	this->fixed_point_number = raw;
}

// -------- toFloat Tont function --------
float Fixed::toFloat(void)const
{
	//std::cout << "toFloat function called" << std::endl;
	float f = this->fixed_point_number;
	for (int i = 0; i < this->fractional_bits; i++)
	{
		f /= 2;
	}
	return (f);
}

int Fixed::toInt(void)const
{
	//std::cout << "toInt function called" << std::endl;
	int i = this->fixed_point_number;
	for (int j = 0; j < this->fractional_bits; j++)
	{
		i /= 2;
	}
	return (i);
}

// -------- constructor --------
Fixed::Fixed() :fractional_bits(8)
{
	//std::cout << "void constructor called " << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed(int i) :fractional_bits(8)
{
	//std::cout << "int constructor called " << std::endl;
	this->fixed_point_number = i << this->fractional_bits; //512
}

Fixed::Fixed(const Fixed &f) :fractional_bits(8)
{
	//std::cout << "const constructor called" << std::endl;
	*this = f; 
}

Fixed::Fixed(float fl) :fractional_bits(8)
{
	//std::cout << "float constructor called" << std::endl;
	for (int i = 0; i < this->fractional_bits; i++)
	{
		fl = fl * 2;
	}
	this->fixed_point_number = roundf(fl);
}

// -----The 6 comparison operators: >, <, >=, <=, == and != -----
bool Fixed::operator>(const Fixed &other) const
{
	//std::cout << " operator> called " <<std::endl;
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	//std::cout << " operator< called " <<std::endl;
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	//std::cout << " operator>= called " <<std::endl;
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	//std::cout << " operator<= called " <<std::endl;
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	//std::cout << " operator== called " <<std::endl;
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	//std::cout << " operator!= called " <<std::endl;
	return (this->getRawBits() != other.getRawBits());
}

// -----The 4 arithmetic operators: +, -, *, and /. -----

Fixed Fixed::operator+(const Fixed &other) const
{
	//std::cout << " operator+ called " <<std::endl;
	Fixed r(this->toFloat() + other.toFloat());
	return (r);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	//std::cout << " operator- called " <<std::endl;
	Fixed r(this->toFloat() - other.toFloat());
	return (r);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	//std::cout << " operator* called " <<std::endl;
	Fixed r(this->toFloat() * other.toFloat());
	return (r);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	//std::cout << " operator/ called " <<std::endl;
	Fixed r(this->toFloat() / other.toFloat());
	return (r);
}

// ------------increment--------------
Fixed &Fixed::operator++(void)
{
	//std::cout << " ++operator called " <<std::endl;
	++this->fixed_point_number;
	return(*this);
}

Fixed &Fixed::operator--(void)
{
	//std::cout << " --operator called " <<std::endl;
	--this->fixed_point_number;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	//std::cout << " operator called++ " <<std::endl;
	Fixed f = *this;
	++(this->fixed_point_number);
	return(f);
}

Fixed Fixed::operator--(int)
{
	//std::cout << " operator> called-- " <<std::endl;
	Fixed f = *this;
	--(this->fixed_point_number);
	return(f);
}

std::ostream &operator<< (std::ostream &os, Fixed const f)
{
	//std::cout << " operator> called<< " <<std::endl;
	os << f.toFloat();
	return (os);
}

const Fixed  &Fixed::min(const Fixed &a, const Fixed &b)
{
	//std::cout << " min const function called " <<std::endl;
	if (a < b)
		return (a);
	return (b);
}

const Fixed  &Fixed::max(const Fixed &a, const Fixed &b)
{
	//std::cout << " max const function called " <<std::endl;
	if (a < b)
		return (b);
	return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	//std::cout << " min function called " <<std::endl;
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	//std::cout << " max function called " <<std::endl;
	if (a < b)
		return (b);
	return (a);
}

Fixed::~Fixed(void){
}