/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvo <dvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:52:37 by dvo               #+#    #+#             */
/*   Updated: 2024/11/19 16:35:43 by dvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

class OccurenceNotFound : public std::exception{
	public:
		virtual const char* what() const throw()
		{
			return "easyfind::OccurenceNotFound";
		}
	};

template <typename T>
void	easyfind(T& a, int nb)
{
	if (std::find(a.begin(), a.end(), nb) == a.end())
        throw OccurenceNotFound();
    else
        std::cout << nb << " found on the container" << std::endl;
	
}