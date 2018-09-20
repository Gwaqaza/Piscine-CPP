/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:38:14 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:38:18 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hero.hpp"
#include "Display.hpp"
#include <ncurses.h>

Hero::Hero( void ) : Character(){
	_form = '>';
	life = 3;
}

Hero::Hero(int x, int y) : Character(x, y){
	_form = '>';
	life = 3;
}

Hero::Hero(Hero const & src) : Character(src.getX(), src.getY()){

}


Hero::~Hero( void ) {

}

bool 	Hero::move( int timeFrameCount) {
	if (timeFrameCount == 0)
		return 1;
	return 0;
}

void 	Hero::move( int const input, int timeFrameCount) {
	if (timeFrameCount){
		if (input == KEY_UP && _y > (SCRSTARTY + 1))
			_y--;
		else if (input == KEY_DOWN && _y < (SCRSTARTY + SCRHEIGHT - 2))
			_y++;
	}
}
