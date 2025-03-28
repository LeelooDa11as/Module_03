#include "ScavTrap.hpp"

int	main(void)
{
	//Different constructors called
	std::cout << "==================== Test1 ====================" << std::endl;
    ScavTrap	player1("Capone");
    ScavTrap	player2;
	ScavTrap	player3(player1);
	ScavTrap	player4("Joji");

	player1.attack(player4.getName());
	player4.takeDamage(player1.getAttackDamage());
	player2 = player4;

	/*std::cout << "======  ======" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		 clap1.attack(clap2.getName());
    	clap2.takeDamage(clap1.getAttackDamage());
	}

	for (int i = 0; i < 11; i++)
		clap1.attack(clap2.getName());
	
	for (int i = )
	std::cout << "====== Test2 ======" << std::endl;
	return 1;
	//std::cout << Figther1 << std::endl;*/
	return (0);
}