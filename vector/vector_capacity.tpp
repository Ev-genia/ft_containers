/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:27:27 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 16:56:30 by mlarra           ###   ########.fr       */
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
	void	vector<T, Allocator>::reserve( size_type new_cap );

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity() const
	{
		if (First == 0)
			return (0);
		return (End - First);
	}

} // namespace ft

#endif