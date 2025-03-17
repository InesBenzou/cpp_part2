#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    if (this != other)
    {
        this->_data = other.getData();
        this->value = other.getValue();
        this->data = other.getDate();
    }
}


BitcoinExchange::&operator = (BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_data = other.getData();
        this->value = other.getValue();
        this->data = other.getDate();
    }
    return (*this);
}

std::map<std::string, float> BitcoinExchange::getData()
{
    return _data;
}

std::string BitcoinExchange::getDate()
{
    return _date;
}

float BitcoinExchange::getValue()
{
    return _value;
}


void BitcoinExchange::setDate(std::string date)
{
    this->_date = date;
}

void BitcoinExchange::setValue(float value)
{
    this->_value = value;
}

void BitcoinExchange::setData(void)
{
    std::ifstream File("data.csv"); 
    if (!File.is_open())
        throw FileFailed();
    std::string line;
    std::getline(File, line);
    while (std::getline(File, line)) //je lis le file ligne par ligne, convertis les donnees et stocke
    {
        std::istringstream iss(line);
        std::string values;
        std::string date;
        if (std::getline (iss, date, ',') && std::getline(iss, values)) //extraction de la date jusqu'a la premiere virgule; value apres la virgule
        {
            float value;
            std::istringstream valueStream(values); // creation du flux : traite le str comme un flux pour mieux le manipuler
            valueStream >> value //conversion de la chaine en float
            _data[date] = value; //je mets date comme clé
        }
    }
}

bool BitcoinExchange::isValidShape()

void BitcoinExchange::handleInput(char *file)
{
    std::ifstream File(data.csv);
    if (!File.is_open())
        throw FileFailed();
    std::string line;
    std::getline(File, line);
    if (line != "date | value")
        throw InvalidFirstLine();
    while (std::getline(File, line))
    {
        try 
        {
            isValidShape(line);
            isExistingDate(_date);
            Calculate();
        }
        catch (const std::exception& e)
        {
            if (typeid(e) == typeid (InvalidShape))
                std::cerr << e.what() << line << std::endl;
            else 
                std::cerr << e.what() << std::endl;
        }
    }
}





BitcoinExchange::~BitcoinExchange()
{
    
}