/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:48:41 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/08 17:55:25 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(randomName()), _HP(100), _maxHP(100), _EP(100), _maxEP(100), _level(1), _MAD(30), _RAD(20), _ADR(5) {
    std::cout << "<" << this->_name << ">A new ClapTrap is born.\n";
}

ClapTrap::ClapTrap(unsigned int hp, unsigned int maxHP, unsigned int ep, unsigned int maxEP, unsigned int level, unsigned int MAD, unsigned int RAD, unsigned int ADR) : _name(randomName()), _HP(hp), _maxHP(maxHP), _EP(ep), _maxEP(maxEP), _level(level), _MAD(MAD), _RAD(RAD), _ADR(ADR) {
    std::cout << "<" << this->_name << ">A new ClapTrap is born.\n";
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int maxHP, unsigned int ep, unsigned int maxEP, unsigned int level, unsigned int MAD, unsigned int RAD, unsigned int ADR) : _name(name), _HP(hp), _maxHP(maxHP), _EP(ep), _maxEP(maxEP), _level(level), _MAD(MAD), _RAD(RAD), _ADR(ADR) {
    std::cout << "<" << this->_name << ">A new ClapTrap is born.\n";
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
    std::cout << "<" << this->_name << ">Your ClapTrap has been cloned.\n";
}

ClapTrap &  ClapTrap::operator=(ClapTrap const & src) {
    this->_HP = src.getHP();
    this->_EP = src.getEP();
    this->_level = src.getLevel();
    this->_name = src.getName();
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "<" << this->_name << ">A ClapTrap is no more.\n";
}

void	ClapTrap::rangedAttack(std::string const & target) {
    std::cout << this->_name << " sniped " << target << " causing " << this->_RAD - this->_ADR << " ranged damage.\n";
}

void	ClapTrap::meleeAttack(std::string const & target) {
    std::cout << this->_name << " pwnd " << target << " causing " << this->_MAD - this->_ADR<< " melee damage.\n";
}

void	ClapTrap::takeDamage(unsigned int amount) {
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

void ClapTrap::beRepaired(unsigned int amount) {
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

unsigned int	ClapTrap::getHP() const {
    return (this->_HP);
}

unsigned int	ClapTrap::getMaxHP() const {
    return (this->_maxHP);
}

unsigned int	ClapTrap::getEP() const {
    return (this->_EP);
}

unsigned int	ClapTrap::getMaxEP() const {
    return (this->_maxEP);
}

unsigned int	ClapTrap::getLevel() const {
    return (this->_level);
}

std::string		ClapTrap::getName() const {
    return (this->_name);
}

unsigned int	ClapTrap::getMAD() const {
    return (this->_MAD);
}

unsigned int	ClapTrap::getRAD() const {
    return (this->_RAD);
}

unsigned int	ClapTrap::getADR() const {
    return (this->_ADR);
}

std::string     ClapTrap::randomName() const {
    std::string names[] = {"Fragger", "Bukko", "Fancy Jack", "Chimmy Changa", "2Lit2Quit", "SL4P-TP", "F4P-TP", "Mega Interplanetary Ninja Assassin Claptrap", "CU5TM-TP", "L33T-TP"};
    return names[(rand() % 10)];
}
