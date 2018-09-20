/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:34:22 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:34:29 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "Display.hpp"

Bullet::Bullet( void ) : Character() {
}

Bullet::Bullet(int x, int y) : Character(x, y) {
	_form = '*';
}

Bullet::Bullet(Bullet const & src) : Character(src.getX(), src.getY()) {

}

Bullet::~Bullet( void ) {

}

bool 	Bullet::move( int timeFrameCount) {

	if (_x > SCRWIDTH + SCRSTARTX - 3)
			return FALSE;
	if (timeFrameCount % 1 == 0){
		_x++;
	} 
	return TRUE;
}
