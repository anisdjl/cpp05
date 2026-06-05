#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern new_intern = Intern();
	Bureaucrat Loulou = Bureaucrat("Loulou", 1);
	AForm *form_1 = new_intern.makeForm("Shruberry Creation", "Anis");
	Loulou.signForm(*form_1);
	Loulou.executeForm(*form_1);
	delete form_1;

	return (0);
}
