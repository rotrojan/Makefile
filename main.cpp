/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2021/12/12 20:26:05 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#define SIZE_ARRAY 10

int	main(void)
{
	Animal const	*dog = new Dog();
	Animal const	*cat = new Cat();
	delete dog;
	delete cat;
	std::cout << std::endl;

	Animal	*array[SIZE_ARRAY];
	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new  Cat();
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE_ARRAY; i++)
		array[i]->make_sound();
	std::cout << std::endl;

	for (int i = 0; i < SIZE_ARRAY; i++)
		delete array[i];
	std::cout << std::endl;

	Dog	dog1;
	std::cout << dog1 << std::endl;
	Dog dog2(dog1);
	std::cout << dog2 << std::endl;
	std::cout << std::endl;

	Cat	cat1;
	std::cout << cat1 << std::endl;
	Cat cat2(cat1);
	std::cout << cat2 << std::endl;
	std::cout << std::endl;
	// Animal animal;

	return (EXIT_SUCCESS);
}
