/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:37:14 by dvo               #+#    #+#             */
/*   Updated: 2024/11/19 17:38:06 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>

class Span
{
public:
	~Span();
	Span();
	Span(Span const &src);
	Span& operator=(Span const & src);

	void addNumber(int nb);
	int	shortestSpan();
	int	longestSpan();
			//Exception Class
	class NumberAlreadyExist : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	class SpanTooShort : public std::exception{
	public:
		virtual const char* what() const throw();
	};
private:
	std::set<int> 	_array;
	int		_shortest;
};

#endif