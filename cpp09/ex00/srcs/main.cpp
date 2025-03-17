#include "../includes/BitcoinEchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED << "Error: please enter 2 arguments" << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange change;
        change.setData();
        change.handleInput(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
