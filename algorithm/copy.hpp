/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:46:18 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 17:04:02 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY_HPP
# define COPY_HPP

namespace ft
{
	template <class InputIt, class OutputIt> inline
	OutputIt	copy(InputIt first, InputIt last, OutputIt x)
	{
		for (; first != last; ++x, ++first)
			*x = *first;
		return (x);
	}

	template <class BidIt1, class BidIt2> inline
	BidIt2	copy_backward(BidIt1 first, BidIt1 last, BidIt2 x)
	{
		while (first != last)
			*--x = *--last;
		return (x);
	}
} // namespace ft

#endif