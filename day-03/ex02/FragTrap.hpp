/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:26:37 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/08 17:18:21 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <string>

class FragTrap {

	private:
		std::string		_name;
		unsigned int	_HP;
		unsigned int	_maxHP;
		unsigned int	_EP;
		unsigned int	_maxEP;
		unsigned int	_level;
		unsigned int	_MAD;
		unsigned int	_RAD;
		int				_ADR;

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		void	rangedAttack( std::string const & target );
		void	meleeAttack( std::string const & target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
		FragTrap &		operator=(FragTrap const & src);
		unsigned int	getHP() const;
		unsigned int	getMaxHP() const;
		unsigned int	getEP() const;
		unsigned int	getMaxEP() const;
		unsigned int	getLevel() const;
		std::string		getName() const;
		unsigned int	getMAD() const;
		unsigned int	getRAD() const;
		unsigned int	getADR() const;
		void			vaulthunter_dot_exe(std::string const & target);
		std::string		randomName() const;
};

#endif
