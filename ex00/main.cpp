#include "ClapTrap.hpp"

int	main( void )
{
	//checks that attack, repair and takeDamage do not work once reached 0 points
	std::cout << "====== Test1 ======" << std::endl;
    ClapTrap clap1("ClapOne");
    ClapTrap clap2;

	std::cout << "======  ======" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		 clap1.attack(clap2.getName());
    	clap2.takeDamage(clap1.getAttackDamage());
	}

	for (int i = 0; i < 11; i++)
		clap1.attack(clap2.getName());
   
   
	std::cout << "====== Test2 ======" << std::endl;
	return 1;
}