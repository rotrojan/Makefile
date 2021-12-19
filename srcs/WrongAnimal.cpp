/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 14:41:47 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal(std::string const &type): _type(type)
{
	std::cout << "A new wrong animal has been created." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wronganimal)
{
	*this = wronganimal;
	std::cout << "A copy of a wrong animal of type " << this->_type
		<< " has been created." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "A wrong animal has been destroyed." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal assignation operator called." << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string const	&WrongAnimal::get_type(void) const
{
	return (this->_type);
}

void	WrongAnimal::make_sound(void) const
{
	std::cout << "Wrong animal blank sound." << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, WrongAnimal const &rhs)
{
	ostream << rhs.get_type();
	return (ostream);
}
