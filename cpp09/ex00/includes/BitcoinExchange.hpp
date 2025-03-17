#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <fstream> //travailler avec des files
#include <sstream> //travailler avec des flux de chaine
#include <stdexcept>

#define RED  "\033[31m"
#define GREEN  "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class InvalidFormat: public std::exception
{
    public : 
        const char* what() const throw()
        {
            return RED "Error: wrong input ";
        }
};

class NoCloserData: public std::exception
{
    public:
        const char* what() const throw()
        {
            return RED "Error: no closer data";
        }
};

class FileFailed: public std::exception
{
    public:
        const char* what() const throw()
        {
            return RED "Error: file exploitation failed" RESET;
        }
};

class InvalidNumber: public std::exception
{
    public:
        const char* what() const throw()
        {
            return RED "Error: invalid number" RESET;
        }
};

class InvalidFirstLine: public std::exception
{
    public:
        const char* what() const throw()
        {
            return RED "Error: the first line must be [data | value]" RESET;
        }
};

class InvalidDate: public std::exception
{
    public:
        const char* what() const throw()
        {
            return RED "Error: invalid date" RESET;
        }
}

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        std::string                  _date;
        float                        _value;
    
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinEchange &other);
        ~BitcoinExchange();

        std::map<std::strinf, float> getData();
        void setData();
        std::string getDate() const;
        float getValue() const;
        void setDate(std::string date);
        void setValue(float value);

        void handleInput(char *file);
        bool isValidShape(const std::strinf &line);
        bool isValidDate(std::string &date);
        bool isValidValue(float &value);
        bool isExistingDate(std::string &date);
        std::ifstream openFile(const std::string &files);
        void getResult();
        void Calculate();
};

#endif