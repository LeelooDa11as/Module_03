/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:42:52 by kkoval            #+#    #+#             */
/*   Updated: 2025/03/28 16:42:55 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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