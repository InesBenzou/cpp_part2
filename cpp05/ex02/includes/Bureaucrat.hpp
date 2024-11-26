#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private :
    	const std::string			_name;
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
        void signForm (AForm& form); //faire passer une reference de la classe (abstraite direct interdit)
        void executeForm(AForm const & form) const;
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif
