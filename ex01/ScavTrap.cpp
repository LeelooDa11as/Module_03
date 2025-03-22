#include "ScavTrap.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

//------------------------------- Constructors & desctructor --------------------------------------------------
ScavTrap::ScavTrap( void ) : ClapTrap("Random dude", 100, 50, 20) {
	std::cout << "ScavTrap " << getName() << " default constructor called" << std::endl;
	std::cout << *this << std::endl;

	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << getName() << " string constructor called" << std::endl;
	std::cout << *this << std::endl;
	return;
}

// To test
ScavTrap::ScavTrap( const ScavTrap &base ) : ClapTrap( base ) {
	std::cout << "ScavTrap " << getName() << " copy constructor called" << std::endl;
	std::cout << *this << std::endl;
	return;
}

//To test
ScavTrap	&ScavTrap::operator=( const ScavTrap &other ) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << getName() << " assignment constructor called" << std::endl;
	std::cout << *this << std::endl;
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << getName() << " destructor called" << std::endl;
	return;
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
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << GREEN << "ClapTrap " << getName() << " repaired itself for " << amount << " HP! Remaining Energy: " << _energyPoints << RESET << std::endl;
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
