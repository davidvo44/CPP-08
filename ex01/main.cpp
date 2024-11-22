/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:38:25 by dvo               #+#    #+#             */
/*   Updated: 2024/11/22 19:11:02 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define TRY(expression) \
	try \
	{ \
		expression; \
		std::cerr << "\033[31mDidn't throw!\033[0m" << std::endl; \
	} \
	catch(const std::exception& e) \
	{ \
		std::cerr << e.what() << std::endl; \
	}

int main (void)
{
	Span test;

	Span oui;
	oui = test;
	TRY(std::cout << test.shortestSpan() << std::endl);
	test.addNumber(6);
	TRY(std::cout << test.shortestSpan() << std::endl);
	test.addNumber(2);
	std::cout << test.shortestSpan() << std::endl;
	test.addNumber(1);
	oui.addNumber(-2);
	TRY(test.addNumber(3));
	test.add_many(4, 0, 4, 10, 8);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	TRY(std::cout << oui.longestSpan() << std::endl);
	
}