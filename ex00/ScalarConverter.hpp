#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <climits> // pour les limtes de int
#include <string> // .find() .find_last_of() .find_first_of()
#include <cmath> // pour les autres limites
#include <cfloat> // pour les limtes de floats
#include <cstdlib> // pour strtod
#include <cctype> // pour le isdigit isnum isprint
#include <iomanip>
#include <fstream>

class ScalarConverter {
    private:
		ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
    public:
        static void convert(std::string input);
};

void	displayAsChar(std::string input);
void	displayAsInt(std::string input);
void	displayAsFloat(std::string input);
void	displayAsDouble(std::string input);

#endif
