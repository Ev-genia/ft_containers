/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destructor.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:10:10 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/01 13:12:54 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP

namespace ft
{
	template <class T, class Allocator>
	vector<T, Allocator>::~vector()
	{
		Clear();
	}
} // namespace ft

#endif