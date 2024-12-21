#pragma once

#include "../Field.hpp"

template<typename T> constexpr std::size_t sb::Field<T>::size() const noexcept
{
	return width * height;
}

template<typename T> void sb::Field<T>::resize(std::size_t new_width, std::size_t new_height)
{
	width = new_width;
	height = new_height;
	data.resize(size());
}

template<typename T>
template<typename Point>
std::size_t sb::Field<T>::get_data_offset(Point const& point) const noexcept
{
	static_assert(sb::is_point<Point>::value);
	return (std::size_t)point.x + (std::size_t)point.y * width;
}

template<typename T> template<typename Point> T& sb::Field<T>::operator[](Point const& point)
{
	return data[get_data_offset(point)];
}

template<typename T>
template<typename Point>
inline T const& sb::Field<T>::operator[](Point const& point) const
{
	return data[get_data_offset(point)];
}

template<typename T>
template<typename Point>
bool sb::Field<T>::is_valid_position(Point const& point) const
{
	static_assert(sb::is_point<Point>::value);

	return point.x >= 0 && point.x < width && point.y >= 0 && point.y < height;
}
