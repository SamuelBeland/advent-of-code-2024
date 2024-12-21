#pragma once

#include "Point.hpp"

#include <cstddef>
#include <vector>

namespace sb
{
	template<typename T> struct Field
	{
		std::size_t width;
		std::size_t height;
		std::vector<T> data;

		[[nodiscard]] constexpr std::size_t size() const noexcept;

		void resize(std::size_t new_width, std::size_t new_height);

		template<typename Point>
		[[nodiscard]] std::size_t get_data_offset(Point const& point) const noexcept;

		template<typename Point> [[nodiscard]] T& operator[](Point const& point);

		template<typename Point> [[nodiscard]] T const& operator[](Point const& point) const;

		template<typename Point> [[nodiscard]] bool is_valid_position(Point const& point) const;
	};
} // namespace sb

#include "inl/Field.inl"
