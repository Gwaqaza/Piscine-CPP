/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:14:30 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/07 16:51:14 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <stdlib.h>

class Fixed {
	private:
		int					_inFixed;
		static const int	_inscFrac = 8;
	
	public:
		Fixed( void );
		Fixed( Fixed const & rhs );
		~Fixed( void );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed & operator=( Fixed const & rhs );
};

#endif
