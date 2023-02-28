/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:45:07 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/28 23:35:40 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		pair(): first(), second() {}

		pair( const T1& x, const T2& y ): first(x), second(y) {}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ): first(p.first), second(p.second) {}

		void	swap(pair<T1, T2> &p)
		{
			pair<T1, T2>	tmp(p.first, p.second);
			
			p.first = this->first;
			p.second = this->second;
			this->first = tmp.first;
			this->second = tmp.second;
		}
	};
	template< class T1, class T2 >
	pair<T1, T2>	make_pair( T1 t, T2 u )
	{
		return (pair<T1, T2>(t, u));
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator==( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator!=( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator<( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator<=( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator>( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator>=( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
	{
		return (!(lhs < rhs));
	}
} // namespace ft

#endif