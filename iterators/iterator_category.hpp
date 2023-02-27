/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_category.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:55:53 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/27 22:44:47 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_CATEGORY_HPP
# define ITERATOR_CATEGORY_HPP

# include "iterator.hpp"

namespace ft
{
	template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t, typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator
	{
		typedef _Category	iterator_category;
		typedef _Tp			value_type;
		typedef _Distance	difference_type;
		typedef _Pointer	pointer;
		typedef _Reference	reference;
		typedef _Tp			iterator_type;
	};
	template <class T, class Dist, class Pt, class Rt>
	struct BidIt: public iterator<bidirectional_iterator_tag, T, Dist, Pt, Rt> {};

	template <class T, class Dist, class Pt, class Rt>
	struct RanIt: public iterator<random_access_iterator_tag, T, Dist, Pt, Rt> {};

	struct OutIt: public iterator<output_iterator_tag, void, void, void, void> {};
} // namespace ft


#endif