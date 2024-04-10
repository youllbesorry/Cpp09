/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:49 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/10 17:40:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	*this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		_coin = rhs._coin;
	return (*this);
}

void BitcoinExchange::fillMap()
{
	std::ifstream data("data.csv");
	std::string line;
	if (data.is_open())
	{
		bool first = true;
		while (std::getline(data, line))
		{
			if (first)
			{
				first = false;
				continue;
			}
			std::istringstream sline(line);
			std::string part1;
			std::string part2;
			std::getline(sline, part1, ',');
			std::getline(sline, part2, ',');
			_coin[part1] = strtod(part2.c_str(), NULL);
		}
		// for (std::map<std::string, double>::iterator it = _coin.begin(); it != _coin.end(); ++it)
		// {
       	// 	std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
		// }
		data.close();
	}
	else
		std::cout << "Cannot open the file" << std::endl;
}

bool isValidDate(std::string line)
{
	
}

bool isDate(std::string line)
{
	std::cout << "line = |" << line << "|" << std::endl;
	int j = 0;
	int i = 0;
	for (i = 0; line[i]; i++)
	{
		if (line[i] == '-')
			j++;
	}
	if (j != 2)
		return (false);
	std::istringstream sline(line);
	std::string s;
	for (j = 0; j <= 2; j++)
	{
		std::getline(sline, s, '-');
		if (j == 0)
		{
			if (s.length() != 4)
				return (false);
		}
		else if ((j == 1 || j == 2))
		{
			if (s.length() != 2)
				return (false);
		}
	}
	return (true);
}

void BitcoinExchange::calculate(std::string infile)
{
	std::cout << "infile = " << infile << std::endl;
	std::ifstream file(infile.c_str());
	std::string line;
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::istringstream sline(line);
			std::string part1;
			std::string part2;
			std::getline(sline, part1, '|');
			std::getline(sline, part2, '|');
			part1.erase(std::remove_if(part1.begin(), part1.end(), ::isspace), part1.end());
		    part2.erase(std::remove_if(part2.begin(), part2.end(), ::isspace), part2.end());
			if (!isDate(part1))
			{
				std::cout << "Error" << std::endl;
				// return ;
			}
		}
	}
	else
		std::cout << "Cannot open the file" << std::endl;
}
