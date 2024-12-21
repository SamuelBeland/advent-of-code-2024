#pragma once

#include "../Direction.hpp"

#include "../utilities.hpp"

template<typename Direction> constexpr Direction sb::get_opposite(Direction direction) noexcept
{
	// static_assert(sb::is_direction<std::decay_t<Direction>>::value);

	switch (direction)
	{
	case Direction::north:
		return Direction::south;
	case Direction::east:
		return Direction::west;
	case Direction::south:
		return Direction::north;
	case Direction::west:
		return Direction::east;
	}
	sb::unreachable();
}

template<typename Direction> constexpr bool sb::is_opposite(Direction lhs, Direction rhs) noexcept
{
	return lhs == sb::get_opposite(rhs);
}
