#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( const FragTrap &base );
	FragTrap &operator=( const FragTrap &other );
	~FragTrap( void );

	void	highFiveGuys( void );

};

std::ostream&	operator<<(std::ostream &out, const FragTrap &other);

#endif