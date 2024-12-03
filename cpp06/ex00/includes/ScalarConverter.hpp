#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <string>
#include <iostream>

class ScalarConverter
{
	private :

	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
        ScalarConverter operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(std::string literal);
};


#endif