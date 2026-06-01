#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void)
{
	Bureaucrat	Anis("Anis", 10);
	try
	{
		Form		form_test("form_test", 12, 150);
		Anis.signForm(form_test);
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << e.what();
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << e.what();
	}
	return (0);
}