#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Exceptions.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5)
{
	_target = "Default's target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential Pardon", 25, 5)
{
	_target = other._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade () > getGradeToExecute())
		throw GradeTooLowException();
	
	if (executor.getGrade() >=0)
		std::cout << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
	
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form)
{
	out << "Presidential Pardon Form : " << form.getName() << "\n"
	<< "Target :" << form.getTarget() << "\n";
	return out;
}


PresidentialPardonForm::~PresidentialPardonForm(){}