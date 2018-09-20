/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:28:54 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/07 17:19:40 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <stdlib.h>
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
};

std::ostream &  operator<<( std::ostream & o, Fixed  const & rhs);

#endif
