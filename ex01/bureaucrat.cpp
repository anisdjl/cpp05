#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException(name, grade);
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException(name, grade);
	_grade = grade;
	_name = name;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureau)
{
	_grade = bureau.getGrade();
	_name = bureau.getName();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureau)
{
	if (this != &bureau)
	{
		_grade = bureau.getGrade();
		_name = bureau.getName();
	}
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException(_name, _grade);
	_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException(_name, _grade);
	_grade += 1;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau)
{
	out << bureau.getName() + ", bureaucrat garde " + std::to_string(bureau.getGrade()) + "\n";

	return (out);
}



Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name, int garde)
{
	_error = "The garde " + std::to_string(garde) + " is too high to create the bureaucrat " + name + '\n';
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_error.c_str());
}


Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name, int garde)
{
	_error = "The garde " + std::to_string(garde) + " is too low to create the bureaucrat " + name + '\n';
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_error.c_str());
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what();
	}
}