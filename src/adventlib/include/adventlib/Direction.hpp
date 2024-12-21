#pragma once

#include <type_traits>

namespace sb
{
	enum class DirectionChange
	{
		none,
		turn_left,
		turn_right,
		opposite,
	};

	template<typename T = int, T N = 0, T E = 1, T S = 2, T W = 3> struct DirectionParams
	{
		enum class Direction : T
		{
			north = N,
			east = E,
			south = S,
			west = W,
		};

		static constexpr Direction DIRECTIONS[] = { Direction::north, Direction::east,
													Direction::south, Direction::west };
	};

	template<typename T> struct is_direction: std::false_type
	{
	};

	template<typename T, T N, T E, T S, T W>
	struct is_direction<DirectionParams<T, N, E, S, W>>: std::true_type
	{
	};

	template<typename Direction>
	[[nodiscard]] constexpr Direction get_opposite(Direction direction) noexcept;

	template<typename Direction>
	[[nodiscard]] constexpr bool is_opposite(Direction lhs, Direction rhs) noexcept;
} // namespace sb

#include "inl/Direction.inl"
