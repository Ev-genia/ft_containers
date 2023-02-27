/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:24:58 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/27 18:37:41 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "iterator.hpp"

namespace ft
{
	template <class It>
	struct	iterator_traits
	{
		typedef typename It::iterator_category	iterator_category;
		typedef typename It::value_type			value_type;
		typedef typename It::difference_type	difference_type;
		typedef typename It::pointer			pointer;
		typedef typename It::reference			reference;
	};
	template <class T>
	struct	iterator_traits<T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T							*pointer;
		typedef T&							reference;
	};
	template <class T>
	struct	iterator_traits<const T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T							*pointer;
		typedef T&							reference;
	};
} // namespace ft

#endif