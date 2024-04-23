/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:36:29 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/23 13:56:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include <algorithm>

class BitcoinExchange
{
	public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		static std::map<int, int> getCalendar();
		void fillMap();
		void parsing(std::string infile);
		void initCalendar();
		bool isValidDate(std::string *line, int n);
		bool isDate(std::string line);
		bool isValidValue(std::string line);
		void calculate(std::string date, std::string value);

	private :
		std::map<std::string, double> _coin;
		std::map<int, int> _calendar;
};


#endif