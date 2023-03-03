/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:19:47 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/01 13:05:01 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP

namespace ft
{
	template <class T, class Allocator>
	vector<T, Allocator>::vector(): _base() {allocateZero(0);}
	
	template <class T, class Allocator>
	vector<T, Allocator>::vector( const allocator_type& alloc ): _base(alloc)
	{
		AllocateZero(0);
	}
} // namespace ft

#endif