/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:27:27 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 18:08:43 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP

namespace ft
{
	template <class T, class Allocator>
	bool	vector<T, Allocator>::empty() const
	{
		return (size() == 0);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::size() const
	{
		if (First == 0)
			return (0);
		return (Last - First);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::max_size() const
	{
		return (_base::AlVal.max_size());
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::reserve( size_type new_cap )
	{
		if (max_size() < new_cap)
			throw "vector<T> is too long";
		else if (capacity() < new_cap)
		{
			pointer	Q = _base::AlVal.allocate(new_cap, (void *)0);

			try
			{
				ItCopy(begin(), end(), Q);
			}
			catch (...)
			{
				_base::AlVal.deallocate(Q, new_cap);
				throw ;
			}
			if (First != 0)
			{
				Destroy(First, Last);
				_base::AlVal.deallocate(First, End - First);
			}
			End = Q + new_cap;
			Last = Q + size();
			First = Q;
		}
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity() const
	{
		if (First == 0)
			return (0);
		return (End - First);
	}
} // namespace ft

#endif