/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 20:09:46 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.class.hpp"

Dog::Dog(void): Animal("dog")
{
	std::cout << "This animal is a dog." << std::endl;
	this->_brain = new Brain();
	this->_brain->add_idea("Play, play, play ...");
	this->_brain->add_idea("Eat, eat, eat ...");
	this->_brain->add_idea("Female, female, female ...");
	this->_brain->add_idea("Play, play, play ...");
	this->_brain->add_idea("Eat, eat, eat ...");
}

Dog::Dog(Dog const &dog): Animal(dog)
{
	this->_brain = new Brain();
	*this = dog;
	std::cout << "A copy of a dog of type " << this->_type
		<< " has been created." << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "A dog has been destroyed." << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignation operator called." << std::endl;
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

Brain const	*Dog::get_brain(void) const
{
	return (this->_brain);
}

void	Dog::make_sound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

std::ostream	&operator<<(std::ostream &ostream, Dog const &rhs)
{
	ostream << rhs.get_type() << " : " << rhs.get_brain()->to_str();
	return (ostream);
}
