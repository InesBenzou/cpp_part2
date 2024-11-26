#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
	public : 
		ShrubberyCreationForm();
    	ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm & other);
		~ShrubberyCreationForm();

		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& other);


#endif