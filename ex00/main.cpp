/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:41:05 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/28 16:41:07 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	player1;
	ClapTrap	player2("Bob");
	
	//checks attack and be repaired
	player1.attack(player2.getName());
	player1.attack(player2.getName());
	player1.beRepaired(2);
	player2.takeDamage(2);
	player2.takeDamage(10);
	player2.takeDamage(1);

	ClapTrap	player3;
	player3 = player2;
	std::cout << player2 << std::endl;
	std::cout << player3 << std::endl;
	return (0);
}