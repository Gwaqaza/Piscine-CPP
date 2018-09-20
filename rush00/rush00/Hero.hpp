/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hero.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:38:27 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:38:34 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

#ifndef HERO_HPP
# define HERO_HPP


class Hero : public Character
{
public:
	Hero(void);
	Hero(int x, int y);
	Hero(Hero const & src);
	~Hero();
	using Character::operator=;
	bool	move( int );
	void	move( int const, int const);
	char 	getForm();
	int		life;

private:
};

#endif
