#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

template <typename T, template <typename...> typename _ArrayType, typename _Fn>
inline int three_mid(const _ArrayType<T> &array, int first, int last, _Fn func)
{
	if (first >= last)
		return first;
	int l = first, r = last;
	int m = ((r + l) >> 1);
	if (func(array[l]) <= func(array[m]))
	{
		if (func(array[m]) <= func(array[r]))
			return m;
		else if (func(array[l]) <= func(array[r]))
			return r;
		else
			return l;
	}
	else
	{
		if (func(array[m]) >= func(array[r]))
			return m;
		else if (func(array[l]) <= func(array[r]))
			return l;
		else
			return r;
	}
}

template <typename T, template <typename...> typename _ArrayType, typename _Fn>
inline int three_mid(const _ArrayType<T> &array, _Fn func)
{
	return three_mid(array, 0, array.size() - 1, func);
}

template <typename T, template <typename...> typename _ArrayType>
inline int three_mid(const _ArrayType<T> &array)
{
	return three_mid(array, f_return_itself_value<T>);
}

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @tparam _Fn
 * @param array
 * @param first
 * @param last
 * @param func
 * @return int
 */
template <typename T, template <typename...> typename _ArrayType, typename _Fn>
int partition(_ArrayType<T> &array, int first, int last, _Fn func)
{
	if (first >= last)
		return -1;

	// int index = first + Randint() % (last - first);
	int index = three_mid(array, first, last, func);
	std::swap(array[first], array[index]);

	T pivot = array[first];
	// array_print(array);
	// std::cout << "pivot: " << pivot
	// 		  << " first: " << first
	// 		  << " mid: " << index
	// 		  << " last: " << last
	// 		  << "\n"
	// 		  << std::endl;
	int l = first + 1, r = last;
	while (l <= r)
	{
		if (func(array[l]) <= func(pivot))
			++l;
		else
			std::swap(array[l], array[r--]);
	}
	std::swap(array[first], array[--l]);
	return l;
}

template <typename T, template <typename...> typename _ArrayType, typename _Fn>
inline int partition(_ArrayType<T> &array, _Fn func)
{
	return partition(array, 0, array.size() - 1, func);
}

template <typename T, template <typename...> typename _ArrayType>
inline int partition(_ArrayType<T> &array)
{
	return partition(array, f_return_itself_value<T>);
}

/**
 * @brief
 *
 * @tparam T
 * @tparam _ArrayType
 * @tparam _Fn
 * @param array
 * @param low
 * @param high
 * @param func
 */
template <typename T, template <typename...> typename _ArrayType, typename _Fn>
void quick_sort(_ArrayType<T> &array, int low, int high, _Fn func)
{
	if (low >= high)
		return;

	int mid = partition(array, low, high, func);
	// std::cout << "mid = " << mid << std::endl;
	if (mid > 0)
	{
		if (low < mid)
			quick_sort(array, low, mid - 1, func);
		if (mid < high)
			quick_sort(array, mid + 1, high, func);
	}
}

template <typename T, template <typename...> typename _ArrayType, typename _Fn>
inline void quick_sort(_ArrayType<T> &array, _Fn func)
{
	quick_sort(array, 0, array.size() - 1, func);
}

template <typename T, template <typename...> typename _ArrayType>
inline void quick_sort(_ArrayType<T> &array)
{
	quick_sort(array, f_return_itself_value<T>);
}

__ALG__END__
