/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:44:33 by dvo               #+#    #+#             */
/*   Updated: 2024/11/19 20:51:39 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> test;
	std::cout << test.size() << std::endl;
	test.push(5);
	test.push(4);
	test.push(8);
	test.push(10);
	test.push(-1);
	std::cout << test.top() << std::endl;
	std::cout << test.size() << std::endl;
	MutantStack<int>::iterator it = test.begin();
	std::cout << *it << std::endl;


	for (MutantStack<int>::r_iterator  it = test.rbegin(); it != test.rend(); ++it)
    	std::cout << *it << " ";
	std::cout << std::endl;
}