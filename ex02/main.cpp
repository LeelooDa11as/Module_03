/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:59:45 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/27 19:40:34 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
    std::cout << "====== ClapTrap Tests ======" << std::endl;
    ClapTrap clap1("ClapOne");
    ClapTrap clap2;

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    //std::cout << clap2 << std::endl;
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    //std::cout << clap2 << std::endl;
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());
    clap1.attack(clap2.getName());
    clap1.attack(clap2.getName());
    clap1.attack(clap2.getName());
    clap1.attack(clap2.getName());
    clap2.beRepaired(10);
    clap2.takeDamage(clap1.getAttackDamage());

    clap2.beRepaired(5);
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAttackDamage());

    std::cout << std::endl;

    std::cout << "====== Testing Setters and Getters ======" << std::endl;
    std::cout << "Before changes: " << clap1 << std::endl;
    
    clap1.setHitPoints(50);
    clap1.setEnergyPoints(20);
    clap1.setAttackDamage(10);

    std::cout << "After changes: " << clap1 << std::endl;

    if (clap1.getHitPoints() == 50 &&
        clap1.getEnergyPoints() == 20 &&
        clap1.getAttackDamage() == 10) {
        std::cout << "✅ Setters and getters work correctly!" << std::endl;
    } else {
        std::cout << "❌ Setters or getters might have an issue!" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== FragTrap Tests ======" << std::endl;
    FragTrap frag1("FragOne");
    FragTrap frag2("FragTwo");

    frag1.attack(frag2.getName());
    frag2.takeDamage(frag1.getAttackDamage());

    frag2.beRepaired(10);
    frag1.highFiveGuys();

    std::cout << std::endl;

    std::cout << "====== Copy and Assignment Tests ======" << std::endl;
    ClapTrap copyClap = clap1; // Copy constructor
    copyClap.attack("Random Target");

    FragTrap copyFrag(frag1); // Copy constructor
    copyFrag.attack("Another Target");

    ClapTrap assignClap;
    assignClap = clap2; // Assignment operator
    assignClap.attack("Assigned Target");

    FragTrap assignFrag;
    assignFrag = frag2; // Assignment operator
    assignFrag.attack("Assigned Frag Target");

    std::cout << "====== End of Tests ======" << std::endl;
    return 0;
}
