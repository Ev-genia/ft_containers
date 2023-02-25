#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <memory>

namespace ft
{
	template <class T>
	class vector_iterator
	{
	private:
		pointer	_ptr;
	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef std::random_access_iterator_tag	iterator_category;

		vector_iterator(): ptr(0) {}
		explicit vector_iterator(pointer ptr): ptr(ptr) {}
		vector_iterator(const vector_iterator &src): ptr(src.ptr) {}
		virtual ~vector_iterator() {}
		vector_iterator& operator=(const vector_iterator &rhs)
		{
			if (this == &rhs)
				return (*this);
			_ptr = rhs._ptr;
			return (*this);
		}
		operator vector_iterator<const value_type>() const
		{
			return (vector_iterator<const value_type>(_ptr));
		}
		reference operator*()
		{
			return (*_ptr);
		}
		const_reference operator*() const
		{
			return (*_ptr);
		}
		pointer operator->()
		{
			return (_ptr);
		}
		const_pointer operator->() const
		{
			return (_ptr);
		}
		reference operator[](difference_type n)
		{
			return (*(_ptr + n));
		}
		const_reference operator[](difference_type n) const
		{
			return (*(_ptr + n));
		}
		pointer base() const
		{
			return (_ptr);
		}
		vector_iterator& operator++()
		{
			++_ptr;
			return (*this);
		}
		vector_iterator& operator--()
		{
			--_ptr;
			return (this);
		}
		vector_iterator operator++(int)
		{
			vector_iterator copy = *this;
			++_ptr;
			return (copy);
		}
		vector_iterator operator--(int)
		{
			vector_iterator copy = *this;
			--_ptr;
			return (copy);
		}
		vector_iterator& operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}
		vector_iterator& operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}
		vector_iterator operator+(difference_type n) const
		{
			return (vector_iterator<T>(_ptr + n));
		}
		vector_iterator operator-(difference_type n) const
		{
			return (vector_iterator<T>(_ptr - n));
		}
		difference_type operator+(const vector_iterator &src) const
		{
			return (base() + src.base());
		}
		difference_type operator-(const vector_iterator &src) const
		{
			return (base() - src.base());
		}
		bool operator==(const vector_iterator &rhs) const
		{
			return (base() == rhs.base());
		}
		bool operator!=(const vector_iterator &rhs) const
		{
			return (base() != rhs.base());
		}
		bool operator<(const vector_iterator &rhs) const
		{
			return (base() < rhs.base());
		}
		bool operator<=(const vector_iterator &rhs) const
		{
			return (base() <= rhs.base());
		}
		bool operator>(const vector_iterator &rhs) const
		{
			return (base() > rhs.base());
		}
		bool operator>=(const vector_iterator &rhs) const
		{
			return (base() >= rhs.base());
		}
	};
	template <class T, class V>
	bool operator==(vector_iterator<T>& first, vector_iterator<V>& second)
	{
		return (first.base() == second.base());
	}
	template <class T, class V>
	bool operator!=(vector_iterator<T>& first, vector_iterator<V>& second)
	{
		return (first.base() != second.base());
	}
	template <class T, class V>
	bool operator<(vector_iterator<T>& first, vector_iterator<V>& second)
	{
		return (first.base() < second.base());
	}
	template <class T, class V>
	bool operator<=(vector_iterator<T>& first, vector_iterator<V>& second)
	{
		return (first.base() <= second.base());
	}
	template <class T, class V>
	bool operator>(vector_iterator<T>& first, vector_iterator<V>& second)
	{
		return (first.base() > second.base());
	}
	template <class T, class V>
	bool operator>=(vector_iterator<T>& first, vector_iterator<V>& second)
	{
		return (first.base() >= second.base());
	}
	template <class T>
	vector_iterator<T> operator+(typename ft::vector_iterator<T>::difference_type n, const vector_iterator<T>& rhs)
	{
		return (rhs + n);
	}
} // namespace ft

#endif