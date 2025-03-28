/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:41:40 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/28 16:41:42 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

//------------------------------- Constructors & desctructor --------------------------------------------------
ClapTrap::ClapTrap( void ):_name("Random dude"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << getName() << " default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string name ) :_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << getName() << " string constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage ) : \
 _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
	std::cout << "ClapTrap " << getName() << " full constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( const ClapTrap &base ) :_name(base._name), _hitPoints(base._hitPoints), _energyPoints(base._energyPoints), _attackDamage(base._attackDamage) {
	std::cout << "ClapTrap " << getName() << " copy constructor called" << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &other ) {
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	std::cout << "ClapTrap " << getName() << " assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << getName() << " destructor called" << std::endl;
	return;
}

//------------------------------- Setters and getters -----------------------------------------------------
void	ClapTrap::setName( std::string name ) {
	this->_name = name;
	return;
}

std::string	ClapTrap::getName( void )const {
	//std::cout << "name is: " <<_name << std::endl;
	return (this->_name);
}

void			ClapTrap::setHitPoints( unsigned int hitPoints ) {
	this->_hitPoints = hitPoints;
	//std::cout << getName() << "'s hit points are set to " << getHitPoints() << std::endl;
	return;
}

unsigned int	ClapTrap::getHitPoints( void )const {
	//std::cout << "ClapTrap " << "getHitPoints function called" << std::endl;
	return (this->_hitPoints);
}

void			ClapTrap::setEnergyPoints( unsigned int energyPoints ) {
	this->_energyPoints = energyPoints;
	//std::cout << "ClapTrap " << getName() << "'s energy points are set to " << getEnergyPoints() << std::endl;
	return;
}

unsigned int	ClapTrap::getEnergyPoints( void )const {
	//std::cout << "ClapTrap " << "getHitPoints function called" << std::endl;
	return (this->_energyPoints);
}

void			ClapTrap::setAttackDamage( unsigned int attackDamage ) {
	this->_attackDamage = attackDamage;
	//std::cout << "ClapTrap " << getName() << "'s attack damage is up to " << getAttackDamage() << std::endl;
	return;
}

unsigned int	ClapTrap::getAttackDamage( void )const {
	//std::cout << "ClapTrap " << "getHitPoints function called" << std::endl;
	return (this->_attackDamage);
}
//------------------------------- Player functions ---------------------------------------------------------

void			ClapTrap::attack( const std::string &target ) {
	std::cout << RED << "ClapTrap " << getName() << RESET;
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
		std::cout << " has no energy or hit points to attack" << std::endl;
	else {
		std::cout << " attacks " << target << " who lost " << this->getAttackDamage() << " points of damage" << std::endl;
		this->_energyPoints = this->getEnergyPoints() - 1;
	}
	std::cout << *this << std::endl;
	return;

}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << RED << "ClapTrap " << getName() << " is already destroyed!" << RESET << std::endl;
        return;
    }
    if (amount >= this->_hitPoints)
       this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << RED << "ClapTrap " << getName() << " took " << amount << " damage! Remaining HP: " << _hitPoints << RESET << std::endl;
	std::cout << *this << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << YELLOW << "ClapTrap " << getName() << " has no energy to repair!" << RESET << std::endl;
		return;
	}
	else if (amount > this->_energyPoints) {

		std::cout << YELLOW << "ClapTrap " << getName() << " does not have enough energy points to repair!" << RESET << std::endl;
		std::cout << *this << std::endl;
		return;
	}
	else 
	{
		this->_hitPoints += amount;
		this->_energyPoints -= amount;
		std::cout << GREEN << "ClapTrap " << getName() << " repaired itself for " << amount << " HP! Remaining Energy: " << _energyPoints << RESET << std::endl;

	}
	std::cout << *this << std::endl;
	return;
}

//------------------------------- Printing the class --------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const ClapTrap& base) {
    out << BOLD << CYAN << "ClapTrap " << base.getName() << RESET
        << " | " << RED << "HP: " << base.getHitPoints() << RESET
        << " | " << GREEN << "EP: " << base.getEnergyPoints() << RESET
        << " | " << YELLOW << "ATK: " << base.getAttackDamage() << RESET;
    return out;
}
