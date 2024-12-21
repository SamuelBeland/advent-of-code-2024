#include "days.hpp"

#include <adventlib/Parser.hpp>
#include <adventlib/utilities.hpp>

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

	std::vector<IdPair> parse_input(std::string_view str)
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
} // namespace

std::string sb::day_1_1(std::string const& input)
{
	std::vector<IdPair> const id_pairs = parse_input(input);
	IdLists id_lists = split_id_lists(id_pairs);
	id_lists = sort_id_lists(std::move(id_lists));
	IdDiff const id_diff = get_id_diff_sum(id_lists);

	return sb::to_string(id_diff);
}

std::string sb::day_1_2(std::string const& /*input*/)
{
	return "";
}
