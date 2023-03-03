/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_distance.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:03:41 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/02 19:56:48 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_DISTANCE_HPP
# define ITERATOR_DISTANCE_HPP

# include "iterator.hpp"

namespace ft
{
	template <class InputIt> inline
	typename ft::iterator_traits<InputIt>::difference_type
				distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type	n = 0;
		Distance2(first, last, n, ft::iterCat(first));
		return (n);
	}

	template <class InputIt, class Dist> inline
	void	Distance(InputIt first, InputIt last, Dist & n)
	{
		Distance2(first, last, n, ft::iterCat(first));
	}

	template <class InputIt, class Dist> inline
	void	Distance2(InputIt first, InputIt last, Dist & n, input_iterator_tag)
	{
		for (; first != last; ++first)
			++n;
	}
} // namespace ft


#endif