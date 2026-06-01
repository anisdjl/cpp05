#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Anis("Anis", 1);
	try
	{
		Bureaucrat Anis("Anis", 1);
		Bureaucrat Evan("Evan", 1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << Anis;
	return (0);
}