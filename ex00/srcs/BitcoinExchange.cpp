/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:49 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/24 13:59:52 by bfaure           ###   ########lyon.fr   */
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

bool BitcoinExchange::isValidValue(std::string line)
{
	if (atoi(line.c_str()) < 0)
		return (false);
	return (true);
}

bool BitcoinExchange::isValidDate(std::string *line, int n)
{
	switch (n)
	{
	case 0:
		if (atoi(line[n].c_str()) < 2009 || atoi(line[n].c_str()) > 2024)
			return (false);
		break;
	case 1:
		if (atoi(line[n].c_str()) <= 0 || atoi(line[n].c_str()) > 12)
			return (false);
		break;
	case 2:
		if (atoi(line[1].c_str()) == 2 && ((atoi(line[0].c_str()) % 4 == 0 && atoi(line[0].c_str()) % 100 != 0) || (atoi(line[0].c_str()) % 400 == 0 && atoi(line[0].c_str()) % 100 != 0)))
		{
			if (atoi(line[n].c_str()) <= 0 || atoi(line[n].c_str()) > 29)
				return (false);
		}
		else if (atoi(line[n].c_str()) <= 0 || atoi(line[n].c_str()) > _calendar[atoi(line[1].c_str())])
			return (false);
		break;
	default:
		break;
	}
	return (true);
}

bool BitcoinExchange::isDate(std::string line)
{
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

void BitcoinExchange::calculate(std::string date, std::string value)
{
	std::map<std::string, double>::iterator it = _coin.upper_bound(date);
	if (it == _coin.end())
		it--;
	if (_coin.upper_bound(date) != _coin.find(date))
		it--;
	std::cout << date << " => " << value << " = " << it->second * atof(value.c_str()) << std::endl;
}

void BitcoinExchange::parsing(std::string infile)
{
	std::cout << "infile = " << infile << std::endl;
	std::ifstream 	file(infile.c_str());
	std::string 	line;
	int 			notPass = 0;
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
			notPass = 0;
			if (!isDate(part1))
			{
				std::cout << "Error" << std::endl;
				notPass++;
				continue ;
			}
			if (!isValidValue(part2))
			{
				std::cout << "Wrong value" << std::endl;
				notPass++;
			}
			if (notPass == 0)
			{
				calculate(part1, part2);
			}
			
		}
	}
	else
		std::cout << "Cannot open the file" << std::endl;
}
