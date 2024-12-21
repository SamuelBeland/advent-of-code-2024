#pragma once

#include "Direction.hpp"

#include <type_traits>

namespace sb
{
	template<typename T, typename DirectionParams = sb::DirectionParams<>> struct Point
	{
		T x;
		T y;

		using Direction = typename DirectionParams::Direction;
		static constexpr auto& DIRECTIONS = DirectionParams::DIRECTIONS;

		// comparison
		[[nodiscard]] constexpr bool operator==(Point const& other) const noexcept;
		[[nodiscard]] constexpr bool operator!=(Point const& other) const noexcept;

		// math
		[[nodiscard]] constexpr Point operator-(Point const& other) const noexcept;
		[[nodiscard]] constexpr T manhattan_distance(Point const& other) const noexcept;
		[[nodiscard]] constexpr Point move_once(Direction direction) const noexcept;
	};

	template<typename T, typename DirectionParams>
	[[nodiscard]] T manhattan_distance(Point<T, DirectionParams> const& lhs,
									   Point<T, DirectionParams> const& rhs) noexcept;

	template<typename T> struct is_point: std::false_type
	{
	};

	template<typename T, typename DirectionParams>
	struct is_point<Point<T, DirectionParams>>: std::true_type
	{
	};
} // namespace sb

#include "inl/Point.inl"
