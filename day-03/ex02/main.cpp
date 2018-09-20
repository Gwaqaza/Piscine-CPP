/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:32:38 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/08 17:54:20 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int		main( void ) {
	srand(time(NULL));
	srand(time(NULL));

	std::cout << "<ANNOUNCER>Lets have a showdown!\n\n";
	FragTrap frag1;
	FragTrap frag2 = FragTrap("OrigiFrag");
	FragTrap frag3 = FragTrap(frag1);
	ScavTrap scav1;
	ScavTrap scav2 = ScavTrap("OrigiFrag");
	ScavTrap scav3 = ScavTrap(scav1);

	std::cout << "\n<ANNOUNCER>The battle is about to begin!\n";
	std::cout << frag1.getName() << " has " << frag1.getHP() << " HP and " << frag1.getEP() << " EP\n";
	std::cout << frag2.getName() << " has " << frag2.getHP() << " HP and " << frag2.getEP() << " EP\n";
	std::cout << frag3.getName() << " has " << frag3.getHP() << " HP and " << frag3.getEP() << " EP\n";
	std::cout << scav1.getName() << " has " << scav1.getHP() << " HP and " << scav1.getEP() << " EP\n";
	std::cout << scav2.getName() << " has " << scav2.getHP() << " HP and " << scav2.getEP() << " EP\n";
	std::cout << scav3.getName() << " has " << scav3.getHP() << " HP and " << scav3.getEP() << " EP\n";

	frag1.rangedAttack(frag2.getName());
	frag2.takeDamage(frag1.getRAD());
	frag2.meleeAttack(frag3.getName());
	frag3.takeDamage(frag2.getMAD());
	scav1.rangedAttack(scav2.getName());
	scav2.takeDamage(scav1.getRAD());
	scav2.meleeAttack(scav3.getName());
	scav3.takeDamage(scav2.getMAD());

	std::cout << "\n<ANNOUNCER>Let's heal these little guys!\n";
	frag1.beRepaired(10);
	frag2.beRepaired(10);
	frag3.beRepaired(10);
	scav1.beRepaired(10);
	scav2.beRepaired(10);
	scav3.beRepaired(10);
	
	std::cout << "\n<ANNOUNCER>Time for some fun!\n";
	frag1.vaulthunter_dot_exe(frag3.getName());
	frag2.vaulthunter_dot_exe(frag3.getName());
	frag3.vaulthunter_dot_exe(frag2.getName());
	scav1.challengeNewcomer(scav3.getName());
	scav2.challengeNewcomer(scav3.getName());
	scav3.challengeNewcomer(scav2.getName());
	
	std::cout << "\n<ANNOUNCER>Okay, I've seen enough! Fire the EMP!\n";
	frag2.takeDamage(9001);
	frag1.takeDamage(9001);
	frag3.takeDamage(9001);
	scav2.takeDamage(9001);
	scav1.takeDamage(9001);
	scav3.takeDamage(9001);
	return 0;
}
