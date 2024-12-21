#include <adventlib/utilities.hpp>

#include <cassert>
#include <fstream>
#include <sstream>

std::string sb::read_all(char const* input_file_path)
{
	std::ifstream t(input_file_path);
	assert(t.is_open());
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

std::vector<std::string_view> sb::split_lines(std::string_view str)
{
	return split(str, '\n');
}
