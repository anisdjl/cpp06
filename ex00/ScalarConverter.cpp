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
	if (input.empty())
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
	displayAsChar(input);
	displayAsInt(input);
	displayAsFloat(input);
	displayAsDouble(input);
}

void	displayAsChar(std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		std::cout << "char: '" << input[0] << "'" << std::endl;
		return ;
	}
	
	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) // si il a une fin et que ce n'est pas un f c'est impossible
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (num != num || num > 127 || num < 0) // si il est en dehors de la table ascii ou que c'est un nan
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(static_cast<int>(num))) // si il est pas prinatble
	{
		std::cout << "char: non displayable" << std::endl;
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
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		return ;
	}

	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) // si il a une fin et que ce n'est pas un f c'est impossible
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (num!= num || num > INT_MAX || num < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	return ;
}

void	displayAsFloat(std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		return ;
	}

	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) // si il a une fin et que ce n'est pas un f c'est impossible
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (num!= num)
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (num == std::numeric_limits<double>::infinity())
	{
		std::cout << "float: inff" << std::endl;
		return ;
	}
	if (num == -std::numeric_limits<double>::infinity())
	{
		std::cout << "float: -inff" << std::endl;
		return ;
	}
	if (num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	if (num == static_cast<long>(num))
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
        std::cout.unsetf(std::ios::fixed); // On reset le flux pour la suite
    }
    else
    {
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    }
}

void	displayAsDouble(std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
		return ;
	}

	double	num;
	char	*end;

	num = std::strtod(input.c_str(), &end);
	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) // si il a une fin et que ce n'est pas un f c'est impossible
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (num!= num)
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (num == std::numeric_limits<double>::infinity())
	{
		std::cout << "double: inf" << std::endl;
		return ;
	}
	if (num == -std::numeric_limits<double>::infinity())
	{
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	if (num > std::numeric_limits<double>::max() || num < -std::numeric_limits<double>::max())
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (num == static_cast<long>(num))
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
        std::cout.unsetf(std::ios::fixed); // On reset le flux pour la suite
    }
    else
    {
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
}
