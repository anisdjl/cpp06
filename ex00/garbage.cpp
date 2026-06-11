// #include "ScalarConverter.hpp"

// void	ScalarConverter::convert(std::string input)
// {
// 	if (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "-inf" || input == "-inff")
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
		
// 		if (input.find('f') != std::string::npos || input == "nanf")
// 		{
// 			std::cout << "float: " << (input == "nanf" ? "nanf" : input) << std::endl; // un soucis ici avec le inf et -inf
// 			std::cout << "double: " << (input == "nanf" ? "nan" : input.substr(0, input.length() - 1)) << std::endl;
// 		}
// 		else {
// 			std::string sign = (input[0] == '-') ? "-" : "";
// 			std::cout << "float: " << sign << "inff" << std::endl;
// 			std::cout << "double: " << sign << "inf" << std::endl;
// 		}
// 		return;
// 	}
// 	displayAsChar(input);
// 	displayAsInt(input);
// 	displayAsFloat(input);
// 	displayAsDouble(input);
// }

// void	displayAsChar(std::string input)
// {
// 	double	num;
// 	char	*end;

// 	num = std::strtod(input.c_str(), &end);
// 	if (input.length() == 1 && !std::isdigit(input[0]))
// 	{
// 		std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
// 		return ;
// 	}
// 	if (num != num || num < 0 || num > 127 || (input.find('.') != std::string::npos)) // number != number c'est pour le nan
// 	{
// 		std::cout << "char: impossible\n";
// 		return ;
// 	}
// 	else if (!isprint(num) || *end)
// 	{
// 		std::cout << "char: Non displayable\n";
// 		return ;
// 	}
// 	else
// 	{
// 		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
// 		return ;
// 	}
// }

// void	displayAsInt(std::string input)
// {
// 	double	num;
// 	char	*end;

// 	num = std::strtod(input.c_str(), &end);
// 	if (input.length() == 1 && !std::isdigit(input[0]))
// 	{
// 		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
// 		return ;
// 	}
// 	if (num != num || input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || num > INT_MAX || num < INT_MIN || !std::isdigit(input[0]))
// 	{
// 		std::cout << "int: impossible" << std::endl;
// 		return ;
// 	}
// 	else
// 	{
// 		std::cout << "int: " << static_cast<int>(num) << std::endl;
// 		return ;
// 	}
// }

// void	displayAsFloat(std::string input)
// {
// 	double	num;
// 	char	*end;

// 	num = std::strtod(input.c_str(), &end);
// 	if (input.length() == 1 && !std::isdigit(input[0]))
// 	{
// 		std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
// 		return ;
// 	}
// 	// if (input.find('.') != std::string::npos)
// 	// {
// 	// 	if (!(*end == 'f' && *(end + 1) == '\0'))
// 	// 	{
// 	// 		std::cout << "float: impossible" << std::endl;
// 	// 		return ;
// 	// 	}
// 	// }
// 	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
// 	{
// 		std::cout << "float: impossible" << std::endl;
// 		return ;
// 	}
// 	if (num == std::floor(num) && num < 1000000)
// 		std::cout << std::fixed << std::setprecision(1);
// 	else
// 		std::cout << std::setprecision(6);
// 	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
// 	return ;
// }

// void	displayAsDouble(std::string input)
// {
// 	double	num;
// 	char	*end;

// 	num = std::strtod(input.c_str(), &end);
// 	if (input.length() == 1 && !std::isdigit(input[0]))
// 	{
// 		std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
// 		return ;
// 	}
// 	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min())
// 	{
// 		std::cout << "double: impossible" << std::endl;
// 		return ;
// 	}
// 	if (num == static_cast<long>(num))
//         std::cout << std::setprecision(1);
//     else
//         std::cout << std::setprecision(5);

//     std::cout << "double: " << static_cast<double>(num) << std::endl;
// 	return ;
// }