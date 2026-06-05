#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
    std::cout << "Intern assignment operator called" << std::endl;
    if (this != &src) {
       
    }
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string tab[] = 
	{
		"Shruberry Creation",
		"Presidential Pardon",
		"Robotomy Request"
	};

	AForm * (Intern::*ptr[]) (std::string) = 
	{
		&Intern::_makePresidential,
		&Intern::_makeShrubbery,
		&Intern::_makeRobotomy
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == tab[i])
		{
			std::cout << "Intern creates the form " << name << std::endl;
			return (this->*ptr[i])(target);
		}
	}
	std::cout << "The name " << name << " doesn't match any form, try with a correct name\n";
	return (NULL);
}

AForm *Intern::_makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::_makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::_makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
