#include "days.hpp"

#include <adventlib/Parser.hpp>
#include <adventlib/utilities.hpp>

#include <limits>
#include <numeric>

namespace
{
	using Id = std::int32_t;
	using IdDiff = Id;

	struct IdPair
	{
		Id left;
		Id right;
	};

	IdPair parse_id_pair(std::string_view str)
	{
		::IdPair result;
		sb::scan(str, "{}   {}", result.left, result.right);
		return result;
	}

	std::vector<IdPair> parse_id_pairs(std::string_view str)
	{
		return sb::transform(sb::split_lines(str), parse_id_pair);
	}

	struct IdLists
	{
		std::vector<Id> left;
		std::vector<Id> right;
	};

	IdLists split_id_lists(std::vector<IdPair> const& id_pairs)
	{
		IdLists id_lists;
		id_lists.left.resize(id_pairs.size());
		id_lists.right.resize(id_pairs.size());

		for (std::size_t i = 0; i < id_pairs.size(); ++i)
		{
			id_lists.left[i] = id_pairs[i].left;
			id_lists.right[i] = id_pairs[i].right;
		}

		return id_lists;
	}

	IdLists sort_id_lists(IdLists id_lists)
	{
		std::sort(id_lists.left.begin(), id_lists.left.end());
		std::sort(id_lists.right.begin(), id_lists.right.end());

		return id_lists;
	}

	IdLists parse_sorted_id_lists(std::string_view str)
	{
		return sort_id_lists(split_id_lists(parse_id_pairs(str)));
	}

	IdDiff get_id_diff_sum(IdLists const& id_lists)
	{
		assert(id_lists.left.size() == id_lists.right.size());

		IdDiff sum = 0;

		for (std::size_t i = 0; i < id_lists.left.size(); ++i)
		{
			sum += std::abs(id_lists.left[i] - id_lists.right[i]);
		}

		return sum;
	}

	IdDiff get_similarity_score(IdLists const& id_lists)
	{
		auto next_right_id = id_lists.right.begin();

		auto const has_next_right_id = [&]() -> bool
		{ return next_right_id != id_lists.right.end(); };

		Id right_id;
		IdDiff right_id_occurence;

		auto const load_next_right_id = [&]() -> void
		{
			assert(has_next_right_id());
			right_id_occurence = 1;
			right_id = *next_right_id++;
			while (has_next_right_id() && *next_right_id == right_id)
			{
				++right_id_occurence;
				++next_right_id;
			}
		};

		load_next_right_id();

		IdDiff similarity_score = 0;

		for (Id const left_id: id_lists.left)
		{
			while (has_next_right_id() && left_id > right_id)
			{
				load_next_right_id();
			}

			if (left_id == right_id)
			{
				similarity_score += right_id * right_id_occurence;
			}
		}

		return similarity_score;
	}
} // namespace

std::string sb::day_1_1(std::string const& input)
{
	IdLists const id_lists = parse_sorted_id_lists(input);
	IdDiff const id_diff = get_id_diff_sum(id_lists);

	return sb::to_string(id_diff);
}

std::string sb::day_1_2(std::string const& input)
{
	IdLists const id_lists = parse_sorted_id_lists(input);
	IdDiff const id_diff = get_similarity_score(id_lists);

	return sb::to_string(id_diff);
}
