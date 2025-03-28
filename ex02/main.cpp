/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:59:45 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/28 16:48:53 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
    std::cout << "==================== Test1 ====================\n" << std::endl;

    // ClapTrap default and parameterized construction
    ClapTrap fighter1;
    ClapTrap fighter2("Bob");

    // Checking if attack reduces energy points and not below 0
    fighter1.attack(fighter2.getName());
    fighter1.attack(fighter2.getName());
    fighter2.takeDamage(10);
    fighter2.takeDamage(5);

    // Test: Check that takeDamage doesn't drop below 0 hit points
    fighter2.takeDamage(5);    // Still 0 HP, shouldn't go negative
    fighter2.beRepaired(5);    // Repair should succeed with valid energy

    fighter1.attack(fighter2.getName());
    fighter1.attack(fighter2.getName());
    fighter1.attack(fighter2.getName());  // Should show no attack possible if no energy

    fighter1.beRepaired(5);  // Repair should succeed as it has energy
    fighter1.beRepaired(100);  // Should fail since it doesn't have enough energy

    // Checking behavior after taking damage and repairing
    fighter1.takeDamage(8); // HP reduced to 2
    fighter1.beRepaired(5); // HP increased to 7 (no more than max hit points)

    // Checking assignments
    ClapTrap fighter3;
    fighter3 = fighter2;  // ClapTrap assignment operator
    std::cout << fighter2 << std::endl;
    std::cout << fighter3 << std::endl;

    std::cout << "\n==================== Test2 ====================\n" << std::endl;

    // FragTrap construction
    FragTrap player1("Capone");
    FragTrap player2;
    FragTrap player3(player1);
    FragTrap player4("Joji");

    player1.attack(player4.getName());
    player4.takeDamage(player1.getAttackDamage());
    player2 = player4;

    // Test FragTrap's behavior after taking damage
    player1.takeDamage(50);
    player1.beRepaired(10);

    // Testing FragTrap's attack behavior when energy is depleted
    player1.attack(player4.getName());
    player1.attack(player4.getName());

    // Test FragTrap's highFiveGuys function
    player3.highFiveGuys();

    // FragTrap repair test with insufficient energy
    player1.takeDamage(100);  // Reduce HP to 0
    player1.beRepaired(50);   // No energy to repair, should display error message

    // FragTrap's energy depletion and repair validation
    player4.takeDamage(20);
    player4.beRepaired(30);
    std::cout << player4 << std::endl;
    return 0;
}
