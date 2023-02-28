/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:37:22 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/28 23:52:33 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

# include "mismatch.hpp"

namespace ft
{
	template <class InputIt1, class InputIt2> inline
	bool	equal(InputIt1 first, InputIt1 last, InputIt2 x)
	{
		return (ft::mismatch(first, last, x).first == last);
	}

	template <class InputIt1, class InputIt2, class Pr> inline
	bool	equal(InputIt1 first, InputIt1 last, InputIt2 x, Pr p)
	{
		return (ft::mismatch(first, last, x, p).first == last);
	}
} // namespace ft

#endif