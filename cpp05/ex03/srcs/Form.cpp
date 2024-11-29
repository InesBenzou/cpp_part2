#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Exceptions.hpp"

Form::Form() : _name("Form_Name"),  _isSigned(false), _gradeToSign(15), _gradeToExecute(10) {}

Form::Form(const Form& other) :  _name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form &Form::operator=(const Form& other) 
{
	if (this != &other)
    	_isSigned = other._isSigned;
    return *this;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

void Form::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

std::string Form::getName() const
{
    return _name;
}


int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat b)
{
    try
    {
        if (b.getGrade() <= _gradeToSign)
        {
            _isSigned = true;
            b.signForm(*this);
        }
        else if (b.getGrade() > _gradeToSign)
        {
            throw GradeTooLowException();
            b.signForm(*this);
        }
    }
    catch(GradeTooHighException& e)
    {
        std::string error;
        error = e.what();
        std::cout << error << std::endl;
    }
    catch(GradeTooLowException& e)
    {
        std::string error;
        error = e.what();
        std::cout << error << std::endl;
    }
}

void Form::execute(Bureaucrat const& bureaucrat) const
{
        std::cout << "Form executed by " << bureaucrat.getName() << std::endl;

}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form Name: " << form.getName() << "\n"
		<< "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
		<< "Grade to Sign: " << form.getGradeToSign() << "\n"
		<< "Grade to Execute: " << form.getGradeToExecute();
	return out;
}

Form::~Form() {}