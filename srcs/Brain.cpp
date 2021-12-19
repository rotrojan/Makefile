/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:06 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 15:51:51 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.class.hpp"

Brain::Brain(void)
{
	std::cout << "A brain has been created." << std::endl;
}

Brain::Brain(Brain const &brain)
{
	*this = brain;
	std::cout << "A copy of a brain has been created." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "A brain has been destroyed." << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignation operator called." << std::endl;
	for (int i = 0; rhs._ideas[i].empty() != true; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

void	Brain::add_idea(std::string idea)
{
	for (int i = NB_IDEAS_MAX - 1; i > 0; i--)
		this->_ideas[i] = this->_ideas[i - 1];
	this->_ideas[0] = idea;
}

std::string const	Brain::to_str(void) const
{
	std::string	ideas_str;
	int			i = 0;

	while (this->_ideas[i].empty() != true && i < NB_IDEAS_MAX)
	{
		ideas_str += this->_ideas[i];
		++i;
		if (this->_ideas[i].empty() != true)
			ideas_str += " ";
	}
	return (ideas_str);
}

std::ostream	&operator<<(std::ostream &ostream, Brain const &rhs)
{
	ostream << rhs.to_str();
	return (ostream);
}
