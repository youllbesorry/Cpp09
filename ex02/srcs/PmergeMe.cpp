/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:21 by bfaure            #+#    #+#             */
/*   Updated: 2024/05/01 13:09:21 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool is_valid_input(std::string str, std::vector<int> &vec, std::deque<int> &deq)
{
    int num = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            std::cout << "Error" << std::endl << "You must use only positive numbers" << std::endl;
            return (false);
        }
        num = atoi(str.c_str());
        if (num < 0)
        {
            std::cout << "Error" << std::endl << "You must use only positive numbers" << std::endl;
            return (false);
        }
    }
    vec.push_back(num);
    deq.push_back(num);
    return (true);
}

void print_vector(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void print_deque(std::deque<int> &deq)
{
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}

std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> jacobsthal(n + 1);
    if (n >= 0)
        jacobsthal[0] = 0;
    if (n >= 1)
        jacobsthal[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }
    return (jacobsthal);
}

