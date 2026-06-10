#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    if (this != &src) {

    }
    return *this;
}

void	ScalarConverter::convert(std::string input)
{
	// je dois chekcer si c'est pas un char bizzare, non affichable
	// je dois trouver le type de base 
	// ensuite je dois checker ses limites pour tout ce qui est overflow
	// ensuite je cast

	double	number;
	char	*end;
	number = std::strtod(input.c_str(), &end);

	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		number = static_cast<double>(input[0]);
	}
	if (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		
		if (input.find('f') != std::string::npos || input == "nanf")
		{
			std::cout << "float: " << (input == "nanf" ? "nanf" : input) << std::endl;
			std::cout << "double: " << (input == "nanf" ? "nan" : input.substr(0, input.length() - 1)) << std::endl;
		}
		else
		{
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
		}
		return;
	}
	(void)number;
	displayAsChar(input);
	displayAsInt(input);
	displayAsFloat(input);
	displayAsDouble(input);
}

void	displayAsChar(std::string input)
{
	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (num != num || num < 0 || num > 127) // number != number c'est pour le nan
	{
		std::cout << "char: impossible\n";
		return ;
	}
	else if (!isprint(num))
	{
		std::cout << "char: Non displayable\n";
		return ;
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		return ;
	}
}

void	displayAsInt(std::string input)
{
	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || num > INT_MAX || num < INT_MIN || !std::isdigit(input[0]))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		return ;
	}
}

void	displayAsFloat(std::string input)
{
	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (!(*end == 'f' && *(end + 1) == '\0'))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
	{
		std::cout << "float: impossible 2" << std::endl;
		return ;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		return ;
	}
}

void	displayAsDouble(std::string input)
{
	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	else
	{
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		return ;
	}
}
