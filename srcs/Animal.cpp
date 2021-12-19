/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 16:25:32 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.class.hpp"

Animal::Animal(std::string const &type): _type(type)
{
	std::cout << "A new animal has been created." << std::endl;
}

Animal::Animal(Animal const &animal)
{
	*this = animal;
	std::cout << "A copy of an animal of type " << this->_type
		<< " has been created." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "An animal has been destroyed." << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignation operator called." << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string const	&Animal::get_type(void) const
{
	return (this->_type);
}

void	Animal::make_sound(void) const
{
	std::cout << "Animal blank sound." << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, Animal const &rhs)
{
	ostream << rhs.get_type();
	return (ostream);
}
