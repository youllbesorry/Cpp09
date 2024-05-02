/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure < bfaure@student.42lyon.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:36 by bfaure            #+#    #+#             */
/*   Updated: 2024/05/01 13:09:36 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>

bool is_valid_input(std::string str, std::vector<int> &vec, std::deque<int> &deq);
void print_vector(std::vector<int> &vec);
void print_deque(std::deque<int> &deq);

template <typename Container>
Container generateJacobsthal(int n);
template <typename RandomAccessIterator, typename Container>
void fordJohnsonSort(RandomAccessIterator first, RandomAccessIterator last, std::string container);
template <typename RandomAccessIterator, typename Container>
void fordJohnsonMerge(RandomAccessIterator first, RandomAccessIterator last, const Container &jacobsthal);

template <typename RandomAccessIterator, typename Container>
void fordJohnsonMerge(RandomAccessIterator first, RandomAccessIterator last, const Container &jacobsthal)
{
    int n = last - first;
    if (n <= 1)
        return;
    int j = 0;
    while (static_cast<size_t>(j) < jacobsthal.size() && jacobsthal[j] < n)
        ++j;
    RandomAccessIterator optimalMiddle = first + jacobsthal[j - 1];
    fordJohnsonMerge<RandomAccessIterator, Container>(first, optimalMiddle, jacobsthal);
    fordJohnsonMerge<RandomAccessIterator, Container>(optimalMiddle, last, jacobsthal);

    std::inplace_merge(first, optimalMiddle, last);
}

template <typename RandomAccessIterator, typename Container>
void fordJohnsonSort(RandomAccessIterator first, RandomAccessIterator last, std::string container)
{
    int n = last - first;
    Container jacobsthal;
    if (container == "vector")
        jacobsthal = generateJacobsthal<Container>(n);
    else if (container == "deque")
        jacobsthal = generateJacobsthal<Container>(n);
    fordJohnsonMerge<RandomAccessIterator, Container>(first, last, jacobsthal);
}

template <typename Container>
Container generateJacobsthal(int n)
{
    Container jacobsthal(n + 1);
    if (n >= 0)
        jacobsthal[0] = 0;
    if (n >= 1)
        jacobsthal[1] = 1;
    for (int i = 2; i <= n; ++i)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    return (jacobsthal);
}

#endif

