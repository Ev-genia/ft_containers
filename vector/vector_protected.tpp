/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_protected.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:30:04 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/03 09:16:04 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP

namespace ft
{
	template <class T, class Allocator>
	bool	vector<T, Allocator>::AllocateZero(size_type n)
	{
		First = 0, Last = 0, End = 0;
		if (n == 0)
			return (false);
		else
		{
			First = _base::AlVal.allocate(n);
			Last = First;
			End = First + n;
			return (true);
		}
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::pointer	
			vector<T, Allocator>::CallConstructor(pointer p, size_type n, const T &x)
	{
		pointer	Ps = p;
		try
		{
			for (; 0 < n; --n, ++p)
				_base::AlVal.construct(p, x);
		}
		catch(...)
		{
			Destroy(Ps, p);
			throw;
		}
		return (p);
	}

	template <class T, class Allocator>
	template <class InputIt>
	typename	vector<T, Allocator>::pointer	
			vector<T, Allocator>::ItCopy(InputIt first, InputIt last, pointer ptr)
	{
		pointer	copyPtr = ptr;

		try
		{
			for (; first != last; ++ptr, ++first)
				_base::AlVal.construct(ptr, *first);
		}
		catch (...)
		{
			Destroy(copyPtr, ptr);
			throw;
		}
		return (ptr);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T, Allocator>::Construct(InputIt first, InputIt last, Int_iterator_tag)
	{
		size_type	n = (size_type)first;
		if (AllocateZero(n))
			Last = CallConstructor(first, n, (T)last);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T, Allocator>::Construct(InputIt first, InputIt last, input_iterator_tag)
	{
		AllocateZero(0);
		insert(begin(), first, last);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T,Allocator>::Construct2(InputIt first, InputIt last, typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type * = nullptr)
	{
		size_type	n = (size_type)first;
		if (AllocateZero(n))
			last = CallConstructor(first, n, (T)last);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T,Allocator>::Construct2(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = nullptr)
	{
		AllocateZero(0);
		insert(begin(), first, last);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::Destroy(pointer first, pointer last)
	{
		for (; first != last; ++first)
			_base::AlVal.destroy(first);
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::Clear()
	{
		if (First != 0)
		{
			Destroy(First, Last);
			_base::AlVal.deallocate(First, End - First);
		}
		First = 0, Last = 0, End = 0;
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T, Allocator>::Insert(iterator p, InputIt first, InputIt last, Int_iterator_tag)
	{
		insert(p, (size_type)first, (T)last);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T, Allocator>::Insert(iterator p, InputIt first, InputIt last, input_iterator_tag)
	{
		for (; first != last; ++first, ++p)
			p = insert(p, *first);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void	vector<T, Allocator>::Insert(iterator p, InputIt first, InputIt last, forward_iterator_tag)
	{
		size_type	m = 0;

		ft::
	}
} // namespace ft

#endif