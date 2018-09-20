/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmahele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:47:44 by pmahele           #+#    #+#             */
/*   Updated: 2018/06/14 18:16:57 by pmahele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void print(T const & type) {
	std::cout << "Passed: " << type << std::endl;
}

template<typename T>
void iter(T * array, int len, void (*f)(T const & type)) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

int		main(void)
{
	char str[6] = "boobs";
	int num[5] = {0, 1, 2, 3, 4};
	bool boo[5] = {true, true, false, true, false};
	std::cout << "Passing \"boobs\":" << std::endl;
	iter(str, 5, print<char>);
	std::cout << "Passing \"0, 1, 2, 3, 4\":" << std::endl;
	iter(num, 5, print<int>);
	std::cout << "Passing \"true, true, false, true, false\":" << std::endl;
	iter(boo, 5, print<bool>);

	return (0);
}
