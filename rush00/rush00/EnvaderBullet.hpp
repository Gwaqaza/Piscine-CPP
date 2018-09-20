/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnvaderBullet.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:37:53 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:37:57 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

#ifndef Invader_Bullet_HPP
 #define Invader_Bullet_HPP

class EnvaderBullet : public Character
{
public:
	EnvaderBullet(void);
	EnvaderBullet(int x, int y);
	EnvaderBullet(EnvaderBullet const & src);
	~EnvaderBullet();
	using Character::operator=;
	bool	move( int );
	bool colision(Character const & elem);
};

#endif
