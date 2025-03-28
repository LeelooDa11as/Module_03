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