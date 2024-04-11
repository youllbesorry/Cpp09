/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:17:47 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/11 13:36:42 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	BitcoinExchange bit;

	bit.initCalendar();
	bit.fillMap();
	bit.calculate(argv[1]);

	return (0);
}