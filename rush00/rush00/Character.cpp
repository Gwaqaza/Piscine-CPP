/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:34:53 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:35:01 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <ncurses.h>
#include <iostream>

Character::Character( void ) : _x(10), _y(10), _form(' ') {}

Character::Character(int x, int y) : _x(x), _y(y),  _form(' ') {}

Character::Character(Character const & src) : _x(src._x), _y(src._y), _form(src._form) {}

Character::~Character( void ) {}

Character const &	Character::operator=(Character const & rhs) {

	if (this != &rhs) {
		_form = rhs._form;
		_x = rhs._x;
		_y = rhs._y;
	}
	return *this;
}

int		Character::getX( void ) const {

	return this->_x;
}

int		Character::getY( void ) const {

	return this->_y;
}

void	Character::toPrint() {

	char	form[2] = {_form, 0};

	if (form[0] == 'X')
	{
		attron(COLOR_PAIR(5));
	    mvprintw(this->_y, this->_x, form);
		attroff(COLOR_PAIR(5));
	}
	else if (form[0] == 'C')
	{
		attron(COLOR_PAIR(1));
	    mvprintw(this->_y, this->_x, form);
		attroff(COLOR_PAIR(1));
	}
	else if (form[0] == '>')
	{
		attron(COLOR_PAIR(4));
	    mvprintw(this->_y, this->_x, form);
		attroff(COLOR_PAIR(4));
	}
	else if (form[0] == '-')
	{
		attron(COLOR_PAIR(2));
	    mvprintw(this->_y, this->_x, form);
		attroff(COLOR_PAIR(2));
	}
	else
	    mvprintw(this->_y, this->_x, form);
}

bool	Character::colision(Character*& elem) {

	return (_x >= elem->getX() && _y == elem->getY());
}
