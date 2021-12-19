/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 20:22:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP
# include <iostream>

class	Animal
{
	public:
		Animal(std::string const &type = "animal");
		Animal(Animal const &animal);
		virtual ~Animal(void);
		Animal					&operator=(Animal const &rhs);
		std::string const		&get_type(void) const;
		virtual void			make_sound(void) const = 0;
	protected:
		std::string				_type;
};

std::ostream					&operator<<(std::ostream &ostream, Animal const &rhs);

#endif
