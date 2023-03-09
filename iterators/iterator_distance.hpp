/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_distance.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:03:41 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/05 11:15:16 by mlarra           ###   ########.fr       */
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
	void	Distance(InputIt first, InputIt last, Dist &n)
	{
		Distance2(first, last, n, ft::iterCat(first));
	}

	template <class InputIt, class Dist> inline
	void	Distance2(InputIt first, InputIt last, Dist &n, input_iterator_tag)
	{
		for (; first != last; ++first)
			++n;
	}

	template <class InputIt, class Dist> inline
	void	Distance2(InputIt first, InputIt last, Dist &n, forward_iterator_tag)
	{
		for (; first != last; ++first)
			++n;
	}

	template <class InputIt, class Dist> inline
	void	Distance2(InputIt first, InputIt last, Dist &n, bidirectional_iterator_tag)
	{
		for (; first != last; ++first)
			++n;
	}

	template <class InputIt, class Dist> inline
	void	Distance2(InputIt first, InputIt last, Dist &n, ft::random_access_iterator_tag)
	{
		n += last - first;
	}

	template <class InputIt, class Dist> inline
	void	DistanceTree(InputIt first, InputIt last, Dist &n)
	{
		for (; first != last; ++first)
			++n;
	}
} // namespace ft


#endif