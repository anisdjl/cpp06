#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of input, try with this format : ./convert '...'";
		return (0);
	}

	std::string input;
	input = argv[1];
	ScalarConverter::convert(input);

	return (0);
}