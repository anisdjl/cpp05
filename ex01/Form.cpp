#include "Form.hpp"

Form::Form(std::string name, int gradetosign, int gradetoexec) : _name(name), _gradeToSign(gradeCheck(gradetosign)), _gradeToExec(gradeCheck(gradetoexec))
{
	_signed = false;	
}

Form::~Form(void)
{

}

Form::Form(const Form &form) : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec)
{
	_signed = false;
}

Form	&Form::operator=(const Form &form)
{
	(void)form;
	// cannot use this due to the const of the attributes
	return (*this);
}

std::string Form::getName(void) const
{
	return (_name);
}

int	Form::getExecgrade(void) const
{
	return (_gradeToExec);
}

int	Form::getSigngrade(void) const
{
	return (_gradeToSign);
}

bool	Form::formState(void) const
{
	return (_signed);
}

int	Form::gradeCheck(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException(grade);
	else if (grade > 150)
		throw Form::GradeTooLowException(grade);
	else
		return (grade);
}

void	Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException(bureau.getGrade());
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form name: " << form.getName() << " | Grade to sign: " << form.getSigngrade() << " | Grade to execute: " << form.getExecgrade() << " | Signed: " << form.formState() << "\n";
	return (out);
}

// ------------- exception ------------- //

Form::GradeTooHighException::GradeTooHighException(int grade)
{
	_error = "The grade " + std::to_string(grade) + " is too high\n";
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
	return (_error.c_str());
}

Form::GradeTooLowException::GradeTooLowException(int grade)
{
	_error = "The grade " + std::to_string(grade) + " is too low\n";
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{

}

const char* Form::GradeTooLowException::what() const throw()
{
	return (_error.c_str());
}
