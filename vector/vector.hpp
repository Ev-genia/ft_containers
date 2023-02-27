/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:20:04 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/27 21:40:43 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
// # include "iterators/vector_iterator.hpp"

# include "../iterators/iterator.hpp"

namespace ft
{
	template <class T, class A>
	class VectorVal
	{
	protected:
		VectorVal(A All = A()): AlVal(All) {}
		typedef typename _Alloc::template
			rebind<T>::other _AlT;
		_Alt AlVal;
	};

	template <class T, class Allocator = std::allocator<T> >
	class vector: public VectorVal<T, Allocator>
	{
	private:
		pointer			_array;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_allocator;

	public:
		typedef Allocator									allocator_type;
		typedef VectorVal<T, Allocator>						_base;
		
		typedef typename allocator_type::value_type			value_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;

		typedef ft::random

		// typedef ft::vector_iterator<value_type>				iterator;
		// typedef ft::vector_iterator<const value_type>		const_iterator;
		// typedef ft::reverse_iterator<iterator>				reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		vector();
/*
		// *Member functions*
		// constructor
		explicit vector(const allocator_type &alloc = allocator_type()): _array(0), _size(0), _capacity(0), _allocator(alloc) {}
		// destructor
		~vector()
		{
			clear();
			if (_capacity)
				_allocator.deallocate(_array, _capacity);
		}
		// operator=
		vector& operator=( const vector &other)
		{
			if (this != other)
			{
				clear();
				_allocator.deallocate(_array, _capacity);
				_size = other.size();
				_capacity = other.capacity();
				_array = _allocator.allocate(_capacity);
				for (size_t i = 0; i < other._size; i++)
					allocator.construct(_array + i, other._array[i]);
			}
			return (*this);
		}
		// assign
		void assign(size_type count, const T& value)
		{
			T	TVal = value;

			erase(begin(), end());
			insert(begin(), count, TVal);
		}


		// *Modifiers*
		void clear()
		{
			if (_array)
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
			}
			_size = 0;
		}
*/
	};
} // namespace ft

# include "vector_constructor.tpp"

#endif