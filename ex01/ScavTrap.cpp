#include "ScavTrap.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

//------------------------------- Constructors & desctructor --------------------------------------------------
ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap " << getName() << " default constructor called" << std::endl;
	//this->setName("Random dude");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << *this << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	std::cout << "ScavTrap " << getName() << " string constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << *this << std::endl;
	return;
}

ScavTrap::ScavTrap( const ScavTrap &base ) : ClapTrap( base ) {
	std::cout << "ScavTrap " << getName() << " copy constructor called" << std::endl;
	std::cout << *this << std::endl;
	return;
}

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

void    ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << getName() << " is now behind the high gate" << std::endl;
	return;
}

void			ScavTrap::attack( const std::string &target ) {
	std::cout << RED << "ScavTrap " << getName() << RESET;
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
		std::cout << " has no energy or hit points to attack" << std::endl;
	else {
		std::cout << " attacks " << target << " who lost " << this->getAttackDamage() << " points of damage" << std::endl;
		this->_energyPoints = this->getEnergyPoints() - 1;
	}
	std::cout << *this << std::endl;
	return;

}

//------------------------------- Printing the class --------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const ScavTrap& base) {
    out << BOLD << CYAN << "ScavTrap " << base.getName() << RESET
        << " | " << RED << "HP: " << base.getHitPoints() << RESET
        << " | " << GREEN << "EP: " << base.getEnergyPoints() << RESET
        << " | " << YELLOW << "ATK: " << base.getAttackDamage() << RESET;
    return out;
}
