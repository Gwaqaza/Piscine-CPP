/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:31:13 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/07 18:18:52 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) {
	this->_inFixed = 0;
	//std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & rhs) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return;
}

Fixed &		Fixed::operator=(Fixed const & rhs) {
	//std::cout << "Assignation operator called" << std::endl;
	this->_inFixed = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
	return;
}

bool		Fixed::operator>( Fixed const & rhs ) {
	if (this->_inFixed > rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator<( Fixed const & rhs ) {
	if (this->_inFixed < rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator>=( Fixed const & rhs ) {
	if (this->_inFixed >= rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator<=( Fixed const & rhs ) {
	if (this->_inFixed <= rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator==( Fixed const & rhs ) {
	if (this->_inFixed == rhs.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator!=( Fixed const & rhs ) {
	if (this->_inFixed != rhs.getRawBits())
		return true;
	else
		return false;
}

Fixed::Fixed(int const n) : _inFixed(n << this->_inscFrac) {
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _inFixed(roundf(n * (1 << this->_inscFrac))) {
	//std::cout << "Float constructor called" << std::endl;
}

Fixed		Fixed::operator+(Fixed const & src) {
	//std::cout << "Addition operator called" << std::endl;
	Fixed res = Fixed(*this);
	res.setRawBits(this->toFloat() + src.toFloat());
	return (res);
}

Fixed		Fixed::operator-(Fixed const & rhs) {
	//std::cout << "Subtraction operator called" << std::endl;
	Fixed res = Fixed(*this);
	res.setRawBits(this->toFloat() - rhs.toFloat());
	return (res);
}

Fixed 		Fixed::operator*(Fixed const & rhs) {
	//std::cout << "Multiplication operator called" << std::endl;
	Fixed res = Fixed(this->toFloat() * rhs.toFloat());
	return (res);
}

Fixed 		Fixed::operator/(Fixed const & rhs) {
	//std::cout << "Division operator called" << std::endl;
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed 		Fixed::operator++(int) {
	//std::cout << "Post increment operator called" << std::endl;
	Fixed temp = Fixed(*this);
	_inFixed++;
	return (temp);
}

Fixed &		Fixed::operator++() {
	//std::cout << "Increment operator called" << std::endl;
	++(_inFixed);
	return (*this);
}

Fixed 		Fixed::operator--(int) {
	//std::cout << "Post decrement operator called" << std::endl;
	Fixed temp = Fixed(*this);
	_inFixed--;
	return (temp);
}

Fixed &		Fixed::operator--() {
	//std::cout << "Decrement operator called" << std::endl;
	--(_inFixed);
	return (*this);

}

int		Fixed::getRawBits(void) const {
	return this->_inFixed;
}

void	Fixed::setRawBits(int const raw) {
	this->_inFixed = raw;
}

float	Fixed::toFloat( void ) const {
	return this->_inFixed / (float)(1 << this->_inscFrac);
}

int		Fixed::toInt( void ) const {
	return this->_inFixed / (1 << this->_inscFrac);
}

Fixed const &		Fixed::max( Fixed const & solve1, Fixed const & solve2 ) {
	if (solve1.toFloat() > solve2.toFloat())
		return solve1;
	else
		return solve2;
}
Fixed const &		Fixed::min( Fixed const & solve1, Fixed const & solve2 ) {
	if (solve1.toFloat() < solve2.toFloat())
		return solve1;
	else
		return solve2;
}

Fixed &		min( Fixed & solve1, Fixed & solve2 ) {
	if (solve1.toFloat() < solve2.toFloat())
		return solve1;
	else
		return solve2;
}

Fixed &		max( Fixed & solve1, Fixed & solve2 ) {
	if (solve1.toFloat() > solve2.toFloat())
		return solve1;
	else
		return solve2;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
