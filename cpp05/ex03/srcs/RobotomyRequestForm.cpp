#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Exceptions.hpp"
#include <cstdlib> 
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
	_target = "Default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	_target = other._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(static_cast<unsigned int>(time(0)));
    int success = rand() % 2;

	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade () > getGradeToExecute())
		throw GradeTooLowException();
	
	if (executor.getGrade() >=0)
	{
		std::cout << "Bip Bop... Whirr... clank... bzzt..";
		if (success)
		{
			std::cout << _target
					<< " has been robotomized successfully." << std::endl;
		}
		else
			std::cout << "The robotomy of" << _target << " failed." << std::endl;   
	}
	

}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form)
{
	out << "Robotomy Requet Form : " << form.getName() << "\n"
	<< "Target :" << form.getTarget() << "\n";
	return out;
}


RobotomyRequestForm::~RobotomyRequestForm(){}