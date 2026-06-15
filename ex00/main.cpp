#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Anis("Anis", 1);
	try
	{
		//Bureaucrat Anis("Anis", 0);
		Bureaucrat Evan("Evan", -3223);
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