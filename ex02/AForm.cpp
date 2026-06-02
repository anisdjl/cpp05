#include "AForm.hpp"

AForm::AForm(std::string name, int gradetosign, int gradetoexec) : _name(name), _gradeToSign(gradeCheck(gradetosign)), _gradeToExec(gradeCheck(gradetoexec))
{
	_signed = false;	
}

AForm::~AForm(void)
{

}

AForm::AForm(const AForm &form) : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec)
{
	_signed = false;
}

AForm	&AForm::operator=(const AForm &form)
{
	(void)form;
	// cannot use this due to the const of the attributes
	return (*this);
}

void	AForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw AForm::GradeTooLowException(bureau.getGrade());
}

std::string AForm::getName(void) const
{
	return (_name);
}

int	AForm::getExecgrade(void) const
{
	return (_gradeToExec);
}

int	AForm::getSigngrade(void) const
{
	return (_gradeToSign);
}

bool	AForm::formState(void) const
{
	return (_signed);
}

int	AForm::gradeCheck(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException(grade);
	else if (grade > 150)
		throw AForm::GradeTooLowException(grade);
	else
		return (grade);
}