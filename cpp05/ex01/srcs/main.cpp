#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main (void)
{
    Bureaucrat Test1;
    Bureaucrat Test2(Test1);
    std::cout << Test1.getName() << std::endl;
    std::cout << Test2.getName() << std::endl;
    std::cout << Test1.getGrade() << std::endl;
    std::cout << Test2.getGrade() << std::endl;
    Test1.incrementGrade();
    std::cout << Test1 << std::endl;

    Form test3;
    Form test4(test3);
    test3.beSigned(Test1);
	Test1.signForm(test3);
    std::cout << test3 << std::endl;
    return 0;
}
