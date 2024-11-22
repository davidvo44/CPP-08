/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:46:06 by dvo               #+#    #+#             */
/*   Updated: 2024/11/20 19:56:13 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdarg>
#include <climits>

Span::Span()
{
	_array.clear();
}

Span::Span(Span const &src)
{
	_array.clear();
	_array = src._array;
}

Span::~Span(){}

Span& Span::operator=(Span const & src)
{
	this->_array = src._array;
	return *this;
}

void Span::addNumber(int nb)
{
	if (_array.find(nb) == _array.end())
		_array.insert(nb);
	else
		throw NumberAlreadyExist();
}

void Span::add_many(int size, int first, ...)
{
	std::va_list args;
	va_start(args, first);
	int value = first;
	for (int i = 0; i < size; i++)
   {
		_array.insert(value);
		value = va_arg(args, int);
	}
	va_end(args);
}

int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw SpanTooShort();
	std::set<int>::iterator it = _array.begin();
	std::set<int>::iterator itmax = it;
	int shortest = INT_MAX;
	std::advance(itmax, 1);
	for (; itmax != _array.end(); std::advance(itmax, 1))
	{
		if (*itmax - *it < shortest)
			shortest = *itmax - *it;
		std::advance(it, 1);
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (_array.size() < 2)
		throw SpanTooShort();
	return (*(--_array.end()) - *_array.begin());
}

const char* Span::NumberAlreadyExist::what() const throw()
{
	return "Span::NumberAlreadyExistException";
}

const char* Span::SpanTooShort::what() const throw()
{
	return "Span::SpanTooShortException";
}