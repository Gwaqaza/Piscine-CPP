/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:34:35 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:34:42 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

#ifndef Bullet_HPP
 #define Bullet_HPP

class Bullet : public Character
{
public:
	Bullet(void);
	Bullet(int x, int y);
	Bullet(Bullet const & src);
	~Bullet();
	using Character::operator=;
	bool	move( int );
	bool colision(Character const & );
};

#endif
