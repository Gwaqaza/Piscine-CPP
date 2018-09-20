/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:47:34 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/08 17:28:18 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name(randomName()), _HP(100), _maxHP(100), _EP(50), _maxEP(50), _level(1), _MAD(20), _RAD(15), _ADR(3) {
	std::cout << "<" << this->_name << ">This time it'll be awesome, I promise!\n";
}

ScavTrap::ScavTrap(std::string name) : _name(name), _HP(100), _maxHP(100), _EP(50), _maxEP(50), _level(1), _MAD(20), _RAD(15), _ADR(3) {
	std::cout << "<" << this->_name << ">Hey everybody! Check out my package!\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
	std::cout << "<" << this->_name << ">Glitching weirdness is a term of endearment, right?\n";
}

ScavTrap &  ScavTrap::operator=(ScavTrap const & src) {
	this->_HP = src.getHP();
	this->_EP = src.getEP();
	this->_level = src.getLevel();
	this->_name = src.getName();
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "<" << this->_name << ">My robotic flesh! AAHH!\n";
}

void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << this->_name << " sniped " << target << " causing " << this->_RAD - this->_ADR << " ranged damage.\n";
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << this->_name << " pwnd " << target << " causing " << this->_MAD - this->_ADR<< " melee damage.\n";
}

void	ScavTrap::takeDamage(unsigned int amount) {
	amount = (amount - this->_ADR);
	if (this->_HP > amount) {
		this->_HP = this->_HP - amount;
		std::cout << this->_name << " took " << amount << " damage.\n";
	}
	else {
		this->_HP = 0;
		std::cout << "<" << this->_name << ">If only my chassis... weren't made of recycled human body parts! Wahahaha!\n";
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {
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

void    ScavTrap::challengeNewcomer(std::string const & target) {
	int i = rand()  % 3;

	if (this->_EP < 25) {
		std::cout << this->_name << " doesn't have enough EP.\n";
	}
	else if (this->_HP == 0) {
		std::cout << this->_name << " is already a pile of rubble.\n";
	}
	else {
		this->_EP -= 25;
		std::cout << "<" << this->_name << "> Hey " << target << "! Let's see what you can really do huh?\n";
		if (i == 0) {
			std::cout << "<" << this->_name << ">Bring me Red Bellys big red belly!\n";
		}
		else if (i == 1) {
			std::cout << "<" << this->_name << ">Beat me at a dance off!\n";
		}
		else if (i == 2) {
			std::cout << "<" << this->_name << ">Bring me FragTraps eye...\n";
		}
	}
}

unsigned int    ScavTrap::getHP() const {
	return (this->_HP);
}

unsigned int    ScavTrap::getMaxHP() const {
	return (this->_maxHP);
}

unsigned int    ScavTrap::getEP() const {
	return (this->_EP);
}

unsigned int    ScavTrap::getMaxEP() const {
	return (this->_maxEP);
}

unsigned int    ScavTrap::getLevel() const {
	return (this->_level);
}

std::string     ScavTrap::getName() const {
	return (this->_name);
}

unsigned int    ScavTrap::getMAD() const {
	return (this->_MAD);
}

unsigned int    ScavTrap::getRAD() const {
	return (this->_RAD);
}

unsigned int    ScavTrap::getADR() const {
	return (this->_ADR);
}

std::string     ScavTrap::randomName() const {
	std::string names[] = {"Fragger", "Bukko", "Fancy Jack", "Chimmy Changa", "2Lit2Quit", "SL4P-TP", "F4P-TP", "Mega Interplanetary Ninja Assassin Claptrap", "CU5TM-TP", "L33T-TP"};
	return names[(rand() % 10)];
}
