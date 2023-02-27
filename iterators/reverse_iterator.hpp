/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:41:38 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/27 22:36:02 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

// # include <iostream>
# include "iterator.hpp"

namespace ft
{
	template <class ItRev>
	class reverse_iterator: public iterator<
		typename ft::iterator_traits<ItRev>::iterator_category,
		typename ft::iterator_traits<ItRev>::value_type,
		typename ft::iterator_traits<ItRev>::difference_type,
		typename ft::iterator_traits<ItRev>::pointer,
		typename ft::iterator_traits<ItRev>::reference>
	{
	public:
		typedef reverse_iterator<ItRev>								MyType;
		typedef typename iterator_traits<ItRev>::difference_type	Diff;
		typedef typename iterator_traits<ItRev>::pointer			Ptr;
		typedef typename iterator_traits<ItRev>::reference			Ref;
		typedef ItRev												iterator_type;

		reverse_iterator() {}

		explicit reverse_iterator(ItRev itr): current(itr) {}

		template <class U>
		reverse_iterator(const reverse_iterator<U> &itr): current(itr.base()) {}

		ItRev	base() const {return (current);}
		Ref		operator*() const {ItRev tmp = current; return (*--tmp);}
		Ptr		operator->() const {return (&**this);}
		MyType&	operator++() {--current; return (*this);}
		MyType&	operator--() {++current; return (*this);}
		MyType	operator++(int) {MyType tmp = *this; --current; return (tmp);}
		MyType	operator--(int) {MyType tmp = *this; ++current; return (tmp);}
		MyType	operator+(Diff n) const {return (MyType(current - n));}
		MyType	operator-(Diff n) const {return (MyType(current + n));}
		MyType	operator+=(Diff n) {current -= n; return (*this);}
		MyType	operator-=(Diff n) {current += n; return (*this);}
		Ref		operator[](Diff n) const {return (*(*this + n));}

	protected:
		ItRev current = ItRev();
	};
	template <class ItRev1, class ItRev2> inline
	typename reverse_iterator<ItRev1>::Diff operator-(const reverse_iterator<ItRev1> &lhs,
		const reverse_iterator<ItRev2> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class ItRev1, class ItRev2> inline
	bool operator==(const reverse_iterator<ItRev1> &lhs, const reverse_iterator<ItRev2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class ItRev1, class ItRev2> inline
	bool operator!=(const reverse_iterator<ItRev1> &lhs, const reverse_iterator<ItRev2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class ItRev1, class ItRev2> inline
	bool operator<(const reverse_iterator<ItRev1> &lhs, const reverse_iterator<ItRev2> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class ItRev1, class ItRev2> inline
	bool operator<=(const reverse_iterator<ItRev1> &lhs, const reverse_iterator<ItRev2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class ItRev1, class ItRev2> inline
	bool operator>(const reverse_iterator<ItRev1> &lhs, const reverse_iterator<ItRev2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class ItRev1, class ItRev2> inline
	bool operator>=(const reverse_iterator<ItRev1> &lhs, const reverse_iterator<ItRev2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

} // namespace ft


#endif