/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:26:30 by bfaure            #+#    #+#             */
/*   Updated: 2024/04/24 14:40:47 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Wrond number of arguments" << std::endl;
		return (1);
	}
	RPN rpn;
	rpn.parsing(argv[1]);
	return (0);
}