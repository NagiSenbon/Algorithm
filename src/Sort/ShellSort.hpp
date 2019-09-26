#pragma once
#include "../Headers.hpp"
#include "InsertionSort.hpp"

__ALGO__BEGIN__

template <typename T>
std::vector<T> &shellSort(std::vector<T> &array)
{
	std::vector<int> G;
	int g = 0;
	while (g < array.size())
	{
		g = 3 * g + 1;
		G.push_back(g);
	}
	for (int i = array.size() - 1; i >= 0; i--)
	{
		alg::insertionSort(array, G[i]);
	}
	return array;
}

__ALGO__END__