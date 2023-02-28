/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:39:08 by mlarra            #+#    #+#             */
/*   Updated: 2023/02/28 19:56:38 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <class T, bool v>
	struct integral_constant
	{
		static const bool	value = v;

		typedef T					value_type;
		typedef integral_constant	type;
		operator value_type() const {return (value);}
	};

	template <class T>
	struct is_integral: public integral_constant<T, false> {};

	template <>
	struct is_integral<bool>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<char>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<signed char>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned char>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<wchar_t>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<char16_t>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<short>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned short>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<int>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned int>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<long>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<long long>: public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long long>: public integral_constant<bool, true> {};
	
} // namespace ft


#endif