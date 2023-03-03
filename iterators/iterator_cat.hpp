/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_cat.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:11:46 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/02 19:50:49 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_CAT_HPP
# define ITERATOR_CAT_HPP

# include "iterator.hpp"

namespace ft
{
	template <class C, class T, class Dist, class Pt, class Rt> inline
	C	iterCat(const ft::iterator<C, T, Dist, Pt, Rt> &)
	{
		C	x;
		return (x);
	}

	template <class T> inline
	ft::random_access_iterator_tag	iterCat(const T)
	{
		ft::random_access_iterator_tag	x;
		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(bool)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(char)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(signed char)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(unsigned char)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(wchar_t)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(short)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(unsigned short)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(int)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(unsigned int)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(long)
	{
		Int_iterator_tag	x;

		return (x);
	}

	inline ft::Int_iterator_tag	iterCat(unsigned long)
	{
		Int_iterator_tag	x;

		return (x);
	}
} // namespace ft


#endif