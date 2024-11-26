#include "../includes/Bureaucrat.hpp"

int main (void)
{
    Bureaucrat Test1;
    Bureaucrat Test2(Test1);
    std::cout << Test1.getName() << std::endl;
    std::cout << Test2.getName() << std::endl;
    std::cout << Test1.getGrade() << std::endl;
    std::cout << Test2.getGrade() << std::endl;
    Test1.decrementGrade();
	Test1.incrementGrade();
    std::cout << Test1 << std::endl;
    return 0;
}