#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"
#include <string>
#include <iostream>

class Intern 
{
    public :
		Intern();
	// Intern(const Intern& other);
	// Intern operator=(const Intern& other);
		Form *makeForm(const std::string formName, const std::string target);
		~Intern();
};

std::ostream& operator<<(std::ostream& out, const Intern& other);

#endif