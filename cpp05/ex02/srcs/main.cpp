#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Exceptions.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main (void)
{
	Bureaucrat jean;
	Bureaucrat jean_bis(jean);
	std::cout << jean << std::endl;
	jean.incrementGrade();
	std::cout << jean << std::endl;


	// //SHRUBBERY CREATION FORM 
	std::cout << "\033[33mSHRUBBERRY FORM\033[0m" << std::endl;
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery << std::endl;
	jean.signForm(shrubbery);
	std::cout << shrubbery << std::endl;
	shrubbery.execute(jean);
	std::cout << std::endl;
	
	// ROBTOMY REQUEST FORM 
	std::cout << "\033[33mROBTOMY REQUEST FORM\033[0m" << std::endl;
	RobotomyRequestForm request("Robot");
	std::cout << request << std::endl;
	try
	{
		jean.signForm(request);
		std::cout << request << std::endl;
		request.execute(jean);
	}

	catch (const FormNotSignedException& e)
	{
        std::cerr << e.what() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Autre exception attrapée : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	//PRESIDENTIAL PARDON FORM
	std::cout << "\033[33mPRESIDENTIAL PARDON FORM\033[0m" << std::endl;
	PresidentialPardonForm pardon("Mr Smith ");
	std::cout << pardon << std::endl;
	try
	{
		jean.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(jean);
	}
	catch (const FormNotSignedException& e)
	{
        std::cerr << e.what() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Autre exception attrapée : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	//TESTER EXECUTE FORM
	std::cout << "\033[33mEXECUTE FORM\033[0m" << std::endl;
	jean_bis.executeForm(shrubbery);
	jean_bis.executeForm(pardon);
	jean_bis.executeForm(request);

	return 0;
}
