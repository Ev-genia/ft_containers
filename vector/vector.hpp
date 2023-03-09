/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:20:04 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/05 11:36:23 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "../algorithm/algorithm.hpp"
# include "../iterators/iterator.hpp"
# include "../utils/utils.hpp"

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

		typedef ft::random_access_iterator<value_type, difference_type,
			pointer, reference, pointer, reference>	iterator;
		typedef ft::random_access_iterator<value_type, difference_type,
			const_pointer, const_reference, pointer, reference>	const_iterator;
		typedef ft::reverse_iterator<iterator>	reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// *Constructors
		vector();

		explicit vector( const allocator_type& alloc );

		explicit vector( size_type count );

		vector(size_type count, const T &val);

		vector( size_type count, const T& val, const allocator_type& alloc );

		vector( const vector& other );

		template< class InputIt >
		vector( InputIt first, InputIt last );

		template< class InputIt >
		vector( InputIt first, InputIt last, const allocator_type& alloc );

		// *Destructor
		~vector();

		// *operator=
		vector& operator=( const vector& other );

		// *assign
		void assign( size_type count, const T& value );
		
		template< class InputIt >
		void assign( InputIt first, InputIt last );

		// *get_allocator
		allocator_type get_allocator() const;

		// *Element access
		reference at( size_type pos );
		const_reference at( size_type pos ) const;
		reference operator[]( size_type pos );
		const_reference operator[]( size_type pos ) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		pointer data();

		// *Iterators
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		// *Capacity
		bool		empty() const; //true if the container is empty, false otherwise
		size_type	size() const;
		size_type	max_size() const;
		void		reserve( size_type new_cap );
		size_type	capacity() const;

		// *Modifiers
		void		clear();
		iterator	insert( iterator pos, const T& value );

		void		insert( iterator pos, size_type count, const T& value );

		template< class InputIt >
		void		insert( iterator pos, InputIt first, InputIt last );

		iterator	erase( iterator pos );
		iterator	erase( iterator first, iterator last );

		void		push_back( const T& value );

		void		pop_back();

		void		resize( size_type count );
		void		resize( size_type count, T value );

		void		swap( vector& other );

	protected:
		bool	AllocateZero(size_type);

		pointer	CallConstructor(pointer, size_type, const T &);

		template <class InputIt>
		pointer	ItCopy(InputIt first, InputIt last, pointer ptr);

		template <class InputIt>
		void	Construct(InputIt first, InputIt last, Int_iterator_tag);

		template <class InputIt>
		void	Construct(InputIt first, InputIt last, input_iterator_tag);

		template <class InputIt>
		void	Construct2(InputIt first, InputIt last, typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type * = nullptr);
		template <class InputIt>
		void	Construct2(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = nullptr);

		void	Destroy(pointer first, pointer last);

		void	Clear();

		template <class InputIt>
		void	Insert(iterator p, InputIt first, InputIt last, Int_iterator_tag);

		template <class InputIt>
		void	Insert(iterator p, InputIt first, InputIt last, input_iterator_tag);

		template <class InputIt>
		void	Insert(iterator p, InputIt first, InputIt last, forward_iterator_tag);

		template <class InputIt>
		void	Insert2(iterator p, InputIt first, typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type * = nullptr);

		template <class InputIt>
		void	Insert2(iterator p, InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = nullptr);

		template <class InputIt>
		void	Assign(InputIt first, InputIt last, Int_iterator_tag);

		template <class InputIt>
		void	Assign(InputIt first, InputIt last, input_iterator_tag);

		pointer First, Last, End;
	};

	// *Non-member functions
	template< class T, class allocator_type > inline
	bool operator==( const std::vector<T, allocator_type>& lhs,
			const std::vector<T, allocator_type>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class allocator_type >
	bool operator!=( const std::vector<T, allocator_type>& lhs,
			const std::vector<T, allocator_type>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T, class allocator_type >
	bool operator<( const std::vector<T, allocator_type>& lhs,
			const std::vector<T, allocator_type>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class allocator_type >
	bool operator<=( const std::vector<T, allocator_type>& lhs,
			const std::vector<T, allocator_type>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class T, class allocator_type >
	bool operator>( const std::vector<T, allocator_type>& lhs,
			const std::vector<T, allocator_type>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T, class allocator_type >
	bool operator>=( const std::vector<T, allocator_type>& lhs,
			const std::vector<T, allocator_type>& rhs )
	{
		return (!(lhs < rhs));
	}
} // namespace ft

# include "vector_constructor.tpp"
# include "vector_destructor.tpp"
# include "vector_overload_operator.tpp"
# include "vector_assign.tpp"
# include "vector_get_allocator.tpp"
# include "vector_element_access.tpp"
# include "vector_iterators.tpp"
# include "vector_capacity.tpp"
# include "vector_modifires.tpp"
# include "vector_protected.tpp"

#endif