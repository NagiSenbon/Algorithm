#pragma once
#include "../Headers.hpp"
#include "BubbleSort.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam __ArrayType
 * @param array
 */
template <typename T, template <typename...> typename __ArrayType>
void comb_sort(__ArrayType<T> &array)
{
	int step = array.size(), j, k;
	while ((step = int(step / 1.3)) > 1)
	{
		for (j = array.size() - 1; j >= step; --j)
		{
			k = j - step;
			if (array[j] < array[k])
				std::swap(array[j], array[k]);
		}
	}
	bubble_sort(array);
}

__ALG__END__
