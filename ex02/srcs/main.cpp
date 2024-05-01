/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:18 by bfaure            #+#    #+#             */
/*   Updated: 2024/05/01 13:09:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
        std::cout << "Error" << std::endl << "You must use this program as follow : ./PmergeMe <sequence>" << std::endl;
        return (1);
    }
    std::vector<int> vec;
    std::deque<int> deq;
    for (int i = 1; i < argc; i++)
    {
        std::cout << "argv[i] : " << argv[i] << std::endl;
        if (!is_valid_input(argv[i], vec, deq))
            return (1);
    }
    std::cout << "Before :";
    print_vector(vec);
    std::cout << std::endl;
    fordJohnsonSort(vec.begin(), vec.end());
    std::cout << "After :";
    print_vector(vec);
    std::cout << std::endl;
    return (0);
}

