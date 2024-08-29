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
    if (str[0] == '\0')
    {
        std::cout << "Error" << std::endl << "You must use only positive integer" << std::endl;
        return (false);
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '\0')
        {
            std::cout << "Error" << std::endl << "You must use only positive integer" << std::endl;
            return (false);
        }
        if (!isdigit(str[i]))
        {
            std::cout << "Error" << std::endl << "You must use only positive integer" << std::endl;
            return (false);
        }
        num = atoi(str.c_str());
        if (num < 0)
        {
            std::cout << "Error" << std::endl << "You must use only positive integer" << std::endl;
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

