/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:37:30 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/27 18:19:36 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

FragTrap::FragTrap( void ) : ClapTrap("Random dude", 100, 100, 30) {
	std::cout << "FragTrap " << getName() << " default constructor called" << std::endl;
	std::cout << *this << std::endl;

	return;
}

FragTrap::FragTrap( std::string name ) : ClapTrap ( name, 100, 100, 30 ) {
	std::cout << "FragTrap " << getName() << " string constructor called" << std::endl;
	std::cout << *this << std::endl;
	return;
}

FragTrap::FragTrap( const FragTrap &base ) : ClapTrap( base ) {
	std::cout << "FragTrap " << getName() << " copy constructor called" << std::endl;
	std::cout << *this << std::endl;
	return;
}

FragTrap	&FragTrap::operator=( const FragTrap &other ) {
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << getName() << " assignment operator called" << std::endl;
	std::cout << *this << std::endl;
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
	return;
}

void	FragTrap::highFiveGuys( void ) {
	std::cout << "Hey buddy! High five for you :D" << std::endl;
	return;
}

//------------------------------- Printing the class --------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const FragTrap& base) {
    out << BOLD << CYAN << "FragTrap " << base.getName() << RESET
        << " | " << RED << "HP: " << base.getHitPoints() << RESET
        << " | " << GREEN << "EP: " << base.getEnergyPoints() << RESET
        << " | " << YELLOW << "ATK: " << base.getAttackDamage() << RESET;
    return out;
}
