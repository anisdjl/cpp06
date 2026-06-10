#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of input, try with this format : ./convert '...'" << std::endl;
		return (0);
	}

	std::string input;
	input = argv[1];
	ScalarConverter::convert(input);

	return (0);
}
