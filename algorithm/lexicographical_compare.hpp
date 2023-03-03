/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:42:00 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/01 12:55:36 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	template <class InputIt1, class InputIt2> inline
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2)
	{
		for (; first1 != last1 && first2 != last2; ++first1, ++first2)
		{
			if (*first1 < *first2)
				return (true);
			else if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}

	template <class InputIt1, class InputIt2, class Pr> inline
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2, Pr p)
	{
		for (; first1 != last1 && first2 != last2; ++first1, ++first2)
		{
			if (p(*first1, *first2))
				return (true);
			else if (p(*first2, *first1))
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}
} // namespace ft


#endif