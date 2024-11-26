#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private :
        std::string const   _name;
        bool                _isSigned; 
        const int        _gradeToSign;
        const int         _gradeToExecute;
    public :
        Form();
        Form(const Form& other);
        Form &operator=(const Form& other);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExectute() const ;
        void beSigned(Bureaucrat b);
        ~Form();
	class GradeTooHighException : public std::exception
		{
			public : 
				virtual const char* what() const throw ()
				{
					return ("Invalid grade : impossible to sign, grade too High");
				}
		};

	class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw ()
				{
					return ("Invalid grade : impossible to sign, grade too Low");
				}
		};
};

std::ostream& operator<<(std::ostream& out, const Form& other);


#endif