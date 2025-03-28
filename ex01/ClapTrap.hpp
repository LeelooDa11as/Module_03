/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:41:49 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/28 16:41:52 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

class ClapTrap
{
	public:

	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage );
	ClapTrap( const ClapTrap &base );
	ClapTrap &operator=( const ClapTrap &other );
	~ClapTrap( void );


	void			setName( std::string name );
	std::string		getName( void )const;
	void			setHitPoints( unsigned int hitPoints );
	unsigned int	getHitPoints( void )const;
	void			setEnergyPoints( unsigned int energyPoints );
	unsigned int	getEnergyPoints( void )const;
	void			setAttackDamage( unsigned int attackDamage );
	unsigned int	getAttackDamage( void )const;


	void			attack( const std::string &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );


	protected:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

std::ostream&	operator<<(std::ostream &out, const ClapTrap &other);

#endif