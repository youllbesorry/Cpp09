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

std::vector<int> vec;
std::deque<int> deq;

int main(int argc, char **argv)
{
	if (argc < 2)
	{
        std::cout << "Error" << std::endl << "You must use this program as follow : ./PmergeMe <sequence>" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        if (!is_valid_input(argv[i], vec, deq))
            return (1);
    }
    std::cout << "Before :";
    print_vector(vec);
    std::cout << std::endl;
    clock_t startVec = clock();
    fordJohnsonSort<std::vector<int>::iterator, std::vector<int> >(vec.begin(), vec.end(), "vector");
    clock_t endVec = clock();
    std::cout << "After :";
    print_vector(vec);
    std::cout << std::endl;
    clock_t startDeq = clock();
    fordJohnsonSort<std::deque<int>::iterator, std::deque<int> >(deq.begin(), deq.end(), "deque");
    clock_t endDeq = clock();
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << std::fixed << static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC << " us" << std::endl;
    return (0);
}

