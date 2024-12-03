#include "../includes/ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error:\nPlease enter what you want to convert" << std::endl;
		return 1;
	}
	ScalarConverter converter;
	converter.convert(argv[1]);
}