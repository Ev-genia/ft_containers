/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:29:06 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 16:32:11 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
# define SWAP_HPP

namespace ft
{
	template <class T> inline
	void	swap(T &first, T &second)
	{
		T	tmp = first;
		first = second;
		second = tmp;
	}
} // namespace ft

#endif