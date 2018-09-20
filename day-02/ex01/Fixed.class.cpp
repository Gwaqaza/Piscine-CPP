/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:29:06 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/07 17:21:15 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) {
	this->_inFixed = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
	return;
}

Fixed &		Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_inFixed = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(int const n) : _inFixed(n << this->_inscFrac) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _inFixed(roundf(n * (1 << this->_inscFrac))) {
	std::cout << "Float constructor called" << std::endl;
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

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
