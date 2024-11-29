#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <string>
#include <iostream>

class Intern 
{
    Inter();
   // Intern(const Intern& other);
   // Intern operator=(const Intern& other);
    AForm makeForm(const std::string formName, const std::string target);
	~Intern();
}

std::ostream& operator<<(std::ostream& out, const Intern& other);
