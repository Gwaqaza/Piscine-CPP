/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:14:46 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/07 16:25:11 by pmahele          ###   ########.fr       */
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

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_inFixed;
}

void	Fixed::setRawBits(int const raw) {
	this->_inFixed = raw;
}
