/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifires.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:28:45 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 17:56:47 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP

// # include "vector.hpp"

namespace ft
{
	template <class T, class Allocator>
	void	vector<T, Allocator>::clear()
	{
		erase(begin(), end());
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::insert( iterator pos, const T& value )
	{
		size_type	ex;
		if (size == 0)
			ex = 0;
		else
			ex = pos - begin();
		insert(pos, (size_type)1, value);
		return (begin() + ex);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::insert( iterator pos, size_type count, const T& value )
	{
		T			TVal = value;
		size_type	n = capacity();

		if (count == 0)
			;
		else if (max_size() - size() < count)
		{
			throw "vector<T> is too long";
		}
		else if (n < size() + count) 
		{
			if ((max_size() - n) < n)
				n = 0;
			else
				n = n + n;
			if (n < size() + count)
				n = size() + count;
			
			pointer	S = _base::AlVal.allocate(n);
			pointer	Q;

			try
			{
				Q = ItCopy(begin(), pos, S);
				Q = CallConstructor(Q, count, TVal);
				ItCopy(pos, end(), Q);
			}
			catch (...)
			{
				Destroy(S, Q);
				_base::AlVal.deallocate(S, n);
				throw ;
			}
			if (First != 0)
			{
				Destroy(First, Last);
				_base::AlVal.deallocate(First, End - First);
			}
			End = S + n;
			Last = S + size() + count;
			First = S;
		}
		else if ((size_type)(end() - pos) < count)
		{
			ItCopy(pos, end(), pos.base() + count);
			try
			{
				CallConstructor(Last, count - (end() - pos), TVal);
			}
			catch (...)
			{
				Destroy(pos.base() + count, Last + count);
				throw ;
			}
			Last += count;
			ft::fill(pos, end() - count, TVal);
		}
		else
		{
			iterator	Oend = end();

			Last = ItCopy(Oend - count, Oend, Last);
			ft::copy_backward(pos, Oend - count, Oend);
			ft::fill(pos, pos + count, TVal);
		}
	}

	template <class T, class Allocator>
	template< class InputIt >
	void	vector<T, Allocator>::insert( iterator pos, InputIt first, InputIt last )
	{
		Insert(pos, last, iterCat(first));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::erase( iterator pos )
	{
		ft::copy(pos + 1, end(), pos);
		Destroy(Last - 1, Last);
		--Last;
		return (pos);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::erase( iterator first, iterator last )
	{
		if (first != last)
		{
			pointer ptr = ft::copy(last, end(), first.base());
			Destroy(ptr, last);
			last = ptr;
		}
		return (first);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::push_back( const T &value )
	{
		insert(end(), value);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::pop_back()
	{
		erase(end() - 1);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::resize( size_type count )
	{
		resize(count, T());
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::resize(size_type count, T value)
	{
		if (size() < count)
			insert(end(), count - size(), value);
		else if (count < size())
			erase(begin() + count, end());
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::swap( vector& other )
	{
		if (_base::AlVal == other.AlVal)
		{
			ft::swap(First, other.First);
			ft::swap(Last, other.Last);
			ft::swap(End, other.End);
		}
		else
		{
			vector	tmp = *this;
			*this = other;
			other = tmp;
		}
	}
} // namespace ft

#endif