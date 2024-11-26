#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat() : _name ("default_name")
{
    _grade = -25;
	try 
	{
		if (_grade <= 1)
            throw GradeTooHighException();
		else if (_grade >= 150)
            throw GradeTooLowException();
	}
	catch (GradeTooHighException& e)
    {
		std::cerr << "\033[33mConstructing " << this->getName() <<
	 	 " failed: " << e.what() << std::endl <<
	 	 "Grade now set to 1" << "\033[0m" << std::endl;
	 	 this->setGrade(1);
    }
	catch (GradeTooLowException& e)
    {

		std::cerr << "\033[33mConstructing " << this->getName() <<
	 	 " failed: " << e.what() << std::endl <<
	 	 "Grade now set to 150" << "\033[0m" << std::endl;
	 	 this->setGrade(150);
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)  : _name(other.getName() + "_copy") 
{
    _grade = other._grade;
}

Bureaucrat Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
    _grade = other.getGrade();
    return (*this);
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    try 
    {
        if (_grade <= 1)
            throw GradeTooHighException();
        else 
        {
            _grade--;
            return;
        }
    }
    catch (GradeTooHighException& e)
    {
        std::string error;
        error = e.what();
        std::cout << error << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try 
    {
        if (_grade >= 150)
            throw GradeTooLowException();
        else 
        {
            _grade++;
            return;
        }
    }
    catch (GradeTooLowException& e)
    {
        std::string error;
        error = e.what();
        std::cout << error << std::endl;
    }
}
 
void Bureaucrat::signForm(Form form)
{
    if (form.getIsSigned() == true)
        std::cout << _name << " signed " << form.getName() << std::endl;
    else if (form.getIsSigned() == false)
        std::cout << _name << " couldn't sign because bureaucrat grade is " << _grade <<". To be able to sign, bureaucrat's grade has to be higher (meaning lower in a math point of vue) than " << form.getGradeToSign() << " and positive." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out << other.getName() << " bureaucrat grade " << other.getGrade();
    return out;
}

Bureaucrat::~Bureaucrat()
{

}