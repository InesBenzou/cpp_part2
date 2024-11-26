#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

class Bureaucrat
{
    private :
    	const std::string  _name;
    	int                 _grade;

    public : 
        Bureaucrat ();
        Bureaucrat(const Bureaucrat& other);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
		void setGrade(int grade);
        Bureaucrat operator=(const Bureaucrat& other);
        ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

class GradeTooHighException : public std::exception
    {
        public :
        virtual const char* what() const throw ()
        {
            return ("Invalid grade");
        }
    };


class GradeTooLowException : public std::exception
    {
        public :
        virtual const char* what() const throw ()
        {
            return ("Invalid grade");
        }
    };

#endif