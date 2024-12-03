#include "../includes/ScalarConverter.hpp"

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, INVALID };

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return *this;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

LiteralType whichType(const std::string& literal)
{
	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return CHAR;
	if (literal.find('.') == std::string::npos)
	{
		try 
		{
			std::stoi(literal);
			return INT;
		}
		catch (...)
		{
			return INVALID;
		}
	}
	if (literal.back() == 'f')
	{
        try
		{
            std::stof(literal);
            return FLOAT;
        }
		catch (...)
		{
            return INVALID;
        }
    }

    try
	{
        std::stod(literal);
        return DOUBLE;
    }
	catch (...)
	{
        return INVALID;
    }
}		

void ScalarConverter::convert(std::string literal)
{
	(void)literal;
	
	//Convertir le string dans son cast correct
	//le caster en char, int, float, long
	//afficher 
	return;
}