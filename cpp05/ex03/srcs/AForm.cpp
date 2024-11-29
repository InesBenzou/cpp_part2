#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Exceptions.hpp"

AForm::AForm() : _name("Form_Name"),  _isSigned(false), _gradeToSign(15), _gradeToExecute(10) {}

AForm::AForm(const AForm& other) :  _name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm &AForm::operator=(const AForm& other) 
{
	if (this != &other)
    	_isSigned = other._isSigned;
    return *this;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

void AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

std::string AForm::getName() const
{
    return _name;
}


int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat b)
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

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Form Name: " << form.getName() << "\n"
		<< "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
		<< "Grade to Sign: " << form.getGradeToSign() << "\n"
		<< "Grade to Execute: " << form.getGradeToExecute();
	return out;
}

AForm::~AForm() {}