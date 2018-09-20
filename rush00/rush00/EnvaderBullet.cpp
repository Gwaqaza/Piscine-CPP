/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnvaderBullet.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:37:21 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:37:28 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnvaderBullet.hpp"
 #include "Display.hpp"

EnvaderBullet::EnvaderBullet( void ) : Character() {
	_form = '-';
}

EnvaderBullet::EnvaderBullet(int x, int y) : Character(x, y) {
	_form = '-';
}

EnvaderBullet::EnvaderBullet(EnvaderBullet const & src) : Character(src.getX(), src.getY()) {

}

EnvaderBullet::~EnvaderBullet( void ) {

}

bool 	EnvaderBullet::move( int timeFrameCount) {

	if (_x < SCRSTARTX + 3)
			return FALSE;
	if (timeFrameCount % 1 == 0){
		_x--;
	} 
	return TRUE;
}
