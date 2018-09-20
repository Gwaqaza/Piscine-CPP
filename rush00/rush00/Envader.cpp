/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Envader.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:36:24 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:36:28 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Envader.hpp"
#include <ncurses.h>
#include <cstdlib>

Envader::Envader( void ) : Character() {
}

Envader::Envader(int x, int y) : Character(x, y){

	char	form[2] = {'X', 'C'};
	_form = form[rand() % 2];
}

Envader::Envader(Envader const & src) : Character(src.getX(), src.getY()){

}


Envader::~Envader( void ) {

}

bool 	Envader::move( int timeFrameCount ) {
	if (_x >= 10)
	{
		if (timeFrameCount % 2 == 0){ 
			_x--;
		}
		return TRUE;
	}
	else
		return FALSE;
}
