#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("FormName"), _gradeToSign(15), _gradeToExecute(10)
{
    _isSigned = false;
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    _isSigned = other._isSigned;
}

Form &Form::operator=(const Form& other) 
{
    _isSigned = other._isSigned;
    return *this;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}


std::string Form::getName() const
{
    return _name;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExectute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat b)
{

    try
    {
        if (b.getGrade() <= _gradeToSign && b.getGrade() >=1)
        {
            _isSigned = true;
            b.signForm(*this);
        }
        else if (b.getGrade() <1)
        {
            throw GradeTooHighException();
            b.signForm(*this);
        }
        else if (b.getGrade() > _gradeToSign || b.getGrade() > 150)
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

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    if (form.getIsSigned() == true)
        out << form.getName() << " is signed. " << std::endl;
    else if (form.getIsSigned() == false)
        out << form.getName() << " is not signed. The min grade to sign it is " << form.getGradeToSign() << " and the min grade to execute it is " << form.getGradeToExectute() << "." << std::endl;
    return out;
}

Form::~Form()
{

}