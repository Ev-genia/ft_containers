#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		T		_*arr;
		size_t	_size;
	public:
		typedef T										value_type;
		typedef Allocator								alloc_type;
		typedef typename alloc_type::reference			reference;
		typedef typename alloc_type::const_reference	const_reference;
		typedef typename alloc_type::size_type			size_type;
		typedef typename alloc_type::difference_type	difference_type;
		typedef typename alloc_type::pointer			pointer;
		typedef typename alloc_type::const_pointer		const_pointer;
		typedef ft::vector_iterator<value_type>			iterator;
		typedef ft::vector_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	};
} // namespace ft


#endif