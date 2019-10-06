#pragma once
#include "../Headers.hpp"
#include "../Heap.hpp"

__ALG__BEGIN__

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @param array
 * @return _ArrayType<T>&
 */
template <typename T, template <typename...> typename _ArrayType>
void heap_sort(_ArrayType<T> &array)
{
	make_heap(array);

	for (int i = array.size() - 1; i >= 1; --i)
	{
		std::swap(array[0], array[i]);
		move_down(array, 0, i - 1);
	}
}

__ALG__END__