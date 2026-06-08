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

	displayAsChar(input);
	displayAsInt(input);
	displayAsFloat(input);
	displayAsDouble(input);
}

void	displayAsChar(std::string input)
{
	double	number;
	char	*end;

	number = std::strtod(input.c_str(), &end);
	if (number != number || number < 0 || number > 127) // number != number c'est pour le nan
	{
		std::cout << "Char: impossible\n";
		return ;
	}
	else
	{
		std::cout << "Char: " << static_cast<char>(number) << std::endl;
		return ;
	}
}

void	displayAsInt(std::string input)
{

}

void	displayAsFloat(std::string input)
{

}

void	displayAsDouble(std::string input)
{

}
