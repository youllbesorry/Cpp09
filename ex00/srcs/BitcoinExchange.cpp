/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:49 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/11 14:21:46 by bfaure           ###   ########lyon.fr   */
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

void BitcoinExchange::initCalendar()
{
	_calendar[1] = 31;
	_calendar[2] = 28;
	_calendar[3] = 31;
	_calendar[4] = 30;
	_calendar[5] = 31;
	_calendar[6] = 30;
	_calendar[7] = 31;
	_calendar[8] = 31;
	_calendar[9] = 30;
	_calendar[10] = 31;
	_calendar[11] = 30;
	_calendar[12] = 31;

}

bool BitcoinExchange::isValidDate(std::string *line, int n)
{
	switch (n)
	{
	case 0:
		// std::cout << atoi(line[n].c_str()) << std::endl;
		if (atoi(line[n].c_str()) < 2009 || atoi(line[n].c_str()) > 2024)
			return (false);
		break;
	case 1:
		// std::cout << atoi(line[n].c_str()) << std::endl;
		if (atoi(line[n].c_str()) <= 0 || atoi(line[n].c_str()) > 12)
			return (false);
		break;
	case 2:
		// std::cout << "atoi(line[n].c_str()) = " << atoi(line[n].c_str()) << std::endl;
		// std::cout << "atoi(line[n - 1].c_str()) = " << atoi(line[n - 1].c_str()) << std::endl;
		// std::cout << "_calendar[atoi(line[n - 1].c_str())] = " << _calendar[atoi(line[n - 1].c_str())] << std::endl;
		if (atoi(line[n].c_str()) > _calendar[atoi(line[n - 1].c_str())])
			return (false);
		// std::cout << "PASS" <<std::endl;
		break;
	default:
		break;
	}
	return (true);
}

bool BitcoinExchange::isDate(std::string line)
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
	std::string s[3];
	for (j = 0; j <= 2; j++)
	{
		std::getline(sline, s[j], '-');
		// std::cout << "s[" << j << "] = " << s[j] << std::endl;
		switch (j)
		{
		case 0:
			if (s[j].length() != 4)
				return (false);
			if (!isValidDate(s, 0))
				return (false);
			break;
		case 1:
			if (s[j].length() != 2)
				return (false);
			if (!isValidDate(s, 1))
				return (false);
			break;
		case 2:
			if (s[j].length() != 2)
				return (false);
			if (!isValidDate(s, 2))
				return (false);
			break;
		
		default:
			break;
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
