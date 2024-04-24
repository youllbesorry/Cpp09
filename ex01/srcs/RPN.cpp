/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:26:39 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/24 17:27:15 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void RPN::afficherOperateurs() {
    std::stack<char> tempStack; // Créer un stack temporaire pour inverser l'ordre
    // Transférer les éléments dans tempStack pour les inverser
    while (!_operator.empty()) {
        tempStack.push(_operator.top());
        _operator.pop();
    }
    // Afficher les éléments dans l'ordre original
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << ' ';
        _operator.push(tempStack.top()); // Remettre les éléments dans _operator
        tempStack.pop();
    }
    std::cout << std::endl;
}

void RPN::afficherValue() {
    std::stack<char> tempStack; // Créer un stack temporaire pour inverser l'ordre
    // Transférer les éléments dans tempStack pour les inverser
    while (!_value.empty()) {
        tempStack.push(_value.top());
        _value.pop();
    }
    // Afficher les éléments dans l'ordre original
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << ' ';
        _value.push(tempStack.top()); // Remettre les éléments dans _operator
        tempStack.pop();
    }
    std::cout << std::endl;
}

void RPN::parsing(std::string line)
{
	std::string strOperator = "+-/*";
	for (unsigned long i = 0; i != line.length(); i++)
	{
		if (line[i] != ' ' && strOperator.find(line[i]) != std::string::npos)
		{
			std::cout << "operator line[" << i << "] = |" << line[i] << "|" << std::endl;
			_operator.push(line[i]);
		}
		else if (line[i] != ' ')
		{
			std::cout << "value line[" << i << "] = |" << line[i] << "|" << std::endl;
			_value.push(line[i]);
		}
	}
	afficherOperateurs();
	afficherValue();
	if ((_value.size() / 2) != _operator.size())
	{
		std::cout << "Wrong number of operator" << std::endl;
		return ;
	}
	return ;
}

void RPN::calculate()
{
	
}
