/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:26:27 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/08 17:22:08 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : _name(randomName()), _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _MAD(30), _RAD(20), _ADR(5) {
	std::cout << "<" << this->_name << ">Look out everybody! Things are about to get awesome!\n";
}

FragTrap::FragTrap(std::string name) : _name(name), _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _MAD(30), _RAD(20), _ADR(5) {
	std::cout << "<" << this->_name << ">Let's get this party started!\n";
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
	std::cout << "<" << this->_name << ">Recompiling my combat code!\n";
}

FragTrap &  FragTrap::operator=(FragTrap const & src) {
	this->_HP = src.getHP();
	this->_EP = src.getEP();
	this->_level = src.getLevel();
	this->_name = src.getName();
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "<" << this->_name << ">Ahr gurgle gurgle urgh... d e a t h.\n";
}

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << this->_name << " sniped " << target << " causing " << this->_RAD - this->_ADR << " ranged damage.\n";
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << this->_name << " pwnd " << target << " causing " << this->_MAD - this->_ADR<< " melee damage.\n";
}

void	FragTrap::takeDamage(unsigned int amount) {
	amount = (amount - this->_ADR);
	if (this->_HP > amount) {
		this->_HP = this->_HP - amount;
		std::cout << this->_name << " took " << amount << " damage.\n";
	}
	else {
		this->_HP = 0;
		std::cout << "<" << this->_name << ">You got me! now I go bye bye :(\n";
	}
}

void	FragTrap::beRepaired(unsigned int amount) {
	unsigned int need;
	need = this->_maxHP - this->_HP;
	if (need >= amount) {
		this->_HP = this->_HP + amount;
		std::cout << this->_name << " gained " << amount << " HP.\n";
	}
	else if (need < amount && need != 0) {
		this->_HP = this->_HP + need;
		std::cout << this->_name << " gained " << need << " HP.\n";
	}
	else if (need == 0) {
		std::cout << this->_name << " has enough HP.\n";
	}
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int i = rand() % 5;

	if (this->_EP < 25) {
		std::cout << this->_name << " doesn't have enough EP.\n";
	}
	else if (this->_HP == 0) {
		std::cout << this->_name << " is already a pile of rubble.\n";
	}
	else {
		this->_EP -= 25;
		std::cout << "<" << this->_name << ">I have an IDEA!\n";
		if (i == 0) {
			std::cout << "<" << this->_name << ">How many ways can I say... THROWING GRENADE?!\n";
			std::cout << this->_name << " throws what can only be described as a waterbaloon from hell at " << target << " causing >9001 damage.\n";
		}
		else if (i == 1) {
			std::cout << "<" << this->_name << "> This could've gone better!\n";
			std::cout << this->_name << " misses " << target << " miserably causing 0 damage.\n";
		}
		else if (i == 2) {
			std::cout << "<" << this->_name << ">Wow, that actually worked?\n";
			beRepaired(10);
		}
		else if (i == 3) {
			std::cout << "<" << this->_name << ">Crack shot!\n";
			rangedAttack(target);
		}
		else if (i == 4) {
			std::cout << "<" << this->_name << ">Eat my metal ass!\n";
			meleeAttack(target);
		}
	}
}

unsigned int    FragTrap::getHP() const {
	return (this->_HP);
}

unsigned int    FragTrap::getMaxHP() const {
	return (this->_maxHP);
}

unsigned int    FragTrap::getEP() const {
	return (this->_EP);
}

unsigned int    FragTrap::getMaxEP() const {
	return (this->_maxEP);
}

unsigned int    FragTrap::getLevel() const {
	return (this->_level);
}

std::string     FragTrap::getName() const {
	return (this->_name);
}

unsigned int    FragTrap::getMAD() const {
	return (this->_MAD);
}

unsigned int    FragTrap::getRAD() const {
	return (this->_RAD);
}

unsigned int    FragTrap::getADR() const {
	return (this->_ADR);
}

std::string     FragTrap::randomName() const {
	std::string names[] = {"Fragger", "Bukko", "Fancy Jack", "Chimmy Changa", "2Lit2Quit", "SL4P-TP", "F4P-TP", "Mega Interplanetary Ninja Assassin Claptrap", "CU5TM-TP", "L33T-TP"};
	return names[(rand() % 10)];
}

