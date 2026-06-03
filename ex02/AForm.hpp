#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

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
		std::string		getName(void) const;
		int				getExecgrade(void) const;
		int				getSigngrade(void) const;
		bool			formState(void) const;
		int				gradeCheck(int grade);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			checkExecGrade(const Bureaucrat &execute) const;

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

		class FormNotSigned : public std::exception
		{
			private:
				std::string	_error;
			public:
				FormNotSigned(std::string name);
				~FormNotSigned(void) throw();
				const char *what() const throw();
		};
};

#endif