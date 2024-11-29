#ifndef ROBOTO_MY_REQUEST_HPP
#define ROBOTO_MY_REQUEST_HPP
#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	private :
		std::string _target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string targert);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

#endif