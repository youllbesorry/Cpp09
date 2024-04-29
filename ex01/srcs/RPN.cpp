/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:26:39 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/29 18:52:15 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

void ft_count(std::string line)
{
	size_t			nb_operator = 0;
	size_t			nb_digit = 0;
	int				i = 0;

	while (line[i])
	{
		if ((line[i] == '-' && isdigit(line[i + 1])))
			throw (std::runtime_error("Somethings goes wrong with your input..."));
		if ((line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '*'))
			nb_operator++;
		else if (isdigit(line[i]))
			nb_digit++;
		i++;
	}
	if (nb_operator != nb_digit - 1)
		throw (std::runtime_error("Somethings goes wrong with your input..."));
}

void RPN(std::string line)
{
	std::stack<int> stack;
	size_t			start = 0;
	size_t			end = 0;
	int				nb = 0;
	
	parsing(line);
	ft_count(line);
	while (line.length() != 0)
	{
		start = line.find_first_not_of(" ");
		end = line.find(" ", start);
		std::string tmp = line.substr(start, end - start);
		if (isdigit(tmp[0]) || (tmp[0] == '-' && tmp.length() > 1))
		{
			for (size_t i = start; i < end; i++)
			{
				if (isdigit(tmp[0] == false))
					throw (std::runtime_error("Somethings goes wrong with your input... 4"));
			}
			nb = atoi(tmp.c_str());
			if (nb < 0 || nb > 9)
				throw (std::runtime_error("Somethings goes wrong with your input..."));
			stack.push(nb);
		}
		else if ((tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '/' || tmp[0] == '*'))
		{
			stack.push(calculate(tmp[0], stack));
			std::cout << "result = " << stack.top() << std::endl;
		}
		line.erase(0, end);
	}
	if (stack.size() < 1)
		throw (std::runtime_error("Somethings goes wrong with your input... 3"));
	std::cout << "Result = " << stack.top() << std::endl;
	return ;
}

void parsing(std::string line)
{
	if (line.find_first_not_of("1234567890+-/* ") != std::string::npos)
		throw (std::runtime_error("Somethings goes wrong with your input..."));
}

int calculate(char _operator, std::stack<int> &stack)
{
	if (stack.size() < 2)
		throw (std::runtime_error("Somethings goes wrong with your input... 1"));
	std::cout << "stack.top() 1 = " << stack.top() << std::endl;
	int second = stack.top();
	stack.pop();
	std::cout << "stack.top() 2 = " << stack.top() << std::endl;
	int first = stack.top();
	stack.pop();
	std::cout << "Calculating: " << first << " " << _operator << " " << second << std::endl;
	switch (_operator)
	{
	case '+':
		{
			if ((first + second) > std::numeric_limits<int>::max() || (first + second) < std::numeric_limits<int>::min())
				throw (std::runtime_error("Somethings goes wrong with your input... 2"));
			return (first + second);
		}
	case '-':
		{
			if ((first - second) > std::numeric_limits<int>::max() || (first - second) < std::numeric_limits<int>::min())
				throw (std::runtime_error("Somethings goes wrong with your input... 2"));
			return (first - second);
		}
	case '/':
		{
			if ((first - second) > std::numeric_limits<int>::max() || (first - second) < std::numeric_limits<int>::min())
				throw (std::runtime_error("Somethings goes wrong with your input... 2"));
			if (second == 0)
				throw (std::runtime_error("You can't divid by 0"));
			return (first / second);
		}
	case '*':
		{
			if ((first * second) > std::numeric_limits<int>::max() || (first * second) < std::numeric_limits<int>::min())
				throw (std::runtime_error("Somethings goes wrong with your input... 2"));
			return (first * second);
		}
	default:
		break;
	}
	return (0);
}
