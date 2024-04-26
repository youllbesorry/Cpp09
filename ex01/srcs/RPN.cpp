/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:26:39 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/26 15:39:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

void RPN(std::string line)
{
	std::stack<int> stack;
	size_t			start = 0;
	size_t			end = 0;
	int				nb = 0;
	
	parsing(line);
	while (line.length() != 0)
	{
		start = line.find_first_not_of(" ");
		end = line.find(" ", start);
		if (isdigit(line[start]))
		{
			for (size_t i = start; i < end; i++)
			{
				if (!isdigit(line[i]))
					throw (std::runtime_error("Somethings goes wrong with your input..."));
			}
			nb = atoi(line.substr(start, end).c_str());
			if (nb < 0 || nb > 9)
				throw (std::runtime_error("Somethings goes wrong with your input..."));
			stack.push(nb);
		}
		else if ((line[start] == '+' || line[start] == '-' || line[start] == '/' || line[start] == '*'))
			stack.push(calculate(line[start], stack));
		line.erase(0, end);
	}
	// if (stack.size() > 1)
	// 	throw (std::runtime_error("Somethings goes wrong with your input... 2"));
	std::cout << "Result = " << stack.top() << std::endl;
	return ;
}

void parsing(std::string line)
{
	if (line.find_first_not_of("1234567890+-/* ") != std::string::npos
	|| line.find_first_not_of("1234567890 ") == std::string::npos
	|| line.find_first_not_of("+-/* ") == std::string::npos
	|| line.empty())
		throw (std::runtime_error("Somethings goes wrong with your input..."));
}

int calculate(char _operator, std::stack<int> stack)
{
	if (stack.size() < 2)
		throw (std::runtime_error("Somethings goes wrong with your input... 1"));
	int second = stack.top();
	stack.pop();
	int first = stack.top();
	stack.pop();
	std::cout << "first = " << first << std::endl;
	std::cout << "_operator = " << _operator <<std::endl;
	std::cout << "second = " << second << std::endl;
	switch (_operator)
	{
	case '+':
		return (first + second);
	case '-':
		return (first - second);
	case '/':
		return (first / second);
	case '*':
		return (first * second);
	default:
		break;
	}
	return (0);
}
