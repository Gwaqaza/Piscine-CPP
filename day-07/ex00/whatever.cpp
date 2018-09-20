/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:14:22 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/13 16:39:57 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename S>
void	swap(S const & x, S const & y) {
	S temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename N>
N	const & min(N const & x, N const & y) {
	if (x < y)
		return x;
	else if (x == y)
		return y;
}

template <typename X>
X	const & max(X const & x, X const & y ) {
	return ( x > y ? x : y );
}

int		main( void ) {
	int a = 2;
	int b = 3;

	std::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << std::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << std::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << std::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << std::max( c, d ) << std::endl;

	return 0;
}
