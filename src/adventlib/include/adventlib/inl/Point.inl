#pragma once

#include "../Point.hpp"

#include <cmath>

template<typename T, typename DirectionParams>
constexpr T sb::Point<T, DirectionParams>::manhattan_distance(
	Point<T, DirectionParams> const& other) const noexcept
{
	return std::abs(x - other.x) + std::abs(y - other.y);
}

template<typename T, typename DirectionParams>
constexpr sb::Point<T, DirectionParams>
sb::Point<T, DirectionParams>::move_once(Direction direction) const noexcept
{
	Point result{ *this };

	switch (direction)
	{
	case Direction::north:
		--result.y;
		break;
	case Direction::east:
		++result.x;
		break;
	case Direction::south:
		++result.y;
		break;
	case Direction::west:
		--result.x;
		break;
	}

	return result;
}

template<typename T, typename DirectionParams>
constexpr sb::Point<T, DirectionParams>
sb::Point<T, DirectionParams>::operator-(sb::Point<T, DirectionParams> const& other) const noexcept
{
	return sb::Point<T>{ x - other.x, y - other.y };
}

template<typename T, typename DirectionParams>
constexpr bool
sb::Point<T, DirectionParams>::operator==(sb::Point<T, DirectionParams> const& other) const noexcept
{
	return x == other.x && y == other.y;
}

template<typename T, typename DirectionParams>
constexpr bool
sb::Point<T, DirectionParams>::operator!=(sb::Point<T, DirectionParams> const& other) const noexcept
{
	return !(*this == other);
}

template<typename T, typename DirectionParams>
T sb::manhattan_distance(sb::Point<T, DirectionParams> const& lhs,
						 sb::Point<T, DirectionParams> const& rhs) noexcept
{
	return lhs.manhattan_distance(rhs);
}
