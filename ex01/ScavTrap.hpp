#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <iomanip>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    public:
    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( ScavTrap const &base );
    ScavTrap &operator=(ScavTrap const &other);
    ~ScavTrap( void );

    //functions:
    
    void    guardGate( void ); //ScavTrap Have netered in Gate keeper mode
    void    attack( const std::string &target );

};

std::ostream& operator<<(std::ostream& out, const ScavTrap& other);


#endif