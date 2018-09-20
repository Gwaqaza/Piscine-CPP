/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:35:07 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:35:12 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#ifndef Character_HPP
# define Character_HPP


class Character
{
public:

	Character(void);
	Character(int x, int y);
	Character(Character const & src);
	virtual ~Character();
	
	Character const &	operator=(Character const & rdh);
	virtual bool	move( int ) = 0;

	bool colision(Character*&);
	virtual void toPrint();
	int		getX( void ) const ;
	int		getY( void ) const ;

protected:

	int _x;
	int _y;
	char _form;
};

#endif
