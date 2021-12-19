/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 20:11:43 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.class.hpp"

Cat::Cat(void): Animal("cat")
{
	std::cout << "This animal is a cat." << std::endl;
	this->_brain = new Brain();
	this->_brain->add_idea("Sleeeeeep ...");
	this->_brain->add_idea("Scorn !");
	this->_brain->add_idea("Sleeeeeep ...");
	this->_brain->add_idea("Eat ! Now !");
	this->_brain->add_idea("Dominate the world ...");
}

Cat::Cat(Cat const &cat): Animal(cat)
{
	this->_brain = new Brain();
	*this = cat;
	std::cout << "A copy of a cat of type " << this->_type
		<< " has been created." << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "A cat has been destroyed." << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignation operator called." << std::endl;
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

Brain const	*Cat::get_brain(void) const
{
	return (this->_brain);
}

void	Cat::make_sound(void) const
{
	std::cout << "Meeeeeooooow!" << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, Cat const &rhs)
{
	ostream << rhs.get_type() << " : " << rhs.get_brain()->to_str();
	return (ostream);
}
