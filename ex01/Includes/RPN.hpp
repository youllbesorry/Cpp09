/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:26:28 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/24 15:41:42 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	public :
		RPN();
		~RPN();
		RPN(const RPN &ref);
		RPN &operator=(const RPN &rhs);
		void parsing(std::string line);
		void calculate();
		void afficherOperateurs(); //A SUPPRIMER
		void afficherValue(); //A SUPPRIMER
	private :
		std::stack<char> _operator;
		std::stack<int> _value;
};

#endif