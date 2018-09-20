/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:31:08 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/07 18:14:29 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_inFixed;
		static const int	_inscFrac = 8;

	public:
		Fixed( void );
		Fixed( Fixed const & rhs );
		Fixed( const int n);
		Fixed( const float n);
		~Fixed( void );

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;
		Fixed &		operator=( Fixed const & rhs );
		bool		operator>( Fixed const & rhs );
		bool		operator<( Fixed const & rhs );
		bool		operator>=( Fixed const & rhs );
		bool		operator<=( Fixed const & rhs );
		bool		operator==( Fixed const & rhs );
		bool		operator!=( Fixed const & rhs );
		Fixed		operator+( Fixed const & rhs );
		Fixed		operator-( Fixed const & rhs );
		Fixed		operator*( Fixed const & rhs );
		Fixed		operator/( Fixed const & rhs );
		Fixed &		operator++();
		Fixed &		operator--();
		Fixed		operator++(int);
		Fixed		operator--(int);
		static Fixed const &	min( Fixed const & solve1, Fixed const & solve2 );
		static Fixed const &	max( Fixed const & solve1, Fixed const & solve2 );
};

std::ostream &  operator<<( std::ostream & o, Fixed  const & rhs);
Fixed &		max( Fixed & solve1, Fixed & solve2 );
Fixed &		min( Fixed &  solve1, Fixed & solve2 );

#endif
