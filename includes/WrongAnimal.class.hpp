/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 14:14:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP
# include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal(std::string const &type = "wrong animal");
		WrongAnimal(WrongAnimal const &wronganimal);
		virtual ~WrongAnimal(void);
		WrongAnimal			&operator=(WrongAnimal const &rhs);
		std::string const	&get_type(void) const;
		void				make_sound(void) const;
	protected:
		std::string			_type;
};

std::ostream				&operator<<(std::ostream &ostream, WrongAnimal const &rhs);

#endif
