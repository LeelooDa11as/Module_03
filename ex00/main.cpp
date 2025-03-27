#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap A("Bob");
	ClapTrap B;
	B.setName("");
	B.getName();

	A.attack("John");
	A.setAttackDamage(2);
	A.attack("John");
	//A.takeDamage(1);
	//A.takeDamage(2);
	A.beRepaired(1);

	return (0);

	return 1;
}