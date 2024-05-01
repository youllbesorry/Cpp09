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
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>

bool is_valid_input(std::string str, std::vector<int> &vec, std::deque<int> &deq);
void print_vector(std::vector<int> &vec);
void print_deque(std::deque<int> &deq);
std::vector<int> generateJacobsthal(int n);

template <typename RandomAccessIterator>
void fordJohnsonMerge(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, const std::vector<int> &jacobsthal);
template <typename RandomAccessIterator>
void fordJohnsonSort(RandomAccessIterator first, RandomAccessIterator last);

template <typename RandomAccessIterator>
void fordJohnsonMerge(RandomAccessIterator first, RandomAccessIterator last, const std::vector<int> &jacobsthal)
{
    int n = last - first;
    if (n <= 1)
        return;
    int j = 0;
    while (jacobsthal[j] < n) ++j;
    RandomAccessIterator optimalMiddle = first + jacobsthal[j-1];

    // Appel récursif sur les deux moitiés
    fordJohnsonMerge(first, optimalMiddle, jacobsthal);
    fordJohnsonMerge(optimalMiddle, last, jacobsthal);

    // Fusionner les deux moitiés
    std::inplace_merge(first, optimalMiddle, last);
}

template <typename RandomAccessIterator>
void fordJohnsonSort(RandomAccessIterator first, RandomAccessIterator last) {
    int n = last - first;
    std::vector<int> jacobsthal = generateJacobsthal(n);
    fordJohnsonMerge(first, last, jacobsthal);
}

#endif

