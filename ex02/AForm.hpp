#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;

	public:
		void		beSigned(const Bureaucrat &bureau);
		AForm(std::string name, int gradetosign, int gradetoexec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();
		std::string	getName(void) const;
		int			getExecgrade(void) const;
		int			getSigngrade(void) const;
		bool		formState(void) const;
		int	AForm::gradeCheck(int grade);

		class GradeTooHighException : public std::exception
		{
			private:
				std::string	_error;
			public:
				GradeTooHighException(int grade);
				~GradeTooHighException(void) throw();
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string	_error;
			public:
				GradeTooLowException(int grade);
				~GradeTooLowException(void) throw();
				const char *what() const throw();
		};
};

#endif