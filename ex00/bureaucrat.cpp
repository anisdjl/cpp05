#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade > 150 || grade < 1)
		throw ;
	_grade = grade;
	_name = name;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor's called|n";
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau)
{

}
