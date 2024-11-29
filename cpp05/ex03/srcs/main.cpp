#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Exceptions.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main (void)
{
	Bureaucrat default_name;
	Bureaucrat default_name_bis(default_name);
	std::cout << default_name << std::endl;
	default_name.incrementGrade();
	std::cout << default_name << std::endl;


	// //SHRUBBERY CREATION FORM 
	std::cout << "\033[33mSHRUBBERRY FORM\033[0m" << std::endl;
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery << std::endl;
	default_name.signForm(shrubbery);
	std::cout << shrubbery << std::endl;
	shrubbery.execute(default_name);
	std::cout << std::endl;
	
	// ROBTOMY REQUEST FORM 
	std::cout << "\033[33mROBTOMY REQUEST FORM\033[0m" << std::endl;
	RobotomyRequestForm request("Robot");
	std::cout << request << std::endl;
	try
	{
		default_name.signForm(request);
		std::cout << request << std::endl;
		request.execute(default_name);
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
		default_name.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(default_name);
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
	default_name_bis.executeForm(shrubbery);
	default_name_bis.executeForm(pardon);
	default_name_bis.executeForm(request);
	std::cout << std::endl;

	//INTERN 
	std::cout << "\033[33mINTERN\033[0m" << std::endl;

	Intern someRandomIntern;
	Form *rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	default_name.executeForm(*rrf);
	delete rrf;
	return 0;
}
