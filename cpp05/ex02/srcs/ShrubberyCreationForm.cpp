#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Exceptions.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()  : AForm("Shrubbery Creation",  145, 137)
{
	_target = "Default's target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	_target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm & other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade () > getGradeToExecute())
		throw GradeTooLowException();
	
	try 
	{
		std::ofstream outFile((_target + "_shrubbery").c_str());
		if (!outFile)
			throw FileCreationException();
		

		outFile << "        _-_\n";
		outFile << "	/~~   ~~\\\n";
		outFile << "  /~~		 ~~\\\n";
		outFile << " |			   |\n";
		outFile << "  \\   _-_-_-   /\n";
		outFile << "	\\_______/\n";

		outFile.close();
	}
	catch (const FileCreationException& e)
		{std::cerr << e.what() << std::endl;}
    catch (const std::exception& e)
        {std::cerr << "An unexpected error occurred: " << e.what() << std::endl;}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form)
{
	out << "ShrubberyCreationForm: " << form.getName() << "\n"
	<< "Target: " << form.getTarget();
	return out;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {}