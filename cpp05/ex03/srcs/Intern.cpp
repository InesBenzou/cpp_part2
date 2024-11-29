#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"


Intern::Intern()
{
    std::cout << "Intern's Creation" << std::endl;
}

// static functions for makeForm
static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}


Form *Intern::makeForm(const std::string formName, const std::string target)
{
    Form *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot,&makeShrubbery };
    std::string forms[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};

    for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return (all_forms[i](target));
		}
	}

	std::cout << "\033[33mIntern can not create a form called " << formName << "\033[0m" << std::endl;
	return (NULL);
}

Intern::~Intern()
{
	std::cout << "Intern's Destruction" << std::endl;
}