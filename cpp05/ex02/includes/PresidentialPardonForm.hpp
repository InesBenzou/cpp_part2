#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm 
{
	private :
		std::string _target;
	public :
		PresidentialPardonForm ();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm &operator = (const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& other);

#endif
