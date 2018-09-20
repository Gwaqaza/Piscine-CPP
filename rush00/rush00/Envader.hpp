/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Envader.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmphephu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:36:56 by mmphephu          #+#    #+#             */
/*   Updated: 2018/06/10 14:37:03 by mmphephu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

#ifndef Envader_HPP
 #define Envader_HPP

class Envader : public Character
{
public:
	Envader(void);
	Envader(int x, int y);
	Envader(Envader const & src);
	~Envader();
	using Character::operator=;
	bool	move( int );

};

#endif
