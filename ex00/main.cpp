/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:49:30 by dvo               #+#    #+#             */
/*   Updated: 2024/11/22 16:01:17 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

#define TRY(expression) \
	try \
	{ \
		expression; \
	} \
	catch(const std::exception& e) \
	{ \
		std::cerr << e.what() << std::endl; \
	}

template <typename T, typename Function>
void add(T& container, Function &func)
{
	for (int i = 1; i < 6; i++)
		func(container, i);
}

template <typename T>
void pushback(T& cont, int value)
{
    cont.push_back(value);
}

int main (void)
{
	std::vector<int> nbr;
	add(nbr, pushback<std::vector<int> >);
	TRY(::easyfind(nbr, 5));

	std::list<int> lst;
	add(lst, pushback<std::list<int> >);
	TRY(::easyfind(lst, 4));

	std::deque<int> deq;
	add(deq, pushback<std::deque<int> >);
	TRY(::easyfind(deq, 8));
}