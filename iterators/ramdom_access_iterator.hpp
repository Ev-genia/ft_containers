/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramdom_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:49:06 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/27 23:42:54 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{
	template <class T, class Dist, class Pt1, class Rt1, class Pt2, class Rt2>
	class random_access_iterator: public iterator<random_access_iterator, Dist, Pt1, Rt1>
	{
	public:
		typedef random_access_iterator<T, Dist, Pt1, Rt1, Pt2, Rt2>	MyType;

		random_access_iterator() {}

		explicit random_access_iterator(Pt1 P): current(P) {}

		random_access_iterator(const random_access_iterator<T, Dist, Pt1, Rt1, Pt2, Rt2> &other): current(other.base()) {}

		template <class _T, class _Dist, class _Pt1, class _Rt1, class _Pt2, class _Rt2>
		random_access_iterator(const random_access_iterator<_T, _Dist, _Pt1, _Rt1, _Pt2, _Rt2> &other): current(other.base()) {}

		Pt1	base() const {return (current);}
		
		random_access_iterator	&operator=(const random_access_iterator &rhs)
		{
			if (this != &rhs)
				this->current = rhs.current;
			return (*this);
		}

		Rt1		operator*() const {return (*current);}
		Pt1		operator->() const {return (&**this);}
		MyType	&operator++() {++current; return (*this);}
		MyType	operator++(int) {MyType tmp = *this; ++current; return (tmp);}
		MyType	&operator--() {--current; return(*this);}
		MyType	operator--(int) {MyType tmp = *this; --current; return (tmp);}

		bool	operator==(int nbr) const {return (current == (Pt1)nbr);}
		bool	operator==(const MyType &rhs) const {return (this->current == rhs.current);}
		bool	operator!=(const MyType &rhs) const {return (!(*this == rhs));}

		MyType	&operator+=(Dist n) {current += n; return (*this);}
		MyType	operator+(Dist n) const {return (MyType(current + n));}
		MyType	&operator-=(Dist n) {current -= n; return (*this);}
		MyType	operator-(Dist n) const {return (MyType(current - n));}
		Rt1		operator[](Dist n) const {return (*(*this + n));}
		
		bool	operator<(const MyType &rhs) const {return (current < rhs.current);}
		bool	operator>(const MyType &rhs) const {return (current > rhs.current);}
		bool	operator<=(const MyType &rhs) const {return (current <= rhs.current);}
		bool	operator>=(const MyType &rhs) const {return (current >= rhs.current);}

		Dist	operator-(const MyType &rhs) {return (current - rhs.current);}

	protected:
		Pt1	current;
	};
	template <class T, class Dist1, class Pt1, class Rt1, class Pt2, class Rt2, class Dist2> inline
	random_access_iterator<T, Dist1, Pt1, Rt1, Pt2, Rt2>	operator+(
			Dist2 n, const random_access_iterator<T, Dist1, Pt1, Rt1, Pt2, Rt2> &rhs)
			{
				return (rhs + static_cast<Dist1>(n));
			}
} // namespace ft


#endif