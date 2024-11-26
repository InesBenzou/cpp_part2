#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    private :
        std::string const   _name;
        bool                _isSigned; 
        const int        _gradeToSign;
        const int         _gradeToExecute;
    public :
        AForm();
		AForm (std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
		void setIsSigned(bool isSigned);
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat b);

		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif
