#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <string>
#include <iostream>

class GradeTooHighException : public std::exception
{
	public : 
		virtual const char* what() const throw ()
		{
			return ("Invalid grade : grade too High");
		}
};

class GradeTooLowException : public std::exception
{
	public :
		virtual const char* what() const throw ()
		{
			return ("Invalid grade : grade too Low");
		}
};


class FormNotSignedException : public std::exception
{
	public :
		virtual const char* what() const throw ()
		{
			return ("Unsigned Form : please sign the form");
		}
};

class FileCreationException : public std::exception
{
	public :
		virtual const char* what() const throw ()
		{
			return ("Error: Unable to create the file");
		}
};

#endif