/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_element_access.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:20:19 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/09 18:01:21 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP

namespace ft
{
	reference		at( size_type pos );
	const_reference	at( size_type pos ) const;
	reference		operator[]( size_type pos );
	const_reference	operator[]( size_type pos ) const;
	reference		front();
	const_reference	front() const;
	reference		back();
	const_reference	back() const;
	pointer			data();
} // namespace ft

#endif