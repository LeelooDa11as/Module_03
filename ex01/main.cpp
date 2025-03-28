/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:41:57 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/28 16:41:59 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	//checks that the parent it still funcional
	std::cout << "==================== Test1 ====================\n" << std::endl;
	ClapTrap	fighter1;
	ClapTrap	fighter2("Bob");
	
	//checks attack and be repaired
	fighter1.attack(fighter2.getName());
	fighter1.attack(fighter2.getName());
	fighter1.beRepaired(2);
	fighter2.takeDamage(2);
	fighter2.takeDamage(10);
	fighter2.takeDamage(1);

	ClapTrap	fighter3;
	fighter3 = fighter2;
	std::cout << fighter2 << std::endl;
	std::cout << fighter3 << std::endl;

	//checking child cnstructors and functions
	std::cout << "\n==================== Test2 ====================\n" << std::endl;
    ScavTrap	player1("Capone");
    ScavTrap	player2;
	ScavTrap	player3(player1);
	ScavTrap	player4("Joji");

	player1.attack(player4.getName());
	player4.takeDamage(player1.getAttackDamage());
	player2 = player4;

	// Test the repair scenario with ScavTrap
	player2.beRepaired(5);  // Player2 should be able to repair if enough energy
	player2.takeDamage(15); // Player2 should take damage and not go below 0 HP
	player2.attack(player4.getName());  // Attack after damage

	// Check that ScavTrap does not perform attack if it has no energy or HP
	player2.takeDamage(100);  // Reduce HP to 0
	player2.attack(player4.getName());  // No attack possible, should show the warning

	// Test ScavTrap's guardGate function
	player1.guardGate();
	return (0);
}