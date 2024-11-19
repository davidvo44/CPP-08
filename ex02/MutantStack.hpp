/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:50:13 by dvo               #+#    #+#             */
/*   Updated: 2024/11/19 20:48:07 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator r_iterator;

	~MutantStack();
	MutantStack();
	MutantStack(MutantStack const &src);
	MutantStack& operator=(MutantStack const & src);
	iterator begin();
	iterator end();
	r_iterator rbegin();
	r_iterator rend();
private:
	
};

#include "MutantStack.tpp"
#endif