/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mismatch.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:42:45 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/28 23:46:37 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISMATCH_HPP
# define MISMATCH_HPP

# include "algorithm.hpp"
# include "../utils/pair.hpp"

namespace ft
{
	template <class InputIt1, class InputIt2> inline
	ft::pair<InputIt1, InputIt2>	mismatch(InputIt1 first, InputIt1 last, InputIt2 x)
	{
		for (; first != last && *first == *x; ++first, ++x)
			;
		return (ft::pair<InputIt1, InputIt2>(first, x));
	}

	template <class InputIt1, class InputIt2, class Pr> inline
	ft::pair<InputIt1, InputIt2>	mismatch(InputIt1 first, InputIt1 last, InputIt2 x, Pr p)
	{
		for (; first != last && p(*first, *x); ++first, ++x)
			;
		return (pair<InputIt1, InputIt2>(first, x));
	}
} // namespace ft

#endif