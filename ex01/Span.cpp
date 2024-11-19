/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:46:06 by dvo               #+#    #+#             */
/*   Updated: 2024/11/19 18:06:18 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span()
{
	_array.clear();
	_shortest = INT_MAX;
}

Span::Span(Span const &src)
{
	_array.clear();
	_array = src._array;
	_shortest = INT_MAX;
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
	std::set<int>::iterator it;
	std::set<int>::iterator itmax;
	it = _array.find(nb);
	itmax = it;
	std::advance(itmax, 1);
	if (itmax != _array.end())
		if (*itmax - *it < _shortest)
			_shortest = *itmax - *it;
	itmax = it;
	std::advance(itmax, -1);
	if (it != _array.begin())
		if (*it - *itmax < _shortest)
			_shortest = *it - *itmax;
}

int Span::shortestSpan()
{
	if (_array.size() < 2)
		throw SpanTooShort();
	return _shortest;
}

int Span::longestSpan()
{
	if (_array.size() < 2)
		throw SpanTooShort();
	return (*(--_array.end()) - *_array.begin());
}
//1 3 -1 10 11
//1
//10

const char* Span::NumberAlreadyExist::what() const throw()
{
	return "Span::NumberAlreadyExistException";
}

const char* Span::SpanTooShort::what() const throw()
{
	return "Span::SpanTooShortException";
}