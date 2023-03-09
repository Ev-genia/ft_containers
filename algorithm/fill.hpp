/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:58:40 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 17:03:42 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_HPP
# define FILL_HPP

namespace ft
{
	template <class FwdIt, class T> inline
	void	fill(FwdIt first, FwdIt last, const T &value)
	{
		for (; first != last; ++first)
			*first = value;
	}

	template <class OutIt, class Sz, class T> inline
	void	fill_n(OutIt first, Sz n, const T &value)
	{
		for (; n > 0; --n, ++first)
			*first = value;
	}
} // namespace ft

#endif