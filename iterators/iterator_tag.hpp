/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_tag.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:07:23 by mlarra            #+#    #+#             */
/*   Updated: 2023/03/02 19:45:23 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TAG_HPP
# define ITERATOR_TAG_HPP

namespace ft
{
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag: public input_iterator_tag {};
	struct	bidirectional_iterator_tag: public forward_iterator_tag {};
	struct	random_access_iterator_tag: public bidirectional_iterator_tag {};
	struct	Int_iterator_tag {};

	template <class It>
	struct	iterator_traits;

	template <class T>
	struct	iterator_traits<T *>;

	template <class ItRev>
	class	reverse_iterator;
} // namespace ft

#endif