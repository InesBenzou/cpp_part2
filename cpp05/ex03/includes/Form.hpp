#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private :
        std::string const   _name;
        bool                _isSigned; 
        const int        _gradeToSign;
        const int         _gradeToExecute;
    public :
        Form();
		Form (std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form &operator=(const Form& other);
        virtual ~Form();

        std::string getName() const;
        bool getIsSigned() const;
		void setIsSigned(bool isSigned);
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat b);

		void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& out, const Form& other);

#endif
